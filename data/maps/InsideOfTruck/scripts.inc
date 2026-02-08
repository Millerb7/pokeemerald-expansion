# 1 "data/maps/InsideOfTruck/scripts.pory"

# 2 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_MapScripts::
# 3 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
# 4 "data/maps/InsideOfTruck/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
# 5 "data/maps/InsideOfTruck/scripts.pory"
	.byte 0
# 6 "data/maps/InsideOfTruck/scripts.pory"

# 7 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_OnLoad:
# 8 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
# 9 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
# 10 "data/maps/InsideOfTruck/scripts.pory"
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
# 11 "data/maps/InsideOfTruck/scripts.pory"
	end
# 12 "data/maps/InsideOfTruck/scripts.pory"

# 13 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_OnResume:
# 14 "data/maps/InsideOfTruck/scripts.pory"
	setstepcallback STEP_CB_TRUCK
# 15 "data/maps/InsideOfTruck/scripts.pory"
	end
# 16 "data/maps/InsideOfTruck/scripts.pory"

# 17 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetIntroFlags::
# 18 "data/maps/InsideOfTruck/scripts.pory"
	lockall
# 19 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 20 "data/maps/InsideOfTruck/scripts.pory"
	checkplayergender
# 21 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
# 22 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
# 23 "data/maps/InsideOfTruck/scripts.pory"
	end
# 24 "data/maps/InsideOfTruck/scripts.pory"

# 25 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetIntroFlagsMale::
# 26 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
# 27 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
# 28 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
# 29 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
# 30 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
# 31 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
# 32 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
# 33 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
# 34 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
# 35 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_SkipIntro, MSGBOX_YESNO
# 36 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
# 37 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_eq InsideOfTruck_EventScript_SkipIntroMale
# 38 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_QuickStart, MSGBOX_YESNO
# 39 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
# 40 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_eq InsideOfTruck_EventScript_QuickStartChooseMode
# 41 "data/maps/InsideOfTruck/scripts.pory"
	message InsideOfTruck_Text_ReadCarefully
# 42 "data/maps/InsideOfTruck/scripts.pory"
	waitmessage
# 43 "data/maps/InsideOfTruck/scripts.pory"
	delay 100
# 44 "data/maps/InsideOfTruck/scripts.pory"
	delay 100
# 45 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_WantToUseDefaultSettings, MSGBOX_YESNO
# 46 "data/maps/InsideOfTruck/scripts.pory"
	call_if_eq VAR_RESULT, YES, InsideOfTruck_EventScript_SetDefaultSettings
# 47 "data/maps/InsideOfTruck/scripts.pory"
	call_if_eq VAR_RESULT, YES, InsideOfTruck_EventScript_GiveStarterItems
# 48 "data/maps/InsideOfTruck/scripts.pory"
	call_if_eq VAR_RESULT, NO, InsideOfTruck_EventScript_StartSettingsMenu
# 49 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
# 50 "data/maps/InsideOfTruck/scripts.pory"
	end
# 51 "data/maps/InsideOfTruck/scripts.pory"

# 52 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_QuickStartChooseMode::
# 53 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_DefaultOrMyMode, MSGBOX_YESNO
# 54 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
# 55 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_eq InsideOfTruck_EventScript_QuickStartDefaults
# 56 "data/maps/InsideOfTruck/scripts.pory"
	call InsideOfTruck_EventScript_SetMyModeSettings
# 57 "data/maps/InsideOfTruck/scripts.pory"
	call InsideOfTruck_EventScript_GiveStarterItems
# 58 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
# 59 "data/maps/InsideOfTruck/scripts.pory"
	end
# 60 "data/maps/InsideOfTruck/scripts.pory"

# 61 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_QuickStartDefaults::
# 62 "data/maps/InsideOfTruck/scripts.pory"
	call InsideOfTruck_EventScript_SetDefaultSettings
# 63 "data/maps/InsideOfTruck/scripts.pory"
	call InsideOfTruck_EventScript_GiveStarterItems
# 64 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
# 65 "data/maps/InsideOfTruck/scripts.pory"
	end
# 66 "data/maps/InsideOfTruck/scripts.pory"

# 67 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SkipIntroMale::
# 68 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
# 69 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SkipIntroCommon
# 70 "data/maps/InsideOfTruck/scripts.pory"

# 71 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SkipIntroFemale::
# 72 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
# 73 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SkipIntroCommon
# 74 "data/maps/InsideOfTruck/scripts.pory"

# 75 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SkipIntroCommon::
# 76 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_EZ_CATCH
# 77 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_SHINY_STARTERS
# 78 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
# 79 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
# 80 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RESCUED_BIRCH
# 81 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_EASY_MODE
# 82 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_MIN_GRINDING_MODE
# 83 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOMIZER_ENABLED
# 84 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOM_ABILITIES_ENABLED
# 85 "data/maps/InsideOfTruck/scripts.pory"
	special ForceBattleStyleSetPleaseGod
# 86 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MON_RANDOM
# 87 "data/maps/InsideOfTruck/scripts.pory"
	call InsideOfTruck_EventScript_GiveStarterItems
# 88 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_SkipIntroDone, MSGBOX_DEFAULT
# 89 "data/maps/InsideOfTruck/scripts.pory"
	warpsilent MAP_NEW_BIRCHS_LAB, 6, 6
# 90 "data/maps/InsideOfTruck/scripts.pory"
	waitstate
# 91 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
# 92 "data/maps/InsideOfTruck/scripts.pory"
	end
# 93 "data/maps/InsideOfTruck/scripts.pory"

# 94 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetIntroFlagsFemale::
# 95 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 96 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
# 97 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
# 98 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 99 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
# 100 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
# 101 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 102 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
# 103 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
# 104 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_SkipIntro, MSGBOX_YESNO
# 105 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
# 106 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_eq InsideOfTruck_EventScript_SkipIntroFemale
# 107 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_QuickStart, MSGBOX_YESNO
# 108 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
# 109 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_eq InsideOfTruck_EventScript_QuickStartChooseMode
# 110 "data/maps/InsideOfTruck/scripts.pory"
	message InsideOfTruck_Text_ReadCarefully
