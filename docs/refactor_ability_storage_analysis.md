# Refactor: Store Ability ID on Pokémon (Analysis)

## 1. Current behavior

- **Species ability list:** `gSpeciesInfo[species].abilities[NUM_ABILITY_SLOTS]` (u16[3]) is the single source of truth per species.
- **Per‑Pokémon storage:** Only a **slot index** is stored:
  - `PokemonSubstruct3.abilityNum` (2 bits → 0, 1, 2)
  - `PokemonSubstruct3.cantRandomizeAbility` (1 bit)
- **Resolving the ability:** `GetMonAbility(mon)` → `GetAbilityBySpecies(species, abilityNum, cantRandomizeAbility)` → `gSpeciesInfo[species].abilities[abilityNum]` (with randomizer logic).
- **Effect:** Changing `gSpeciesInfo` (e.g. ROM randomizer) changes what ability every existing Pokémon “has,” because the game always re-derives it from species + slot.

---

## 2. Where abilities are used

### Battle system
- **`src/battle_util.c`**  
  - `CalcPartyMonTypeEffectivenessMultiplier`: `GetMonAbility(mon)`  
  - `GetBattlerAbility`: uses `gBattleMons[battler].ability` (already resolved)  
  - Battle mon init: `gBattleMons[battler].ability = GetMonAbility(mon)`
- **`src/battle_main.c`**  
  - Party → battle: `GetMonAbility(mon)`; battle mon stores **resolved** `u16 ability`  
  - Trainer setup: matches `speciesInfo->abilities[ability]` to set slot
- **`src/battle_controllers.c`**  
  - `battleMon.abilityNum = GetMonData(..., MON_DATA_ABILITY_NUM)`  
  - `gBattleMons[battler].ability` used for UI/scripts
- **`src/battle_script_commands.c`**  
  - Resolves ability via `GetAbilityBySpecies(species, abilityNum, cantRandomizeAbility)` for battle mons  
  - Uses `gSpeciesInfo[species].abilities[GetMonData(..., MON_DATA_ABILITY_NUM)]` in at least one place
- **`src/battle_ai_*.c`**  
  - Use `GetMonAbility(mon)` or `GetAbilityBySpecies` with battle mon’s species/abilityNum

### Menus / UI
- **`src/pokemon_summary_screen.c`**  
  - `GetAbilityBySpecies(summary.species, summary.abilityNum, FALSE)` for display
- **`src/bw_summary_screen.c`**  
  - Same pattern
- **`src/ui_stat_editor.c`**  
  - `GetAbilityBySpecies(speciesID, GetMonData(..., MON_DATA_ABILITY_NUM), FALSE)` for name
- **`src/party_menu.c`**  
  - Sets/reads `MON_DATA_ABILITY_NUM` (slot) for ability capsule / slot switching

### Field / scripts / other
- **`src/pokemon.c`**  
  - `GetAbilityBySpecies`, `GetMonAbility`; `CreateBoxMon` does **not** set ability (stays 0); copy/convert use slot
- **`src/wild_encounter.c`**, **`src/overworld.c`**, **`src/field_player_avatar.c`**, **`src/event_object_movement.c`**, **`src/egg_hatch.c`**, **`src/match_call.c`**, **`src/fldeff_cut.c`**  
  - Use `GetMonAbility(&gPlayerParty[0])` or similar
- **`src/script_pokemon_util.c`**  
  - `ScriptGiveMonParameterized(..., abilityNum, ...)`; validates with `GetAbilityBySpecies(species, abilityNum, FALSE)`; sets `MON_DATA_ABILITY_NUM`
- **`src/dexnav.c`**, **`src/daycare.c`**, **`src/trade.c`**, **`src/field_specials.c`**  
  - Get/Set `MON_DATA_ABILITY_NUM` or use `GetAbilityBySpecies` / `GetMonAbility`
- **`src/battle_tower.c`**, **`src/battle_pyramid.c`**, **`src/battle_pike.c`**, **`src/battle_factory*.c`**  
  - Set slot from species ability list or rental/tower data; compare `speciesInfo->abilities[ability] == partyData[i].ability`

### Summary
- **Read path:** Almost everything goes through `GetMonAbility(mon)` or `GetAbilityBySpecies(species, abilityNum, cantRandomizeAbility)`. Battle then uses the **resolved** `gBattleMons[battler].ability` (u16).
- **Write path:** All writes are to **slot**: `SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum)` (or equivalent). No place currently stores a direct ability ID on the Pokémon struct for save/party data.

---

## 3. Structs and fields involved

### 3.1 Stored on Pokémon (save/party)

| Location | Field | Type | Role |
|----------|--------|------|------|
| **PokemonSubstruct3** (inside BoxPokemon → secure) | `abilityNum` | 2 bits | Slot index 0/1/2 |
| | `cantRandomizeAbility` | 1 bit | Randomizer flag |

- **BoxPokemon** = personality, otId, nickname, language, … + **secure** (4 × 12‑byte substructs). No extra space; substructs are fixed 12 bytes for the union.
- **Pokemon** = `struct BoxPokemon box` + status, level, mail, hp, maxHP, 6 stats. No ability field.

