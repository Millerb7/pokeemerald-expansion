#!/usr/bin/env python3
import re
from pathlib import Path

FILLERS = ["ABILITY_TRUANT", "ABILITY_ILLUMINATE", "ABILITY_RUN_AWAY"]

FORCED_SPECIES = {
    "SPECIES_WISHIWASHI",
    "SPECIES_PALAFIN",
    "SPECIES_PALAFIN_HERO",
    "SPECIES_MINIOR",
    "SPECIES_MINIOR_CORE",
    "SPECIES_MIMIKYU",
    "SPECIES_MIMIKYU_BUSTED",
    "SPECIES_EISCUE",
    "SPECIES_EISCUE_NOICE",
    "SPECIES_AEGISLASH",
    "SPECIES_AEGISLASH_BLADE",
    "SPECIES_ZYGARDE",
    "SPECIES_ZYGARDE_10",
    "SPECIES_ZYGARDE_COMPLETE",
    "SPECIES_DARMANITAN",
    "SPECIES_DARMANITAN_ZEN",
    "SPECIES_DARMANITAN_GALAR",
    "SPECIES_DARMANITAN_GALAR_ZEN",
    "SPECIES_CASTFORM",
    "SPECIES_CHERRIM",
    "SPECIES_CHERRIM_SUNSHINE",
    "SPECIES_MORPEKO",
    "SPECIES_MORPEKO_HANGRY",
    "SPECIES_CRAMORANT",
    "SPECIES_CRAMORANT_GULPING",
    "SPECIES_CRAMORANT_GORGING",
    "SPECIES_ARCEUS",
    "SPECIES_ARCEUS_NORMAL",
    "SPECIES_ARCEUS_TYPELESS",
    "SPECIES_ARCEUS_FIGHTING",
    "SPECIES_ARCEUS_FLYING",
    "SPECIES_ARCEUS_POISON",
    "SPECIES_ARCEUS_GROUND",
    "SPECIES_ARCEUS_ROCK",
    "SPECIES_ARCEUS_BUG",
    "SPECIES_ARCEUS_GHOST",
    "SPECIES_ARCEUS_STEEL",
    "SPECIES_ARCEUS_FIRE",
    "SPECIES_ARCEUS_WATER",
    "SPECIES_ARCEUS_GRASS",
    "SPECIES_ARCEUS_ELECTRIC",
    "SPECIES_ARCEUS_PSYCHIC",
    "SPECIES_ARCEUS_ICE",
    "SPECIES_ARCEUS_DRAGON",
    "SPECIES_ARCEUS_DARK",
    "SPECIES_ARCEUS_FAIRY",
}

SKIP_IF_BLOCK_CONTAINS = [
    ".isMegaEvolution = TRUE",
    ".isPrimalReversion = TRUE",
    ".isUltraBurst = TRUE",
    ".isGigantamax = TRUE",
]

SKIP_SPECIES_TOKEN_PATTERNS = [
    r"_MEGA",
    r"_PRIMAL",
    r"_ULTRA",
    r"_GMAX",
]

# Find "[SPECIES_XXX] =" starts
SPECIES_HEADER_RE = re.compile(r"\[\s*(SPECIES_[A-Z0-9_]+)\s*\]\s*=\s*")

# Match abilities inside a block (multiline-safe)
ABILITIES_RE = re.compile(
    r"""
    (?P<prefix>\.abilities\s*=\s*\{\s*)
    (?P<a1>ABILITY_[A-Z0-9_]+)\s*,\s*
    (?P<a2>ABILITY_[A-Z0-9_]+)\s*,\s*
    (?P<a3>ABILITY_[A-Z0-9_]+)
    (?P<suffix>\s*\}\s*,)
    """,
    re.VERBOSE | re.DOTALL,
)

def needs_fix(a1: str, a2: str, a3: str) -> bool:
    abilities = [a1, a2, a3]
    if "ABILITY_NONE" in abilities:
        return True
    return len(set(abilities)) != 3