# 111 "data/maps/InsideOfTruck/scripts.pory"
	waitmessage
# 112 "data/maps/InsideOfTruck/scripts.pory"
	delay 100
# 113 "data/maps/InsideOfTruck/scripts.pory"
	delay 100
# 114 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_WantToUseDefaultSettings, MSGBOX_YESNO
# 115 "data/maps/InsideOfTruck/scripts.pory"
	call_if_eq VAR_RESULT, YES, InsideOfTruck_EventScript_SetDefaultSettings
# 116 "data/maps/InsideOfTruck/scripts.pory"
	call_if_eq VAR_RESULT, YES, InsideOfTruck_EventScript_GiveStarterItems
# 117 "data/maps/InsideOfTruck/scripts.pory"
	call_if_eq VAR_RESULT, NO, InsideOfTruck_EventScript_StartSettingsMenu
# 118 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
# 119 "data/maps/InsideOfTruck/scripts.pory"
	end
# 120 "data/maps/InsideOfTruck/scripts.pory"

# 121 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetDefaultSettings:
# 122 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_DefaultSettingsSaved, MSGBOX_DEFAULT
# 123 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_NORMAL_MODE
# 124 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_MIN_GRINDING_MODE
# 125 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOMIZER_ENABLED
# 126 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOM_ABILITIES_ENABLED
# 127 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOM_ABILITIES_ENABLED
# 128 "data/maps/InsideOfTruck/scripts.pory"
	special ForceBattleStyleSetPleaseGod
# 129 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MAX_MON_MODE
# 130 "data/maps/InsideOfTruck/scripts.pory"
	return
# 131 "data/maps/InsideOfTruck/scripts.pory"

# 132 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_GiveStarterItems::
# 133 "data/maps/InsideOfTruck/scripts.pory"
	giveitem ITEM_TM27, 1
# 134 "data/maps/InsideOfTruck/scripts.pory"
	giveitem ITEM_ABILITY_CAPSULE, 1
# 135 "data/maps/InsideOfTruck/scripts.pory"
	return
# 136 "data/maps/InsideOfTruck/scripts.pory"

# 137 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetMyModeSettings:
# 138 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_EZ_CATCH
# 139 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_SHINY_STARTERS
# 140 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_MyModeSettingsSaved, MSGBOX_DEFAULT
# 141 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_EASY_MODE
# 142 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_MIN_GRINDING_MODE
# 143 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOMIZER_ENABLED
# 144 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOM_ABILITIES_ENABLED
# 145 "data/maps/InsideOfTruck/scripts.pory"
	special ForceBattleStyleSetPleaseGod
# 146 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MON_RANDOM
# 147 "data/maps/InsideOfTruck/scripts.pory"
	return
# 148 "data/maps/InsideOfTruck/scripts.pory"

# 149 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_MovingBox::
# 150 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
# 151 "data/maps/InsideOfTruck/scripts.pory"
	end
# 152 "data/maps/InsideOfTruck/scripts.pory"

# 153 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_BoxPrintedWithMonLogo:
# 154 "data/maps/InsideOfTruck/scripts.pory"
	.string "The box is printed with a Pokémon logo.\p"
# 155 "data/maps/InsideOfTruck/scripts.pory"
	.string "It's a Pokémon brand moving and\n"
# 156 "data/maps/InsideOfTruck/scripts.pory"
	.string "delivery service.$"
# 157 "data/maps/InsideOfTruck/scripts.pory"

# 158 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_SkipIntro:
# 159 "data/maps/InsideOfTruck/scripts.pory"
	.string "Skip entire intro?\p"
# 160 "data/maps/InsideOfTruck/scripts.pory"
	.string "Spawn at Prof. Birch's lab to choose\n"
# 161 "data/maps/InsideOfTruck/scripts.pory"
	.string "your starter. EZ Catch and Shiny\n"
# 162 "data/maps/InsideOfTruck/scripts.pory"
	.string "Starters will be enabled.$"
# 163 "data/maps/InsideOfTruck/scripts.pory"

# 164 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_SkipIntroDone:
# 165 "data/maps/InsideOfTruck/scripts.pory"
	.string "Intro skipped. EZ Catch and Shiny\n"
# 166 "data/maps/InsideOfTruck/scripts.pory"
	.string "Starters enabled. Choose your starter!$"
# 167 "data/maps/InsideOfTruck/scripts.pory"

# 168 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_QuickStart:
# 169 "data/maps/InsideOfTruck/scripts.pory"
	.string "Quick start? (Skips the intro message.)$"
# 170 "data/maps/InsideOfTruck/scripts.pory"

# 171 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_DefaultOrMyMode:
# 172 "data/maps/InsideOfTruck/scripts.pory"
	.string "Default settings (Yes) or My mode (No)?\p"
# 173 "data/maps/InsideOfTruck/scripts.pory"
	.string "My mode: Easy, Min Grinding,\n"
# 174 "data/maps/InsideOfTruck/scripts.pory"
	.string "Random Abilities, normal species.$"
# 175 "data/maps/InsideOfTruck/scripts.pory"

# 176 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_MyModeSettingsSaved:
# 177 "data/maps/InsideOfTruck/scripts.pory"
	.string "My mode settings saved.\n"
# 178 "data/maps/InsideOfTruck/scripts.pory"
	.string "Good luck!$"
# 179 "data/maps/InsideOfTruck/scripts.pory"

# 180 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_ReadCarefully:
# 181 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Please take a moment to read the\n"
# 182 "data/maps/InsideOfTruck/scripts.pory"
	.string "following carefully.$"
# 183 "data/maps/InsideOfTruck/scripts.pory"

# 184 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_WantToUseDefaultSettings:
# 185 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}Would you like to play Pokémon Emerald\n"
# 186 "data/maps/InsideOfTruck/scripts.pory"
	.string "Imperium with the default settings?\p"
# 187 "data/maps/InsideOfTruck/scripts.pory"
	.string "The default settings are as follows:\p"