So today the only stored ability-related data is **slot + cantRandomize** inside the encrypted substructs.

### 3.2 Battle (runtime only)

| Location | Field | Type | Role |
|----------|--------|------|------|
| **BattlePokemon** | `abilityNum` | 2 bits | Copy of party mon’s slot |
| | `cantRandomizeAbility` | u8 | Copy from party |
| | **`ability`** | **u16** | Resolved ability ID used in battle |

Battle already uses a **resolved** `u16 ability`; the refactor only changes how that value is produced from party data (from “slot → gSpeciesInfo” to “stored ability ID, with fallback”).

### 3.3 Other save/global structures (slot only)

- **RentalMon** (global.h): `u8 abilityNum`
- **BattleTowerPokemon** (global.h): `abilityNum:1` (only 1 bit in this struct)
- **EmeraldBattleTowerRecord** / **BattleTowerEReaderTrainer**: use `BattleTowerPokemon party[]`

These are used for frontier/tower/rental; they currently store slot, not ability ID. They can stay as-is initially or be extended later (see migration).

---

## 4. Required changes (and impact)

### 4.1 Add stored ability ID

**Option A – New field on BoxPokemon (recommended)**  
- Add `u16 abilityOverride` (or `abilityId`) **after** the `secure` union in `struct BoxPokemon`.
- Semantics: `0` or `ABILITY_NONE` = “use legacy slot” (current behavior). Non-zero = use this ability ID for this Pokémon.
- **Pros:** Clear, backward compatible at read time (old saves have 0/uninitialized → treat as “use slot”).  
- **Cons:** Increases `sizeof(BoxPokemon)` and shifts everything after it in any layout that embeds BoxPokemon (e.g. party, PC storage). So:
  - Save format changes (see migration below).
  - Any `memcpy`/serialization by `sizeof(struct Pokemon)` or `sizeof(struct BoxPokemon)` must stay consistent (they will if only this one field is added and layout is otherwise unchanged).

**Option B – Replace slot in Substruct3**  
- In `PokemonSubstruct3`, replace `abilityNum:2` (+ optionally `cantRandomizeAbility:1`) with a 16‑bit ability field.
- **Cons:** Breaks existing saves (same bytes would now mean something else). No simple “0 = use slot” for old data. Not recommended unless you drop save compatibility.

**Recommendation:** Option A: add `u16 abilityOverride` to `BoxPokemon` and keep `abilityNum` (and optionally `cantRandomizeAbility`) for backward compatibility and for UI (“which slot does this correspond to?”).

### 4.2 New MON_DATA and accessors

- Add e.g. `MON_DATA_ABILITY` (or `MON_DATA_ABILITY_OVERRIDE`).
- In `GetBoxMonData` / `SetBoxMonData` (and any higher-level Get/Set that wraps them), read/write the new field from `BoxPokemon` (outside the secure union). Do **not** put it in the encrypted substructs, so you don’t break checksum/encryption.
- **GetMonAbility(mon)** (and battle code that needs the resolved ability) should become:
  - `override = GetMonData(mon, MON_DATA_ABILITY, NULL);`
  - If `override != 0 && override != ABILITY_NONE`: return `override`.
  - Else: keep current logic `GetAbilityBySpecies(species, abilityNum, cantRandomizeAbility)`.
- **SetMonData(..., MON_DATA_ABILITY, &abilityId)** should write the new field and, if you want to keep “slot” in sync for UI, optionally set `abilityNum` to the slot that matches this ability in `gSpeciesInfo[species]` (or leave slot as “best guess” / 0).

### 4.3 Who needs to change

| Area | Change |
|------|--------|
| **include/pokemon.h** | Add `u16 abilityOverride` to `BoxPokemon`; add `MON_DATA_ABILITY`; (optional) extend `BattlePokemon` comment. |
| **src/pokemon.c** | Implement Get/Set for `MON_DATA_ABILITY` (read/write `boxMon->abilityOverride`); change `GetMonAbility` to check override first; change `CreateBoxMon`/`CreateMon` to set initial ability from species (e.g. set override to `gSpeciesInfo[species].abilities[0]` or chosen slot). |
| **src/pokemon.c** (copy/convert) | When copying party → battle mon, set `dst->ability` from `GetMonAbility(src)` (already done); when creating battle mon from party, keep using `GetMonAbility` so one change in `GetMonAbility` covers battle. |
| **Battle** | No struct change for `BattlePokemon`; keep using `gBattleMons[battler].ability` (u16). Ensure it is always filled from `GetMonAbility(partyMon)` (or equivalent). So only call sites that currently call `GetAbilityBySpecies(species, abilityNum, ...)` with battle mon’s species/abilityNum need to use the party mon’s resolved ability (or keep using GetMonAbility on the party mon). |
| **Menus** | Summary/stat editor: can keep using `GetMonAbility(mon)` (which will use override when set). Ability capsule / slot switch: when changing ability, set both `MON_DATA_ABILITY` and optionally `MON_DATA_ABILITY_NUM` so UI and legacy slot stay consistent. |
| **Scripts** | `ScriptGiveMonParameterized`: accept ability **ID** (or slot); if ID, set `MON_DATA_ABILITY`; if slot, set `MON_DATA_ABILITY_NUM` and optionally set `MON_DATA_ABILITY` to `GetAbilityBySpecies(species, slot, FALSE)` so new mons are independent of future gSpeciesInfo changes. |
| **Daycare** | `InheritAbility`: currently inherits **slot**; can be changed to inherit **ability ID** (e.g. from parent’s stored ability or from `GetMonAbility`) and set `MON_DATA_ABILITY` on the egg. |
| **Randomizer** | `GetAbilityBySpecies` / randomizer: when randomizer is enabled, you can either (a) keep randomizing at read time and write the result into `MON_DATA_ABILITY` once, or (b) only randomize on creation/capture and then store that ID so re-randomizing the ROM doesn’t change existing mons. |

