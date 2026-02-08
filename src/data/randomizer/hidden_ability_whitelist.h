// Hidden Ability Whitelist - Damage Boosts, Weather, Immunities, and Broken Stuff Only
// Criteria: Must be either a significant damage boost, weather setter, immunity/absorb, or exceptionally strong

static const u16 sHiddenAbilityWhitelist[] =
{
    // === BROKEN/LEGENDARY TIER ===
    ABILITY_HUGE_POWER,
    ABILITY_PARENTAL_BOND,
    ABILITY_DELTA_STREAM,
    ABILITY_PRIMORDIAL_SEA,
    ABILITY_DESOLATE_LAND,
    ABILITY_MAGIC_GUARD,
    ABILITY_SHADOW_SHIELD, 
    ABILITY_MULTISCALE,
    ABILITY_PRISM_ARMOR,
    ABILITY_FUR_COAT,
    
    // === MAJOR DAMAGE BOOSTS ===
    ABILITY_GUTS,
    ABILITY_ADAPTABILITY,
    ABILITY_TECHNICIAN, 
    ABILITY_SHEER_FORCE, 
    ABILITY_TOUGH_CLAWS,
    ABILITY_MOXIE,
    ABILITY_BEAST_BOOST, 
    ABILITY_SOUL_HEART, 
    ABILITY_GORILLA_TACTICS,
    
    // === WEATHER SETTERS ===
    ABILITY_DROUGHT,              // Sun
    ABILITY_DRIZZLE,              // Rain
    ABILITY_SAND_STREAM,          // Sandstorm
    ABILITY_SNOW_WARNING,         // Snow/Hail
    
    // === IMMUNITIES (TYPE) ===
    ABILITY_LEVITATE,
    ABILITY_FLASH_FIRE,
    ABILITY_VOLT_ABSORB, 
    ABILITY_WATER_ABSORB, 
    ABILITY_SAP_SIPPER, 
    ABILITY_STORM_DRAIN,  
    ABILITY_LIGHTNING_ROD, 
    ABILITY_MOTOR_DRIVE,  
    ABILITY_DRY_SKIN, 
    ABILITY_THICK_FAT,
    ABILITY_WATER_BUBBLE, 
    ABILITY_FLUFFY, 
    ABILITY_HEATPROOF,
    ABILITY_WELL_BAKED_BODY,
    ABILITY_EARTH_EATER,
    ABILITY_WIND_RIDER,
    
    // === STAT BOOST ABILITIES ===
    ABILITY_SPEED_BOOST,          // +1 Speed each turn (broken)
    
    // === PARADOX ABILITIES (Stat Boosts in Weather/Terrain) ===
    ABILITY_ORICHALCUM_PULSE,     // Sun + Attack boost
    ABILITY_HADRON_ENGINE,        // Electric Terrain + SpA boost
    
    // === CUSTOM ABILITIES ===
    ABILITY_FELINE_PROWESS,
    ABILITY_SAGE_POWER,
    ABILITY_FATAL_PRECISION,
    ABILITY_FAST_START,
    ABILITY_MIND_OVER_MATTER,
    ABILITY_FORTIFY,
};

#define HIDDEN_ABILITY_WHITELIST_SIZE (NELEMS(sHiddenAbilityWhitelist))