# 188 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal difficulty{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} - challenging boss\n"
# 189 "data/maps/InsideOfTruck/scripts.pory"
	.string "battles with hard level caps enforced.\p"
# 190 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Minimal Grinding Mode is ON{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} - this\n"
# 191 "data/maps/InsideOfTruck/scripts.pory"
	.string "guarantees all Pokémon will have\l"
# 192 "data/maps/InsideOfTruck/scripts.pory"
	.string "perfect IVs, and EVs cannot be\l"
# 193 "data/maps/InsideOfTruck/scripts.pory"
	.string "obtained.  Boss Pokémon will not have\l"
# 194 "data/maps/InsideOfTruck/scripts.pory"
	.string "EVs either.\p"
# 195 "data/maps/InsideOfTruck/scripts.pory"
	.string "Randomizer {COLOR RED}{SHADOW LIGHT_RED}OFF{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} - no additional\n"
# 196 "data/maps/InsideOfTruck/scripts.pory"
	.string "randomization will be enabled.\p"
# 197 "data/maps/InsideOfTruck/scripts.pory"
	.string "With this information in mind:\n"
# 198 "data/maps/InsideOfTruck/scripts.pory"
	.string "Would you like to play Pokémon Emerald\l"
# 199 "data/maps/InsideOfTruck/scripts.pory"
	.string "Imperium with the default settings?$"
# 200 "data/maps/InsideOfTruck/scripts.pory"

# 201 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_DefaultSettingsSaved:
# 202 "data/maps/InsideOfTruck/scripts.pory"
	.string "Default settings saved.\n"
# 203 "data/maps/InsideOfTruck/scripts.pory"
	.string "Good luck!$"

InsideOfTruck_EventScript_StartSettingsMenu::
# 207 "data/maps/InsideOfTruck/scripts.pory"
	msgbox WhichOption
# 208 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_MIN_GRINDING_MODE, InsideOfTruck_EventScript_StartSettingsMenu_2
# 217 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_0, 0
# 218 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_4, 1
# 219 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_2, 2
# 220 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, 3
InsideOfTruck_EventScript_StartSettingsMenu_1:
# 225 "data/maps/InsideOfTruck/scripts.pory"
	dynmultistack 0, 0, TRUE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 227 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq InsideOfTruck_EventScript_StartSettingsMenu_6
InsideOfTruck_EventScript_StartSettingsMenu_5:
# 232 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq InsideOfTruck_EventScript_StartSettingsMenu_9
InsideOfTruck_EventScript_StartSettingsMenu_8:
# 237 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq InsideOfTruck_EventScript_StartSettingsMenu_12
InsideOfTruck_EventScript_StartSettingsMenu_11:
# 242 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq InsideOfTruck_EventScript_StartSettingsMenu_14
	return

InsideOfTruck_EventScript_StartSettingsMenu_2:
# 210 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_0, 0
# 211 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_1, 1
# 212 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_2, 2
# 213 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, 3
	goto InsideOfTruck_EventScript_StartSettingsMenu_1

InsideOfTruck_EventScript_StartSettingsMenu_6:
# 229 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_DifficultyOptions
	goto InsideOfTruck_EventScript_StartSettingsMenu_5

InsideOfTruck_EventScript_StartSettingsMenu_9:
# 234 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_MinGrindingMode
	goto InsideOfTruck_EventScript_StartSettingsMenu_8

InsideOfTruck_EventScript_StartSettingsMenu_12:
# 239 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_RandomzierOptions
	goto InsideOfTruck_EventScript_StartSettingsMenu_11

InsideOfTruck_EventScript_StartSettingsMenu_14:
# 244 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SaveSettingsDone
	return


InsideOfTruck_EventScript_DifficultyOptions::
# 249 "data/maps/InsideOfTruck/scripts.pory"
	msgbox WhichDifficulty
# 250 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_GAME_SETTING_DIFFICULTY_MODE
# 252 "data/maps/InsideOfTruck/scripts.pory"
	case GAME_SETTING_DIFFICULTY_NORMAL_MODE, InsideOfTruck_EventScript_DifficultyOptions_3
# 257 "data/maps/InsideOfTruck/scripts.pory"
	case GAME_SETTING_DIFFICULTY_EASY_MODE, InsideOfTruck_EventScript_DifficultyOptions_4
# 263 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_0, GAME_SETTING_DIFFICULTY_NORMAL_MODE
# 264 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_1, GAME_SETTING_DIFFICULTY_EASY_MODE
# 265 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
InsideOfTruck_EventScript_DifficultyOptions_1:
# 270 "data/maps/InsideOfTruck/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 272 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_7
InsideOfTruck_EventScript_DifficultyOptions_6:
# 277 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, GAME_SETTING_DIFFICULTY_NORMAL_MODE
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_10
InsideOfTruck_EventScript_DifficultyOptions_9:
# 297 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, GAME_SETTING_DIFFICULTY_EASY_MODE
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_12
	return

InsideOfTruck_EventScript_DifficultyOptions_3:
# 253 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_0, GAME_SETTING_DIFFICULTY_NORMAL_MODE
# 254 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_1, GAME_SETTING_DIFFICULTY_EASY_MODE
# 255 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_DifficultyOptions_1

InsideOfTruck_EventScript_DifficultyOptions_4:
# 258 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_2, GAME_SETTING_DIFFICULTY_NORMAL_MODE
# 259 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_3, GAME_SETTING_DIFFICULTY_EASY_MODE
# 260 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_DifficultyOptions_1

InsideOfTruck_EventScript_DifficultyOptions_7:
# 274 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_StartSettingsMenu
	goto InsideOfTruck_EventScript_DifficultyOptions_6

InsideOfTruck_EventScript_DifficultyOptions_10:
# 279 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_NORMAL_MODE
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_14
# 286 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalDifficultyYesNo, MSGBOX_YESNO
# 287 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_21
InsideOfTruck_EventScript_DifficultyOptions_20:
# 292 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_DifficultyOptions
	goto InsideOfTruck_EventScript_DifficultyOptions_9