Impact is moderate: one new field, one new MON_DATA, central change in `GetMonAbility` and in creation/copy paths. Battle and menus mostly keep using `GetMonAbility(mon)` or the existing `gBattleMons[battler].ability`.

---

## 5. Migration path for existing save data

### 5.1 Strategy

- **New field:** `BoxPokemon.abilityOverride` (u16). On **old saves**, this region of memory was not present (or was part of the next struct). So you must not assume it’s zero without a version check.
- **Save version:** Bump a save version (e.g. in save block 2) when you add this layout change.
- **On load (old version):**
  - For every Pokémon (party + PC), do **not** read `abilityOverride` (or treat it as 0).
  - Behavior: `GetMonAbility` sees override 0 → uses current `GetAbilityBySpecies(species, abilityNum, cantRandomizeAbility)`. So old saves behave exactly as today.
- **On load (new version):**
  - Read `abilityOverride` as usual. If non-zero, use it; else derive from slot.
- **On first save after upgrade:**
  - Optionally run a **one-time migration**: for each Pokémon, `resolved = GetAbilityBySpecies(species, abilityNum, cantRandomizeAbility)`; then `SetMonData(mon, MON_DATA_ABILITY, &resolved)`. Then save. From then on, that Pokémon’s ability is fixed and no longer changes if gSpeciesInfo changes.
  - Or skip migration and only store ability ID for **new** captures/creations; old mons keep “slot” semantics until the player does something that writes an ability (e.g. ability capsule, or a future “re-sync” option).

### 5.2 Compatibility

- **Old save + new ROM:** No new field; `GetMonAbility` treats missing override as 0 and uses slot. Full backward compatibility.
- **New save + old ROM:** Old ROM doesn’t know about the new field; it will read the next 2 bytes as part of the next Pokémon or structure. So **new saves are not backward compatible** with older ROMs. Document that “save format changed in version X.”

### 5.3 Checksum / encryption

- BoxPokemon’s **secure** union (substructs) is encrypted/checksummed. The new field should be **outside** that union so you don’t invalidate existing checksums. Add `abilityOverride` after `secure` and do not include it in the substruct checksum. If your save code writes BoxPokemon as a whole, it will naturally include the new field; just ensure the save version is bumped so old loaders don’t misinterpret the layout.

---

## 6. Suggested implementation order

1. **Add field and MON_DATA**  
   - `BoxPokemon.abilityOverride` (u16).  
   - `MON_DATA_ABILITY` in enum; Get/Set in pokemon.c (non-encrypted).

2. **Centralize resolution**  
   - Change `GetMonAbility(mon)` to: if `GetMonData(mon, MON_DATA_ABILITY, NULL) != 0` return it, else `GetAbilityBySpecies(species, abilityNum, cantRandomizeAbility)`.

3. **Creation and copy**  
   - In `CreateBoxMon` / `CreateMon`, set initial ability (e.g. from slot 0 or chosen slot) into `MON_DATA_ABILITY` so new mons have an explicit ID.  
   - Where you copy party → battle mon, keep using `GetMonAbility`; no need to touch BattlePokemon layout.

4. **Places that set ability**  
   - Replace or complement `SetMonData(..., MON_DATA_ABILITY_NUM, ...)` with `SetMonData(..., MON_DATA_ABILITY, &abilityId)` where you want to fix the ability (e.g. script give mon, ability capsule, daycare inherit). Optionally keep writing `abilityNum` for UI/legacy.

5. **Save version and migration**  
   - Bump save version; on load, if version old, treat `abilityOverride` as 0. Optionally, on first save after upgrade, run migration that sets `MON_DATA_ABILITY` from current `GetAbilityBySpecies` for all mons.

6. **Tests**  
   - Battle: same ability used as before when override is 0; when override is set, that ability is used regardless of gSpeciesInfo.  
   - Summary screen, stat editor, scripts: show and set correct ability.  
   - Old save loads and behaves identically; new save uses stored ability ID where set.

This keeps battle and ability **functionality** unchanged while making Pokémon abilities independent of `gSpeciesInfo` and giving you a clear path to preserve compatibility with existing save data.