def make_distinct(a1: str, a2: str, a3: str) -> list[str]:
    original = [a1, a2, a3]
    kept = []
    seen = set()

    for a in original:
        if a == "ABILITY_NONE":
            continue
        if a not in seen:
            kept.append(a)
            seen.add(a)

    for f in FILLERS:
        if len(kept) >= 3:
            break
        if f not in seen:
            kept.append(f)
            seen.add(f)

    while len(kept) < 3:
        kept.append(FILLERS[-1])

    return kept[:3]

def should_skip_species(species_token: str, block_text: str) -> bool:
    if species_token in FORCED_SPECIES:
        return True
    for pat in SKIP_SPECIES_TOKEN_PATTERNS:
        if re.search(pat, species_token):
            return True
    for s in SKIP_IF_BLOCK_CONTAINS:
        if s in block_text:
            return True
    return False

def replace_abilities(block_text: str) -> tuple[str, int]:
    def repl(m: re.Match) -> str:
        a1, a2, a3 = m.group("a1"), m.group("a2"), m.group("a3")
        if not needs_fix(a1, a2, a3):
            return m.group(0)
        na1, na2, na3 = make_distinct(a1, a2, a3)
        return f"{m.group('prefix')}{na1}, {na2}, {na3}{m.group('suffix')}"

    new_block, n = ABILITIES_RE.subn(repl, block_text)
    return new_block, n

def find_matching_brace(text: str, open_brace_index: int) -> int:
    # Assumes text[open_brace_index] == '{'
    depth = 0
    i = open_brace_index
    n = len(text)

    in_str = False
    str_char = ""
    escape = False

    while i < n:
        c = text[i]

        # crude string handling so braces in strings don't confuse us
        if in_str:
            if escape:
                escape = False
            elif c == "\\":
                escape = True
            elif c == str_char:
                in_str = False
        else:
            if c == '"' or c == "'":
                in_str = True
                str_char = c
            elif c == "{":
                depth += 1
            elif c == "}":
                depth -= 1
                if depth == 0:
                    return i

        i += 1

    return -1

def process_file(path: Path) -> int:
    text = path.read_text(encoding="utf-8", errors="replace")
    out = []
    idx = 0
    touched = 0

    while True:
        m = SPECIES_HEADER_RE.search(text, idx)
        if not m:
            out.append(text[idx:])
            break

        species_token = m.group(1)
        header_start = m.start()
        out.append(text[idx:header_start])

        # find the first '{' after the header
        brace_open = text.find("{", m.end())
        if brace_open == -1:
            # weird file; just copy remainder and stop
            out.append(text[header_start:])
            break

        brace_close = find_matching_brace(text, brace_open)
        if brace_close == -1:
            # unbalanced braces; copy remainder and stop
            out.append(text[header_start:])
            break

        block = text[header_start:brace_close + 1]  # includes final "}"
        # include trailing comma if present
        j = brace_close + 1
        while j < len(text) and text[j].isspace():
            j += 1
        if j < len(text) and text[j] == ",":
            j += 1
        block_full = text[header_start:j]

        if should_skip_species(species_token, block_full):
            out.append(block_full)
        else:
            new_block, n = replace_abilities(block_full)
            touched += n
            out.append(new_block)

        idx = j

    new_text = "".join(out)
    if touched > 0 and new_text != text:
        bak = path.with_suffix(path.suffix + ".bak")
        if not bak.exists():
            bak.write_text(text, encoding="utf-8")
        path.write_text(new_text, encoding="utf-8")

    return touched

def main():
    repo_root = Path(".").resolve()
    targets = sorted(repo_root.rglob("src/data/pokemon/species_info/gen_*_families.h"))

    if not targets:
        print("No gen_*_families.h files found under:", repo_root)
        return

    files_changed = 0
    entries_touched = 0

    for p in targets:
        n = process_file(p)
        if n > 0:
            files_changed += 1
            entries_touched += n
            print(f"[changed] {p}  ({n} .abilities entries touched)")

    print(f"\nDone. Files changed: {files_changed}, total entries touched: {entries_touched}")
    print("Skipped forced species and special forms (mega/primal/ultra/gmax).")
    print("Backups written as: *.h.bak (only for files that changed)")

if __name__ == "__main__":
    main()