InsideOfTruck_EventScript_DifficultyOptions_12:
# 299 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_EASY_MODE
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_17
# 306 "data/maps/InsideOfTruck/scripts.pory"
	msgbox EasyDifficultyYesNo, MSGBOX_YESNO
# 307 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_24
InsideOfTruck_EventScript_DifficultyOptions_23:
# 312 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_DifficultyOptions
	return

InsideOfTruck_EventScript_DifficultyOptions_14:
# 281 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalDifficultyCurrentlySelected
# 282 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_DifficultyOptions
	goto InsideOfTruck_EventScript_DifficultyOptions_9

InsideOfTruck_EventScript_DifficultyOptions_17:
# 301 "data/maps/InsideOfTruck/scripts.pory"
	msgbox EasyDifficultyCurrentlySelected
# 302 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_DifficultyOptions
	return

InsideOfTruck_EventScript_DifficultyOptions_21:
# 289 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_NORMAL_MODE
# 290 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalDifficultyEnabled
	goto InsideOfTruck_EventScript_DifficultyOptions_20

InsideOfTruck_EventScript_DifficultyOptions_24:
# 309 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_EASY_MODE
# 310 "data/maps/InsideOfTruck/scripts.pory"
	msgbox EasyDifficultyEnabled
	goto InsideOfTruck_EventScript_DifficultyOptions_23


InsideOfTruck_EventScript_MinGrindingMode::
# 318 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_MIN_GRINDING_MODE, InsideOfTruck_EventScript_MinGrindingMode_2
# 329 "data/maps/InsideOfTruck/scripts.pory"
	msgbox MinGrindingAlreadyOffYesNo, MSGBOX_YESNO
# 330 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_MinGrindingMode_7
InsideOfTruck_EventScript_MinGrindingMode_1:
# 336 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_StartSettingsMenu
	return

InsideOfTruck_EventScript_MinGrindingMode_2:
# 320 "data/maps/InsideOfTruck/scripts.pory"
	msgbox MinGrindingAlreadyOnYesNo, MSGBOX_YESNO
# 321 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_MinGrindingMode_5
	goto InsideOfTruck_EventScript_MinGrindingMode_1

InsideOfTruck_EventScript_MinGrindingMode_5:
# 323 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_MIN_GRINDING_MODE
# 324 "data/maps/InsideOfTruck/scripts.pory"
	msgbox MinGrindingDisabled
	goto InsideOfTruck_EventScript_MinGrindingMode_1

InsideOfTruck_EventScript_MinGrindingMode_7:
# 332 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_MIN_GRINDING_MODE
# 333 "data/maps/InsideOfTruck/scripts.pory"
	msgbox MinGrindingEnabled
	goto InsideOfTruck_EventScript_MinGrindingMode_1


InsideOfTruck_EventScript_RandomzierOptions::
# 342 "data/maps/InsideOfTruck/scripts.pory"
	msgbox WhichRandomizerOption
# 345 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOMIZER_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_2
# 351 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_1, 0
InsideOfTruck_EventScript_RandomzierOptions_1:
# 355 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOM_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_6
# 361 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_3, 1
InsideOfTruck_EventScript_RandomzierOptions_5:
# 365 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOM_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_10
# 379 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_6, 2
InsideOfTruck_EventScript_RandomzierOptions_9:
# 392 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
# 394 "data/maps/InsideOfTruck/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 396 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_14
InsideOfTruck_EventScript_RandomzierOptions_13:
# 402 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_20
InsideOfTruck_EventScript_RandomzierOptions_19:
# 408 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_23
InsideOfTruck_EventScript_RandomzierOptions_22:
# 433 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_25
	return

InsideOfTruck_EventScript_RandomzierOptions_2:
# 347 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_0, 0
	goto InsideOfTruck_EventScript_RandomzierOptions_1

InsideOfTruck_EventScript_RandomzierOptions_6:
# 357 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_2, 1
	goto InsideOfTruck_EventScript_RandomzierOptions_5

InsideOfTruck_EventScript_RandomzierOptions_10:
# 367 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOM_MEGA_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_16
# 373 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_5, 2
	goto InsideOfTruck_EventScript_RandomzierOptions_9

InsideOfTruck_EventScript_RandomzierOptions_14:
# 398 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_StartSettingsMenu
	goto InsideOfTruck_EventScript_RandomzierOptions_13

InsideOfTruck_EventScript_RandomzierOptions_16:
# 369 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_4, 2
	goto InsideOfTruck_EventScript_RandomzierOptions_9

InsideOfTruck_EventScript_RandomzierOptions_20:
# 404 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions
	goto InsideOfTruck_EventScript_RandomzierOptions_19

InsideOfTruck_EventScript_RandomzierOptions_23:
# 410 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOM_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_28
# 422 "data/maps/InsideOfTruck/scripts.pory"
	msgbox RandomAbilitiesAlreadyOffYesNo, MSGBOX_YESNO
# 423 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_36
InsideOfTruck_EventScript_RandomzierOptions_27:
# 429 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_RandomzierOptions
	goto InsideOfTruck_EventScript_RandomzierOptions_22

InsideOfTruck_EventScript_RandomzierOptions_25:
# 435 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_unset FLAG_RANDOM_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_32
InsideOfTruck_EventScript_RandomzierOptions_31:
# 441 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOM_MEGA_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_39
# 452 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_RandomzierOptions_Text_10, MSGBOX_YESNO
# 453 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_44
InsideOfTruck_EventScript_RandomzierOptions_38:
# 459 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_RandomzierOptions
	return

InsideOfTruck_EventScript_RandomzierOptions_28:
# 412 "data/maps/InsideOfTruck/scripts.pory"
	msgbox RandomAbilitiesAlreadyOnYesNo, MSGBOX_YESNO
# 413 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_34
	goto InsideOfTruck_EventScript_RandomzierOptions_27

InsideOfTruck_EventScript_RandomzierOptions_32:
# 437 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_RandomzierOptions_Text_7
# 438 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_RandomzierOptions
	goto InsideOfTruck_EventScript_RandomzierOptions_31

InsideOfTruck_EventScript_RandomzierOptions_34:
# 415 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOM_ABILITIES_ENABLED
# 416 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOM_MEGA_ABILITIES_ENABLED
# 417 "data/maps/InsideOfTruck/scripts.pory"
	msgbox RandomAbilitiesDisabled
	goto InsideOfTruck_EventScript_RandomzierOptions_27

InsideOfTruck_EventScript_RandomzierOptions_36:
# 425 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOM_ABILITIES_ENABLED
# 426 "data/maps/InsideOfTruck/scripts.pory"
	msgbox RandomAbilitiesEnabled
	goto InsideOfTruck_EventScript_RandomzierOptions_27

InsideOfTruck_EventScript_RandomzierOptions_39:
# 443 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_RandomzierOptions_Text_8, MSGBOX_YESNO
# 444 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_42
	goto InsideOfTruck_EventScript_RandomzierOptions_38

InsideOfTruck_EventScript_RandomzierOptions_42:
# 446 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOM_MEGA_ABILITIES_ENABLED
# 447 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_RandomzierOptions_Text_9
	goto InsideOfTruck_EventScript_RandomzierOptions_38

InsideOfTruck_EventScript_RandomzierOptions_44:
# 455 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOM_MEGA_ABILITIES_ENABLED
# 456 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_RandomzierOptions_Text_11
	goto InsideOfTruck_EventScript_RandomzierOptions_38


InsideOfTruck_EventScript_SpeciesRandomizerOptions::
# 472 "data/maps/InsideOfTruck/scripts.pory"
	msgbox WhichSpeciesRandomizerOption
# 473 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_unset FLAG_RANDOMIZER_ENABLED, InsideOfTruck_EventScript_SpeciesRandomizerOptions_2
# 483 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_RANDOMIZER_MODE
# 485 "data/maps/InsideOfTruck/scripts.pory"
	case MON_RANDOM, InsideOfTruck_EventScript_SpeciesRandomizerOptions_9
# 492 "data/maps/InsideOfTruck/scripts.pory"
	case MON_RANDOM_BST, InsideOfTruck_EventScript_SpeciesRandomizerOptions_10
# 499 "data/maps/InsideOfTruck/scripts.pory"
	case MON_RANDOM_LEGEND_AWARE, InsideOfTruck_EventScript_SpeciesRandomizerOptions_11
# 506 "data/maps/InsideOfTruck/scripts.pory"
	case MAX_MON_MODE, InsideOfTruck_EventScript_SpeciesRandomizerOptions_12
InsideOfTruck_EventScript_SpeciesRandomizerOptions_12:
# 508 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_0, MAX_MON_MODE
# 509 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_1, MON_RANDOM
# 510 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_2, MON_RANDOM_BST
# 511 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_3, MON_RANDOM_LEGEND_AWARE
# 512 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
InsideOfTruck_EventScript_SpeciesRandomizerOptions_1:
# 520 "data/maps/InsideOfTruck/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 522 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_6
InsideOfTruck_EventScript_SpeciesRandomizerOptions_5:
# 528 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MAX_MON_MODE
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_14
InsideOfTruck_EventScript_SpeciesRandomizerOptions_13:
# 545 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_RANDOM
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_17
InsideOfTruck_EventScript_SpeciesRandomizerOptions_16:
# 570 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_RANDOM_BST
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_23
InsideOfTruck_EventScript_SpeciesRandomizerOptions_22:
# 595 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_RANDOM_LEGEND_AWARE
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_32
	return

InsideOfTruck_EventScript_SpeciesRandomizerOptions_2:
# 475 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_0, MAX_MON_MODE
# 476 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_1, MON_RANDOM
# 477 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_2, MON_RANDOM_BST
# 478 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_3, MON_RANDOM_LEGEND_AWARE
# 479 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_1

InsideOfTruck_EventScript_SpeciesRandomizerOptions_6:
# 524 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_RandomzierOptions
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_5

InsideOfTruck_EventScript_SpeciesRandomizerOptions_9:
# 486 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_4, MAX_MON_MODE
# 487 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_5, MON_RANDOM
# 488 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_2, MON_RANDOM_BST
# 489 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_3, MON_RANDOM_LEGEND_AWARE
# 490 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_1

InsideOfTruck_EventScript_SpeciesRandomizerOptions_10:
# 493 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_4, MAX_MON_MODE
# 494 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_1, MON_RANDOM
# 495 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_6, MON_RANDOM_BST
# 496 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_3, MON_RANDOM_LEGEND_AWARE
# 497 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_1

InsideOfTruck_EventScript_SpeciesRandomizerOptions_11:
# 500 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_4, MAX_MON_MODE
# 501 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_1, MON_RANDOM
# 502 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_2, MON_RANDOM_BST
# 503 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_7, MON_RANDOM_LEGEND_AWARE
# 504 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_1

InsideOfTruck_EventScript_SpeciesRandomizerOptions_14:
# 530 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_unset FLAG_RANDOMIZER_ENABLED, InsideOfTruck_EventScript_SpeciesRandomizerOptions_20
InsideOfTruck_EventScript_SpeciesRandomizerOptions_19:
# 535 "data/maps/InsideOfTruck/scripts.pory"
	msgbox SpeciesRandomizerTurnOffYesNo, MSGBOX_YESNO
# 536 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_30
InsideOfTruck_EventScript_SpeciesRandomizerOptions_29:
# 542 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_13

InsideOfTruck_EventScript_SpeciesRandomizerOptions_17:
# 547 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RANDOMIZER_MODE, MON_RANDOM
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_26
# 559 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalSpeciesRandomizerAlreadyOffYesNo, MSGBOX_YESNO
# 560 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_40
InsideOfTruck_EventScript_SpeciesRandomizerOptions_25:
# 567 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_16

InsideOfTruck_EventScript_SpeciesRandomizerOptions_20:
# 532 "data/maps/InsideOfTruck/scripts.pory"
	msgbox SpeciesRandomizerAlreadyOff
# 533 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_19

InsideOfTruck_EventScript_SpeciesRandomizerOptions_23:
# 572 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RANDOMIZER_MODE, MON_RANDOM_BST
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_35
# 584 "data/maps/InsideOfTruck/scripts.pory"
	msgbox ScaledSpeciesRandomizerAlreadyOffYesNo, MSGBOX_YESNO
# 585 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_48
InsideOfTruck_EventScript_SpeciesRandomizerOptions_34:
# 592 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_22

InsideOfTruck_EventScript_SpeciesRandomizerOptions_26:
# 549 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalSpeciesRandomizerAlreadyOnYesNo, MSGBOX_YESNO
# 550 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_38
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_25

InsideOfTruck_EventScript_SpeciesRandomizerOptions_30:
# 538 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOMIZER_ENABLED
# 539 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MAX_MON_MODE
# 540 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalSpeciesRandomizerDisabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_29

InsideOfTruck_EventScript_SpeciesRandomizerOptions_32:
# 597 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RANDOMIZER_MODE, MON_RANDOM_LEGEND_AWARE
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_43
# 609 "data/maps/InsideOfTruck/scripts.pory"
	msgbox LegendsAwareRandomizerAlreadyOffYesNo, MSGBOX_YESNO
# 610 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_52
InsideOfTruck_EventScript_SpeciesRandomizerOptions_42:
# 617 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions
	return

InsideOfTruck_EventScript_SpeciesRandomizerOptions_35:
# 574 "data/maps/InsideOfTruck/scripts.pory"
	msgbox ScaledSpeciesRandomizerAlreadyOnYesNo, MSGBOX_YESNO
# 575 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_46
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_34

InsideOfTruck_EventScript_SpeciesRandomizerOptions_38:
# 552 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOMIZER_ENABLED
# 553 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MAX_MON_MODE
# 554 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalSpeciesRandomizerDisabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_25

InsideOfTruck_EventScript_SpeciesRandomizerOptions_40:
# 562 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOMIZER_ENABLED
# 563 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MON_RANDOM
# 564 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalSpeciesRandomizerEnabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_25

InsideOfTruck_EventScript_SpeciesRandomizerOptions_43:
# 599 "data/maps/InsideOfTruck/scripts.pory"
	msgbox LegendsAwareRandomizerAlreadyOnYesNo, MSGBOX_YESNO
# 600 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_50
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_42

InsideOfTruck_EventScript_SpeciesRandomizerOptions_46:
# 577 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOMIZER_ENABLED
# 578 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MAX_MON_MODE
# 579 "data/maps/InsideOfTruck/scripts.pory"
	msgbox ScaledSpeciesRandomizerDisabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_34

InsideOfTruck_EventScript_SpeciesRandomizerOptions_48:
# 587 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOMIZER_ENABLED
# 588 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MON_RANDOM_BST
# 589 "data/maps/InsideOfTruck/scripts.pory"
	msgbox ScaledSpeciesRandomizerEnabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_34

InsideOfTruck_EventScript_SpeciesRandomizerOptions_50:
# 602 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOMIZER_ENABLED
# 603 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MAX_MON_MODE
# 604 "data/maps/InsideOfTruck/scripts.pory"
	msgbox LegendsAwareRandomizerDisabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_42

InsideOfTruck_EventScript_SpeciesRandomizerOptions_52:
# 612 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOMIZER_ENABLED
# 613 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MON_RANDOM_LEGEND_AWARE
# 614 "data/maps/InsideOfTruck/scripts.pory"
	msgbox LegendsAwareRandomizerEnabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_42


InsideOfTruck_EventScript_SaveSettingsDone::
# 624 "data/maps/InsideOfTruck/scripts.pory"
	special ForceBattleStyleSetPleaseGod
# 625 "data/maps/InsideOfTruck/scripts.pory"
	msgbox CustomSettingsSaved
# 626 "data/maps/InsideOfTruck/scripts.pory"
	call InsideOfTruck_EventScript_GiveStarterItems
# 627 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_StartSettingsMenu_Text_0:
# 210 "data/maps/InsideOfTruck/scripts.pory"
	.string "Difficulty Options$"

InsideOfTruck_EventScript_StartSettingsMenu_Text_1:
# 211 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Minimal Grinding Mode$"

InsideOfTruck_EventScript_StartSettingsMenu_Text_2:
# 212 "data/maps/InsideOfTruck/scripts.pory"
	.string "Randomizer Options$"

InsideOfTruck_EventScript_StartSettingsMenu_Text_3:
# 213 "data/maps/InsideOfTruck/scripts.pory"
	.string "Done$"

InsideOfTruck_EventScript_StartSettingsMenu_Text_4:
# 218 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Minimal Grinding Mode$"

InsideOfTruck_EventScript_DifficultyOptions_Text_0:
# 253 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal$"

InsideOfTruck_EventScript_DifficultyOptions_Text_1:
# 254 "data/maps/InsideOfTruck/scripts.pory"
	.string "Easy$"

InsideOfTruck_EventScript_DifficultyOptions_Text_2:
# 258 "data/maps/InsideOfTruck/scripts.pory"
	.string "Normal$"

InsideOfTruck_EventScript_DifficultyOptions_Text_3:
# 259 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Easy$"

InsideOfTruck_EventScript_RandomzierOptions_Text_0:
# 347 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Species$"

InsideOfTruck_EventScript_RandomzierOptions_Text_1:
# 351 "data/maps/InsideOfTruck/scripts.pory"
	.string "Species$"

InsideOfTruck_EventScript_RandomzierOptions_Text_2:
# 357 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ability$"

InsideOfTruck_EventScript_RandomzierOptions_Text_3:
# 361 "data/maps/InsideOfTruck/scripts.pory"
	.string "Ability$"

InsideOfTruck_EventScript_RandomzierOptions_Text_4:
# 369 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Mega Ability$"

InsideOfTruck_EventScript_RandomzierOptions_Text_5:
# 373 "data/maps/InsideOfTruck/scripts.pory"
	.string "Mega Ability$"

InsideOfTruck_EventScript_RandomzierOptions_Text_6:
# 379 "data/maps/InsideOfTruck/scripts.pory"
	.string "Mega Ability (requires Ability)$"

InsideOfTruck_EventScript_RandomzierOptions_Text_7:
# 437 "data/maps/InsideOfTruck/scripts.pory"
	.string "Turn on Ability randomizer first.$"

InsideOfTruck_EventScript_RandomzierOptions_Text_8:
# 443 "data/maps/InsideOfTruck/scripts.pory"
	.string "Randomize Mega Abilities is currently ON.\nTurn it OFF?$"

InsideOfTruck_EventScript_RandomzierOptions_Text_9:
# 447 "data/maps/InsideOfTruck/scripts.pory"
	.string "Mega Abilities will no longer be randomized.$"

InsideOfTruck_EventScript_RandomzierOptions_Text_10:
# 452 "data/maps/InsideOfTruck/scripts.pory"
	.string "Randomize Mega Abilities is currently OFF.\nTurn it ON?$"

InsideOfTruck_EventScript_RandomzierOptions_Text_11:
# 456 "data/maps/InsideOfTruck/scripts.pory"
	.string "Mega Abilities will now be randomized.$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_0:
# 475 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Off (normal species)$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_1:
# 476 "data/maps/InsideOfTruck/scripts.pory"
	.string "Normal species$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_2:
# 477 "data/maps/InsideOfTruck/scripts.pory"
	.string "Scaled species$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_3:
# 478 "data/maps/InsideOfTruck/scripts.pory"
	.string "Legendary-aware species$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_4:
# 486 "data/maps/InsideOfTruck/scripts.pory"
	.string "Off (normal species)$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_5:
# 487 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal species$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_6:
# 495 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Scaled species$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_7:
# 503 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Legendary-aware species$"

WhichOption::
# 632 "data/maps/InsideOfTruck/scripts.pory"
	.string "Which option would you like\n"
	.string "to customize?$"

WhichDifficulty::
# 638 "data/maps/InsideOfTruck/scripts.pory"
	.string "Which difficulty mode would you\n"
	.string "like to play on?$"

WhichRandomizerOption::
# 644 "data/maps/InsideOfTruck/scripts.pory"
	.string "Which randomizer option would you\n"
	.string "like to customize?$"

WhichSpeciesRandomizerOption::
# 650 "data/maps/InsideOfTruck/scripts.pory"
	.string "Which Species Randomizer option would\n"
	.string "you like to customize?$"

NormalDifficultyCurrentlySelected::
# 656 "data/maps/InsideOfTruck/scripts.pory"
	.string "This is the recommended difficulty\n"
	.string "mode and is what this game is primarily\l"
	.string "balanced around.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal Mode{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} has challenging boss\n"
	.string "battles with hard level caps enforced.\p"
	.string "The player cannot access the Bag\n"
	.string "during trainer battles, and the battle\l"
	.string "style is forced to Set.\p"
	.string "You currently have {COLOR GREEN}{SHADOW LIGHT_GREEN}Normal Mode{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} enabled.\n"
	.string "Please select a different difficulty\l"
	.string "mode if you wish to change it.$"

EasyDifficultyCurrentlySelected::
# 671 "data/maps/InsideOfTruck/scripts.pory"
	.string "There are still level caps in {COLOR GREEN}{SHADOW LIGHT_GREEN}Easy Mode,{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\n"
	.string "however, the Boss Pokémon will be 2\l"
	.string "levels lower than in Normal.\l"
	.string "Boss teams are otherwise unchanged.\p"
	.string "The player is allowed to access the\n"
	.string "Bag during any battle.\p"
	.string "Additionally, the player can change the\n"
	.string "battle style from Set to Shift.\p"
	.string "This will still be more difficult than a\n"
	.string "vanilla Pokémon game.\p"
	.string "You currently have {COLOR GREEN}{SHADOW LIGHT_GREEN}Easy Mode{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} enabled.\n"
	.string "Please select a different difficulty\l"
	.string "mode if you wish to change it.$"

NormalDifficultyYesNo::
# 688 "data/maps/InsideOfTruck/scripts.pory"
	.string "This is the recommended difficulty\n"
	.string "mode and is what this game is primarily\l"
	.string "balanced around.\p"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal Mode{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} has challenging boss\n"
	.string "battles with hard level caps enforced.\p"
	.string "The player cannot access the Bag\n"
	.string "during trainer battles, and the battle\l"
	.string "style is forced to Set.\p"
	.string "Do you want to turn on\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal Mode?$"

EasyDifficultyYesNo::
# 702 "data/maps/InsideOfTruck/scripts.pory"
	.string "There are still level caps in {COLOR GREEN}{SHADOW LIGHT_GREEN}Easy Mode,{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\n"
	.string "however, the Boss Pokémon will be 2\l"
	.string "levels lower than in Normal.\l"
	.string "Boss teams are otherwise unchanged.\p"
	.string "The player is allowed to access the\n"
	.string "Bag during any battle.\p"
	.string "Additionally, the player can change the\n"
	.string "battle style from Set to Shift.\p"
	.string "This will still be more difficult than a\n"
	.string "vanilla Pokémon game.\p"
	.string "Do you want to turn on\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Easy Mode?$"

NormalDifficultyEnabled::
# 718 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal Mode{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} enabled.$"

EasyDifficultyEnabled::
# 723 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Easy Mode{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} enabled.$"

MinGrindingAlreadyOnYesNo::
# 728 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Minimal Grinding Mode{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} guarantees all\n"
	.string "Pokémon to have perfect IVs,\l"
	.string "and EVs cannot be obtained.\l"
	.string "Boss Pokémon will not have EVs either.\p"
	.string "If this mode is disabled, obtainable\n"
	.string "Pokémon will have random IVs and can be\l"
	.string "EV trained.\p"
	.string "Boss Pokémon will still have perfect\n"
	.string "IVs and will be EV trained.\p"
	.string "Do you want to turn\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Minimal Grinding Mode off?$"

MinGrindingAlreadyOffYesNo::
# 743 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Minimal Grinding Mode{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} guarantees all\n"
	.string "Pokémon to have perfect IVs,\l"
	.string "and EVs cannot be obtained.\l"
	.string "Boss Pokémon will not have EVs either.\p"
	.string "If this mode is disabled, obtainable\n"
	.string "Pokémon will have random IVs and can be\l"
	.string "EV trained.\p"
	.string "Boss Pokémon will still have perfect\n"
	.string "IVs and will be EV trained.\p"
	.string "Do you want to turn\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Minimal Grinding Mode on?$"

MinGrindingEnabled::
# 758 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Minimal Grinding Mode enabled.$"

MinGrindingDisabled::
# 763 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Minimal Grinding Mode disabled.$"

RandomAbilitiesAlreadyOnYesNo::
# 769 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ability Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes abilities\n"
	.string "for the player, but doesn't affect\l"
	.string "abilities on Boss Pokémon.\p"
	.string "Do you want to turn off the\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Ability Randomizer?$"

RandomAbilitiesAlreadyOffYesNo::
# 778 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ability Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes abilities\n"
	.string "for the player, but doesn't affect\l"
	.string "abilities on Boss Pokémon.\p"
	.string "Do you want to turn on the\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ability Randomizer?$"

RandomAbilitiesEnabled::
# 788 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ability Randomizer enabled.$"

RandomAbilitiesDisabled::
# 793 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Ability Randomizer disabled.$"

RandomLearnsetsAlreadyOnYesNo::
# 799 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Learnset Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes\n"
	.string "Pokémon learnsets.\p"
	.string "It does not randomize TMs or\n"
	.string "move tutors.\p"
	.string "Boss Pokémon also keep their normal\n"
	.string "movesets.\p"
	.string "Do you want to turn off the\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Learnset Randomizer?$"

RandomLearnsetsAlreadyOffYesNo::
# 811 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Learnset Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes\n"
	.string "Pokémon learnsets.\p"
	.string "It does not randomize TMs or\n"
	.string "move tutors.\p"
	.string "Boss Pokémon also keep their normal\n"
	.string "movesets.\p"
	.string "Do you want to turn on the\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Learnset Randomizer?$"

RandomLearnsetsEnabled::
# 824 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Learnset Randomizer enabled.$"

RandomLearnsetsDisabled::
# 829 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Learnset Randomizer disabled.$"

NormalSpeciesRandomizerAlreadyOnYesNo::
# 835 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Species Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes\n"
	.string "encounters, trainers, and gifts.\l"
	.string "It does not randomize boss battles.\p"
	.string "Many legendaries cannot be\n"
	.string "encountered.\p"
	.string "Do you want to turn off the\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Species Randomizer?$"

NormalSpeciesRandomizerAlreadyOffYesNo::
# 846 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Species Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes\n"
	.string "encounters, trainers, and gifts.\l"
	.string "It does not randomize boss battles.\p"
	.string "Many legendaries cannot be\n"
	.string "encountered.\p"
	.string "Do you want to turn on the\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Species Randomizer?$"

NormalSpeciesRandomizerEnabled::
# 858 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Species Randomizer enabled.$"

NormalSpeciesRandomizerDisabled::
# 863 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Species Randomizer disabled.$"

SpeciesRandomizerAlreadyOff::
# 868 "data/maps/InsideOfTruck/scripts.pory"
	.string "Species Randomizer is already off.\n"
	.string "(Normal species - no randomization.)$"

SpeciesRandomizerTurnOffYesNo::
# 874 "data/maps/InsideOfTruck/scripts.pory"
	.string "Turn off Species Randomizer?\n"
	.string "(Back to normal species.)$"

ScaledSpeciesRandomizerAlreadyOnYesNo::
# 880 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Scaled Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} only gives\n"
	.string "reasonable Pokémon for your location\l"
	.string "in the game.\p"
	.string "This randomization is based off the\n"
	.string "base stat total of the original\l"
	.string "encounter.\l"
	.string "It does not randomize boss battles.\p"
	.string "Do you want to turn off the\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Scaled Randomizer?$"

ScaledSpeciesRandomizerAlreadyOffYesNo::
# 893 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Scaled Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} only gives\n"
	.string "reasonable Pokémon for your location\l"
	.string "in the game.\p"
	.string "This randomization is based off the\n"
	.string "base stat total of the original\l"
	.string "encounter.\l"
	.string "It does not randomize boss battles.\p"
	.string "Do you want to turn on the\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Scaled Randomizer?$"

ScaledSpeciesRandomizerEnabled::
# 907 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Scaled Randomizer enabled.$"

ScaledSpeciesRandomizerDisabled::
# 912 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Scaled Randomizer disabled.$"

LegendsAwareRandomizerAlreadyOnYesNo::
# 917 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Legendary-aware Species Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} is\n"
	.string "the same thing as the Species\l"
	.string "Randomizer, with the only difference\l"
	.string "being that legendary Pokémon will be\l"
	.string "guaranteed to be randomized into\l"
	.string "legendary Pokémon.\p"
	.string "Do you want to turn off the\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Legendary-aware Species Randomizer?$"

LegendsAwareRandomizerAlreadyOffYesNo::
# 929 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Legendary-aware Species Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} is\n"
	.string "the same thing as the Species\l"
	.string "Randomizer, with the only difference\l"
	.string "being that legendary Pokémon will be\l"
	.string "guaranteed to be randomized into\l"
	.string "legendary Pokémon.\p"
	.string "Do you want to turn on the\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Legendary-aware Species Randomizer?$"

LegendsAwareRandomizerEnabled::
# 942 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Legendary-aware Species Randomizer\n"
	.string "enabled.$"

LegendsAwareRandomizerDisabled::
# 948 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Legendary-aware Species Randomizer\n"
	.string "disabled.$"

CustomSettingsSaved::
# 955 "data/maps/InsideOfTruck/scripts.pory"
	.string "Custom settings saved.\n"
	.string "Good luck!$"
