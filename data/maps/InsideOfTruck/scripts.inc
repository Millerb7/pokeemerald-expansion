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
	message InsideOfTruck_Text_ReadCarefully
# 36 "data/maps/InsideOfTruck/scripts.pory"
	waitmessage
# 37 "data/maps/InsideOfTruck/scripts.pory"
	delay 100
# 38 "data/maps/InsideOfTruck/scripts.pory"
	delay 100
# 39 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_WantToUseDefaultSettings, MSGBOX_YESNO
# 40 "data/maps/InsideOfTruck/scripts.pory"
	call_if_eq VAR_RESULT, YES, InsideOfTruck_EventScript_SetDefaultSettings
# 41 "data/maps/InsideOfTruck/scripts.pory"
	call_if_eq VAR_RESULT, NO, InsideOfTruck_EventScript_StartSettingsMenu
# 42 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
# 43 "data/maps/InsideOfTruck/scripts.pory"
	end
# 44 "data/maps/InsideOfTruck/scripts.pory"

# 45 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetIntroFlagsFemale::
# 46 "data/maps/InsideOfTruck/scripts.pory"
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
# 47 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
# 48 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
# 49 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
# 50 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
# 51 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
# 52 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
# 53 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
# 54 "data/maps/InsideOfTruck/scripts.pory"
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
# 55 "data/maps/InsideOfTruck/scripts.pory"
	message InsideOfTruck_Text_ReadCarefully
# 56 "data/maps/InsideOfTruck/scripts.pory"
	waitmessage
# 57 "data/maps/InsideOfTruck/scripts.pory"
	delay 100
# 58 "data/maps/InsideOfTruck/scripts.pory"
	delay 100
# 59 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_WantToUseDefaultSettings, MSGBOX_YESNO
# 60 "data/maps/InsideOfTruck/scripts.pory"
	call_if_eq VAR_RESULT, YES, InsideOfTruck_EventScript_SetDefaultSettings
# 61 "data/maps/InsideOfTruck/scripts.pory"
	call_if_eq VAR_RESULT, NO, InsideOfTruck_EventScript_StartSettingsMenu
# 62 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
# 63 "data/maps/InsideOfTruck/scripts.pory"
	end
# 64 "data/maps/InsideOfTruck/scripts.pory"

# 65 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_SetDefaultSettings:
# 66 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_DefaultSettingsSaved, MSGBOX_DEFAULT
# 67 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_NORMAL_MODE
# 68 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_MIN_GRINDING_MODE
# 69 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOMIZER_ENABLED
# 70 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOM_ABILITIES_ENABLED
# 71 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOM_ABILITIES_ENABLED
# 72 "data/maps/InsideOfTruck/scripts.pory"
	special ForceBattleStyleSetPleaseGod
# 73 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MAX_MON_MODE
# 74 "data/maps/InsideOfTruck/scripts.pory"
	return
# 75 "data/maps/InsideOfTruck/scripts.pory"

# 76 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_EventScript_MovingBox::
# 77 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
# 78 "data/maps/InsideOfTruck/scripts.pory"
	end
# 79 "data/maps/InsideOfTruck/scripts.pory"

# 80 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_BoxPrintedWithMonLogo:
# 81 "data/maps/InsideOfTruck/scripts.pory"
	.string "The box is printed with a Pokémon logo.\p"
# 82 "data/maps/InsideOfTruck/scripts.pory"
	.string "It's a Pokémon brand moving and\n"
# 83 "data/maps/InsideOfTruck/scripts.pory"
	.string "delivery service.$"
# 84 "data/maps/InsideOfTruck/scripts.pory"

# 85 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_ReadCarefully:
# 86 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Please take a moment to read the\n"
# 87 "data/maps/InsideOfTruck/scripts.pory"
	.string "following carefully.$"
# 88 "data/maps/InsideOfTruck/scripts.pory"

# 89 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_WantToUseDefaultSettings:
# 90 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}Would you like to play Pokémon Emerald\n"
# 91 "data/maps/InsideOfTruck/scripts.pory"
	.string "Imperium with the default settings?\p"
# 92 "data/maps/InsideOfTruck/scripts.pory"
	.string "The default settings are as follows:\p"
# 93 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal difficulty{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} - challenging boss\n"
# 94 "data/maps/InsideOfTruck/scripts.pory"
	.string "battles with hard level caps enforced.\p"
# 95 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Minimal Grinding Mode is ON{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} - this\n"
# 96 "data/maps/InsideOfTruck/scripts.pory"
	.string "guarantees all Pokémon will have\l"
# 97 "data/maps/InsideOfTruck/scripts.pory"
	.string "perfect IVs, and EVs cannot be\l"
# 98 "data/maps/InsideOfTruck/scripts.pory"
	.string "obtained.  Boss Pokémon will not have\l"
# 99 "data/maps/InsideOfTruck/scripts.pory"
	.string "EVs either.\p"
# 100 "data/maps/InsideOfTruck/scripts.pory"
	.string "Randomizer {COLOR RED}{SHADOW LIGHT_RED}OFF{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} - no additional\n"
# 101 "data/maps/InsideOfTruck/scripts.pory"
	.string "randomization will be enabled.\p"
# 102 "data/maps/InsideOfTruck/scripts.pory"
	.string "With this information in mind:\n"
# 103 "data/maps/InsideOfTruck/scripts.pory"
	.string "Would you like to play Pokémon Emerald\l"
# 104 "data/maps/InsideOfTruck/scripts.pory"
	.string "Imperium with the default settings?$"
# 105 "data/maps/InsideOfTruck/scripts.pory"

# 106 "data/maps/InsideOfTruck/scripts.pory"
InsideOfTruck_Text_DefaultSettingsSaved:
# 107 "data/maps/InsideOfTruck/scripts.pory"
	.string "Default settings saved.\n"
# 108 "data/maps/InsideOfTruck/scripts.pory"
	.string "Good luck!$"

InsideOfTruck_EventScript_StartSettingsMenu::
# 112 "data/maps/InsideOfTruck/scripts.pory"
	msgbox WhichOption
# 113 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_MIN_GRINDING_MODE, InsideOfTruck_EventScript_StartSettingsMenu_2
# 122 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_0, 0
# 123 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_4, 1
# 124 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_2, 2
# 125 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, 3
InsideOfTruck_EventScript_StartSettingsMenu_1:
# 130 "data/maps/InsideOfTruck/scripts.pory"
	dynmultistack 0, 0, TRUE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 132 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq InsideOfTruck_EventScript_StartSettingsMenu_6
InsideOfTruck_EventScript_StartSettingsMenu_5:
# 137 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq InsideOfTruck_EventScript_StartSettingsMenu_9
InsideOfTruck_EventScript_StartSettingsMenu_8:
# 142 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq InsideOfTruck_EventScript_StartSettingsMenu_12
InsideOfTruck_EventScript_StartSettingsMenu_11:
# 147 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq InsideOfTruck_EventScript_StartSettingsMenu_14
	return

InsideOfTruck_EventScript_StartSettingsMenu_2:
# 115 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_0, 0
# 116 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_1, 1
# 117 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_2, 2
# 118 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, 3
	goto InsideOfTruck_EventScript_StartSettingsMenu_1

InsideOfTruck_EventScript_StartSettingsMenu_6:
# 134 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_DifficultyOptions
	goto InsideOfTruck_EventScript_StartSettingsMenu_5

InsideOfTruck_EventScript_StartSettingsMenu_9:
# 139 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_MinGrindingMode
	goto InsideOfTruck_EventScript_StartSettingsMenu_8

InsideOfTruck_EventScript_StartSettingsMenu_12:
# 144 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_RandomzierOptions
	goto InsideOfTruck_EventScript_StartSettingsMenu_11

InsideOfTruck_EventScript_StartSettingsMenu_14:
# 149 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SaveSettingsDone
	return


InsideOfTruck_EventScript_DifficultyOptions::
# 154 "data/maps/InsideOfTruck/scripts.pory"
	msgbox WhichDifficulty
# 155 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_GAME_SETTING_DIFFICULTY_MODE
# 157 "data/maps/InsideOfTruck/scripts.pory"
	case GAME_SETTING_DIFFICULTY_NORMAL_MODE, InsideOfTruck_EventScript_DifficultyOptions_3
# 162 "data/maps/InsideOfTruck/scripts.pory"
	case GAME_SETTING_DIFFICULTY_EASY_MODE, InsideOfTruck_EventScript_DifficultyOptions_4
# 168 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_0, GAME_SETTING_DIFFICULTY_NORMAL_MODE
# 169 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_1, GAME_SETTING_DIFFICULTY_EASY_MODE
# 170 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
InsideOfTruck_EventScript_DifficultyOptions_1:
# 175 "data/maps/InsideOfTruck/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 177 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_7
InsideOfTruck_EventScript_DifficultyOptions_6:
# 182 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, GAME_SETTING_DIFFICULTY_NORMAL_MODE
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_10
InsideOfTruck_EventScript_DifficultyOptions_9:
# 202 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, GAME_SETTING_DIFFICULTY_EASY_MODE
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_12
	return

InsideOfTruck_EventScript_DifficultyOptions_3:
# 158 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_0, GAME_SETTING_DIFFICULTY_NORMAL_MODE
# 159 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_1, GAME_SETTING_DIFFICULTY_EASY_MODE
# 160 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_DifficultyOptions_1

InsideOfTruck_EventScript_DifficultyOptions_4:
# 163 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_2, GAME_SETTING_DIFFICULTY_NORMAL_MODE
# 164 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_DifficultyOptions_Text_3, GAME_SETTING_DIFFICULTY_EASY_MODE
# 165 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_DifficultyOptions_1

InsideOfTruck_EventScript_DifficultyOptions_7:
# 179 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_StartSettingsMenu
	goto InsideOfTruck_EventScript_DifficultyOptions_6

InsideOfTruck_EventScript_DifficultyOptions_10:
# 184 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_NORMAL_MODE
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_14
# 191 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalDifficultyYesNo, MSGBOX_YESNO
# 192 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_21
InsideOfTruck_EventScript_DifficultyOptions_20:
# 197 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_DifficultyOptions
	goto InsideOfTruck_EventScript_DifficultyOptions_9

InsideOfTruck_EventScript_DifficultyOptions_12:
# 204 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_EASY_MODE
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_17
# 211 "data/maps/InsideOfTruck/scripts.pory"
	msgbox EasyDifficultyYesNo, MSGBOX_YESNO
# 212 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_DifficultyOptions_24
InsideOfTruck_EventScript_DifficultyOptions_23:
# 217 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_DifficultyOptions
	return

InsideOfTruck_EventScript_DifficultyOptions_14:
# 186 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalDifficultyCurrentlySelected
# 187 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_DifficultyOptions
	goto InsideOfTruck_EventScript_DifficultyOptions_9

InsideOfTruck_EventScript_DifficultyOptions_17:
# 206 "data/maps/InsideOfTruck/scripts.pory"
	msgbox EasyDifficultyCurrentlySelected
# 207 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_DifficultyOptions
	return

InsideOfTruck_EventScript_DifficultyOptions_21:
# 194 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_NORMAL_MODE
# 195 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalDifficultyEnabled
	goto InsideOfTruck_EventScript_DifficultyOptions_20

InsideOfTruck_EventScript_DifficultyOptions_24:
# 214 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_GAME_SETTING_DIFFICULTY_MODE, GAME_SETTING_DIFFICULTY_EASY_MODE
# 215 "data/maps/InsideOfTruck/scripts.pory"
	msgbox EasyDifficultyEnabled
	goto InsideOfTruck_EventScript_DifficultyOptions_23


InsideOfTruck_EventScript_MinGrindingMode::
# 223 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_MIN_GRINDING_MODE, InsideOfTruck_EventScript_MinGrindingMode_2
# 234 "data/maps/InsideOfTruck/scripts.pory"
	msgbox MinGrindingAlreadyOffYesNo, MSGBOX_YESNO
# 235 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_MinGrindingMode_7
InsideOfTruck_EventScript_MinGrindingMode_1:
# 241 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_StartSettingsMenu
	return

InsideOfTruck_EventScript_MinGrindingMode_2:
# 225 "data/maps/InsideOfTruck/scripts.pory"
	msgbox MinGrindingAlreadyOnYesNo, MSGBOX_YESNO
# 226 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_MinGrindingMode_5
	goto InsideOfTruck_EventScript_MinGrindingMode_1

InsideOfTruck_EventScript_MinGrindingMode_5:
# 228 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_MIN_GRINDING_MODE
# 229 "data/maps/InsideOfTruck/scripts.pory"
	msgbox MinGrindingDisabled
	goto InsideOfTruck_EventScript_MinGrindingMode_1

InsideOfTruck_EventScript_MinGrindingMode_7:
# 237 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_MIN_GRINDING_MODE
# 238 "data/maps/InsideOfTruck/scripts.pory"
	msgbox MinGrindingEnabled
	goto InsideOfTruck_EventScript_MinGrindingMode_1


InsideOfTruck_EventScript_RandomzierOptions::
# 247 "data/maps/InsideOfTruck/scripts.pory"
	msgbox WhichRandomizerOption
# 250 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOMIZER_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_2
# 256 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_1, 0
InsideOfTruck_EventScript_RandomzierOptions_1:
# 260 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOM_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_6
# 266 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_3, 1
InsideOfTruck_EventScript_RandomzierOptions_5:
# 270 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOM_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_10
# 284 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_6, 2
InsideOfTruck_EventScript_RandomzierOptions_9:
# 297 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
# 299 "data/maps/InsideOfTruck/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 301 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_14
InsideOfTruck_EventScript_RandomzierOptions_13:
# 307 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_20
InsideOfTruck_EventScript_RandomzierOptions_19:
# 313 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_23
InsideOfTruck_EventScript_RandomzierOptions_22:
# 338 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_25
	return

InsideOfTruck_EventScript_RandomzierOptions_2:
# 252 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_0, 0
	goto InsideOfTruck_EventScript_RandomzierOptions_1

InsideOfTruck_EventScript_RandomzierOptions_6:
# 262 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_2, 1
	goto InsideOfTruck_EventScript_RandomzierOptions_5

InsideOfTruck_EventScript_RandomzierOptions_10:
# 272 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOM_MEGA_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_16
# 278 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_5, 2
	goto InsideOfTruck_EventScript_RandomzierOptions_9

InsideOfTruck_EventScript_RandomzierOptions_14:
# 303 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_StartSettingsMenu
	goto InsideOfTruck_EventScript_RandomzierOptions_13

InsideOfTruck_EventScript_RandomzierOptions_16:
# 274 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_RandomzierOptions_Text_4, 2
	goto InsideOfTruck_EventScript_RandomzierOptions_9

InsideOfTruck_EventScript_RandomzierOptions_20:
# 309 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions
	goto InsideOfTruck_EventScript_RandomzierOptions_19

InsideOfTruck_EventScript_RandomzierOptions_23:
# 315 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOM_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_28
# 327 "data/maps/InsideOfTruck/scripts.pory"
	msgbox RandomAbilitiesAlreadyOffYesNo, MSGBOX_YESNO
# 328 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_36
InsideOfTruck_EventScript_RandomzierOptions_27:
# 334 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_RandomzierOptions
	goto InsideOfTruck_EventScript_RandomzierOptions_22

InsideOfTruck_EventScript_RandomzierOptions_25:
# 340 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_unset FLAG_RANDOM_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_32
InsideOfTruck_EventScript_RandomzierOptions_31:
# 346 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_set FLAG_RANDOM_MEGA_ABILITIES_ENABLED, InsideOfTruck_EventScript_RandomzierOptions_39
# 357 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_RandomzierOptions_Text_10, MSGBOX_YESNO
# 358 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_44
InsideOfTruck_EventScript_RandomzierOptions_38:
# 364 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_RandomzierOptions
	return

InsideOfTruck_EventScript_RandomzierOptions_28:
# 317 "data/maps/InsideOfTruck/scripts.pory"
	msgbox RandomAbilitiesAlreadyOnYesNo, MSGBOX_YESNO
# 318 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_34
	goto InsideOfTruck_EventScript_RandomzierOptions_27

InsideOfTruck_EventScript_RandomzierOptions_32:
# 342 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_RandomzierOptions_Text_7
# 343 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_RandomzierOptions
	goto InsideOfTruck_EventScript_RandomzierOptions_31

InsideOfTruck_EventScript_RandomzierOptions_34:
# 320 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOM_ABILITIES_ENABLED
# 321 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOM_MEGA_ABILITIES_ENABLED
# 322 "data/maps/InsideOfTruck/scripts.pory"
	msgbox RandomAbilitiesDisabled
	goto InsideOfTruck_EventScript_RandomzierOptions_27

InsideOfTruck_EventScript_RandomzierOptions_36:
# 330 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOM_ABILITIES_ENABLED
# 331 "data/maps/InsideOfTruck/scripts.pory"
	msgbox RandomAbilitiesEnabled
	goto InsideOfTruck_EventScript_RandomzierOptions_27

InsideOfTruck_EventScript_RandomzierOptions_39:
# 348 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_RandomzierOptions_Text_8, MSGBOX_YESNO
# 349 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_RandomzierOptions_42
	goto InsideOfTruck_EventScript_RandomzierOptions_38

InsideOfTruck_EventScript_RandomzierOptions_42:
# 351 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOM_MEGA_ABILITIES_ENABLED
# 352 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_RandomzierOptions_Text_9
	goto InsideOfTruck_EventScript_RandomzierOptions_38

InsideOfTruck_EventScript_RandomzierOptions_44:
# 360 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOM_MEGA_ABILITIES_ENABLED
# 361 "data/maps/InsideOfTruck/scripts.pory"
	msgbox InsideOfTruck_EventScript_RandomzierOptions_Text_11
	goto InsideOfTruck_EventScript_RandomzierOptions_38


InsideOfTruck_EventScript_SpeciesRandomizerOptions::
# 376 "data/maps/InsideOfTruck/scripts.pory"
	msgbox WhichSpeciesRandomizerOption
# 377 "data/maps/InsideOfTruck/scripts.pory"
	goto_if_unset FLAG_RANDOMIZER_ENABLED, InsideOfTruck_EventScript_SpeciesRandomizerOptions_2
# 386 "data/maps/InsideOfTruck/scripts.pory"
	switch VAR_RANDOMIZER_MODE
# 388 "data/maps/InsideOfTruck/scripts.pory"
	case MON_RANDOM, InsideOfTruck_EventScript_SpeciesRandomizerOptions_9
# 394 "data/maps/InsideOfTruck/scripts.pory"
	case MON_RANDOM_BST, InsideOfTruck_EventScript_SpeciesRandomizerOptions_10
# 400 "data/maps/InsideOfTruck/scripts.pory"
	case MON_RANDOM_LEGEND_AWARE, InsideOfTruck_EventScript_SpeciesRandomizerOptions_11
# 406 "data/maps/InsideOfTruck/scripts.pory"
	case MAX_MON_MODE, InsideOfTruck_EventScript_SpeciesRandomizerOptions_12
# 413 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_0, MON_RANDOM
# 414 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_1, MON_RANDOM_BST
# 415 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_2, MON_RANDOM_LEGEND_AWARE
# 416 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
InsideOfTruck_EventScript_SpeciesRandomizerOptions_1:
# 424 "data/maps/InsideOfTruck/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 426 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_6
InsideOfTruck_EventScript_SpeciesRandomizerOptions_5:
# 431 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_RANDOM
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_15
InsideOfTruck_EventScript_SpeciesRandomizerOptions_14:
# 456 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_RANDOM_BST
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_18
InsideOfTruck_EventScript_SpeciesRandomizerOptions_17:
# 481 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, MON_RANDOM_LEGEND_AWARE
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_24
	return

InsideOfTruck_EventScript_SpeciesRandomizerOptions_2:
# 379 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_0, MON_RANDOM
# 380 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_1, MON_RANDOM_BST
# 381 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_2, MON_RANDOM_LEGEND_AWARE
# 382 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_1

InsideOfTruck_EventScript_SpeciesRandomizerOptions_6:
# 428 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_RandomzierOptions
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_5

InsideOfTruck_EventScript_SpeciesRandomizerOptions_9:
# 389 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_3, MON_RANDOM
# 390 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_1, MON_RANDOM_BST
# 391 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_2, MON_RANDOM_LEGEND_AWARE
# 392 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_1

InsideOfTruck_EventScript_SpeciesRandomizerOptions_10:
# 395 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_0, MON_RANDOM
# 396 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_4, MON_RANDOM_BST
# 397 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_2, MON_RANDOM_LEGEND_AWARE
# 398 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_1

InsideOfTruck_EventScript_SpeciesRandomizerOptions_11:
# 401 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_0, MON_RANDOM
# 402 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_1, MON_RANDOM_BST
# 403 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_5, MON_RANDOM_LEGEND_AWARE
# 404 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_1

InsideOfTruck_EventScript_SpeciesRandomizerOptions_12:
# 407 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_0, MON_RANDOM
# 408 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_1, MON_RANDOM_BST
# 409 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_2, MON_RANDOM_LEGEND_AWARE
# 410 "data/maps/InsideOfTruck/scripts.pory"
	dynmultipush InsideOfTruck_EventScript_StartSettingsMenu_Text_3, MULTI_B_PRESSED
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_1

InsideOfTruck_EventScript_SpeciesRandomizerOptions_15:
# 433 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RANDOMIZER_MODE, MON_RANDOM
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_21
# 445 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalSpeciesRandomizerAlreadyOffYesNo, MSGBOX_YESNO
# 446 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_32
InsideOfTruck_EventScript_SpeciesRandomizerOptions_20:
# 453 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_14

InsideOfTruck_EventScript_SpeciesRandomizerOptions_18:
# 458 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RANDOMIZER_MODE, MON_RANDOM_BST
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_27
# 470 "data/maps/InsideOfTruck/scripts.pory"
	msgbox ScaledSpeciesRandomizerAlreadyOffYesNo, MSGBOX_YESNO
# 471 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_40
InsideOfTruck_EventScript_SpeciesRandomizerOptions_26:
# 478 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_17

InsideOfTruck_EventScript_SpeciesRandomizerOptions_21:
# 435 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalSpeciesRandomizerAlreadyOnYesNo, MSGBOX_YESNO
# 436 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_30
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_20

InsideOfTruck_EventScript_SpeciesRandomizerOptions_24:
# 483 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RANDOMIZER_MODE, MON_RANDOM_LEGEND_AWARE
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_35
# 495 "data/maps/InsideOfTruck/scripts.pory"
	msgbox LegendsAwareRandomizerAlreadyOffYesNo, MSGBOX_YESNO
# 496 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_44
InsideOfTruck_EventScript_SpeciesRandomizerOptions_34:
# 503 "data/maps/InsideOfTruck/scripts.pory"
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions
	return

InsideOfTruck_EventScript_SpeciesRandomizerOptions_27:
# 460 "data/maps/InsideOfTruck/scripts.pory"
	msgbox ScaledSpeciesRandomizerAlreadyOnYesNo, MSGBOX_YESNO
# 461 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_38
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_26

InsideOfTruck_EventScript_SpeciesRandomizerOptions_30:
# 438 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOMIZER_ENABLED
# 439 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MAX_MON_MODE
# 440 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalSpeciesRandomizerDisabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_20

InsideOfTruck_EventScript_SpeciesRandomizerOptions_32:
# 448 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOMIZER_ENABLED
# 449 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MON_RANDOM
# 450 "data/maps/InsideOfTruck/scripts.pory"
	msgbox NormalSpeciesRandomizerEnabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_20

InsideOfTruck_EventScript_SpeciesRandomizerOptions_35:
# 485 "data/maps/InsideOfTruck/scripts.pory"
	msgbox LegendsAwareRandomizerAlreadyOnYesNo, MSGBOX_YESNO
# 486 "data/maps/InsideOfTruck/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq InsideOfTruck_EventScript_SpeciesRandomizerOptions_42
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_34

InsideOfTruck_EventScript_SpeciesRandomizerOptions_38:
# 463 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOMIZER_ENABLED
# 464 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MAX_MON_MODE
# 465 "data/maps/InsideOfTruck/scripts.pory"
	msgbox ScaledSpeciesRandomizerDisabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_26

InsideOfTruck_EventScript_SpeciesRandomizerOptions_40:
# 473 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOMIZER_ENABLED
# 474 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MON_RANDOM_BST
# 475 "data/maps/InsideOfTruck/scripts.pory"
	msgbox ScaledSpeciesRandomizerEnabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_26

InsideOfTruck_EventScript_SpeciesRandomizerOptions_42:
# 488 "data/maps/InsideOfTruck/scripts.pory"
	clearflag FLAG_RANDOMIZER_ENABLED
# 489 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MAX_MON_MODE
# 490 "data/maps/InsideOfTruck/scripts.pory"
	msgbox LegendsAwareRandomizerDisabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_34

InsideOfTruck_EventScript_SpeciesRandomizerOptions_44:
# 498 "data/maps/InsideOfTruck/scripts.pory"
	setflag FLAG_RANDOMIZER_ENABLED
# 499 "data/maps/InsideOfTruck/scripts.pory"
	setvar VAR_RANDOMIZER_MODE, MON_RANDOM_LEGEND_AWARE
# 500 "data/maps/InsideOfTruck/scripts.pory"
	msgbox LegendsAwareRandomizerEnabled
	goto InsideOfTruck_EventScript_SpeciesRandomizerOptions_34


InsideOfTruck_EventScript_SaveSettingsDone::
# 510 "data/maps/InsideOfTruck/scripts.pory"
	special ForceBattleStyleSetPleaseGod
# 511 "data/maps/InsideOfTruck/scripts.pory"
	msgbox CustomSettingsSaved
# 512 "data/maps/InsideOfTruck/scripts.pory"
	releaseall
	end


InsideOfTruck_EventScript_StartSettingsMenu_Text_0:
# 115 "data/maps/InsideOfTruck/scripts.pory"
	.string "Difficulty Options$"

InsideOfTruck_EventScript_StartSettingsMenu_Text_1:
# 116 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Minimal Grinding Mode$"

InsideOfTruck_EventScript_StartSettingsMenu_Text_2:
# 117 "data/maps/InsideOfTruck/scripts.pory"
	.string "Randomizer Options$"

InsideOfTruck_EventScript_StartSettingsMenu_Text_3:
# 118 "data/maps/InsideOfTruck/scripts.pory"
	.string "Done$"

InsideOfTruck_EventScript_StartSettingsMenu_Text_4:
# 123 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Minimal Grinding Mode$"

InsideOfTruck_EventScript_DifficultyOptions_Text_0:
# 158 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal$"

InsideOfTruck_EventScript_DifficultyOptions_Text_1:
# 159 "data/maps/InsideOfTruck/scripts.pory"
	.string "Easy$"

InsideOfTruck_EventScript_DifficultyOptions_Text_2:
# 163 "data/maps/InsideOfTruck/scripts.pory"
	.string "Normal$"

InsideOfTruck_EventScript_DifficultyOptions_Text_3:
# 164 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Easy$"

InsideOfTruck_EventScript_RandomzierOptions_Text_0:
# 252 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Species$"

InsideOfTruck_EventScript_RandomzierOptions_Text_1:
# 256 "data/maps/InsideOfTruck/scripts.pory"
	.string "Species$"

InsideOfTruck_EventScript_RandomzierOptions_Text_2:
# 262 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ability$"

InsideOfTruck_EventScript_RandomzierOptions_Text_3:
# 266 "data/maps/InsideOfTruck/scripts.pory"
	.string "Ability$"

InsideOfTruck_EventScript_RandomzierOptions_Text_4:
# 274 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Mega Ability$"

InsideOfTruck_EventScript_RandomzierOptions_Text_5:
# 278 "data/maps/InsideOfTruck/scripts.pory"
	.string "Mega Ability$"

InsideOfTruck_EventScript_RandomzierOptions_Text_6:
# 284 "data/maps/InsideOfTruck/scripts.pory"
	.string "Mega Ability (requires Ability)$"

InsideOfTruck_EventScript_RandomzierOptions_Text_7:
# 342 "data/maps/InsideOfTruck/scripts.pory"
	.string "Turn on Ability randomizer first.$"

InsideOfTruck_EventScript_RandomzierOptions_Text_8:
# 348 "data/maps/InsideOfTruck/scripts.pory"
	.string "Randomize Mega Abilities is currently ON.\nTurn it OFF?$"

InsideOfTruck_EventScript_RandomzierOptions_Text_9:
# 352 "data/maps/InsideOfTruck/scripts.pory"
	.string "Mega Abilities will no longer be randomized.$"

InsideOfTruck_EventScript_RandomzierOptions_Text_10:
# 357 "data/maps/InsideOfTruck/scripts.pory"
	.string "Randomize Mega Abilities is currently OFF.\nTurn it ON?$"

InsideOfTruck_EventScript_RandomzierOptions_Text_11:
# 361 "data/maps/InsideOfTruck/scripts.pory"
	.string "Mega Abilities will now be randomized.$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_0:
# 379 "data/maps/InsideOfTruck/scripts.pory"
	.string "Normal species$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_1:
# 380 "data/maps/InsideOfTruck/scripts.pory"
	.string "Scaled species$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_2:
# 381 "data/maps/InsideOfTruck/scripts.pory"
	.string "Legendary-aware species$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_3:
# 389 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal species$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_4:
# 396 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Scaled species$"

InsideOfTruck_EventScript_SpeciesRandomizerOptions_Text_5:
# 403 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Legendary-aware species$"

WhichOption::
# 517 "data/maps/InsideOfTruck/scripts.pory"
	.string "Which option would you like\n"
	.string "to customize?$"

WhichDifficulty::
# 523 "data/maps/InsideOfTruck/scripts.pory"
	.string "Which difficulty mode would you\n"
	.string "like to play on?$"

WhichRandomizerOption::
# 529 "data/maps/InsideOfTruck/scripts.pory"
	.string "Which randomizer option would you\n"
	.string "like to customize?$"

WhichSpeciesRandomizerOption::
# 535 "data/maps/InsideOfTruck/scripts.pory"
	.string "Which Species Randomizer option would\n"
	.string "you like to customize?$"

NormalDifficultyCurrentlySelected::
# 541 "data/maps/InsideOfTruck/scripts.pory"
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
# 556 "data/maps/InsideOfTruck/scripts.pory"
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
# 573 "data/maps/InsideOfTruck/scripts.pory"
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
# 587 "data/maps/InsideOfTruck/scripts.pory"
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
# 603 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal Mode{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} enabled.$"

EasyDifficultyEnabled::
# 608 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Easy Mode{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} enabled.$"

MinGrindingAlreadyOnYesNo::
# 613 "data/maps/InsideOfTruck/scripts.pory"
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
# 628 "data/maps/InsideOfTruck/scripts.pory"
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
# 643 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Minimal Grinding Mode enabled.$"

MinGrindingDisabled::
# 648 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Minimal Grinding Mode disabled.$"

RandomAbilitiesAlreadyOnYesNo::
# 654 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ability Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes abilities\n"
	.string "for the player, but doesn't affect\l"
	.string "abilities on Boss Pokémon.\p"
	.string "Do you want to turn off the\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Ability Randomizer?$"

RandomAbilitiesAlreadyOffYesNo::
# 663 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ability Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes abilities\n"
	.string "for the player, but doesn't affect\l"
	.string "abilities on Boss Pokémon.\p"
	.string "Do you want to turn on the\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ability Randomizer?$"

RandomAbilitiesEnabled::
# 673 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Ability Randomizer enabled.$"

RandomAbilitiesDisabled::
# 678 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Ability Randomizer disabled.$"

RandomLearnsetsAlreadyOnYesNo::
# 684 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Learnset Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes\n"
	.string "Pokémon learnsets.\p"
	.string "It does not randomize TMs or\n"
	.string "move tutors.\p"
	.string "Boss Pokémon also keep their normal\n"
	.string "movesets.\p"
	.string "Do you want to turn off the\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Learnset Randomizer?$"

RandomLearnsetsAlreadyOffYesNo::
# 696 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Learnset Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes\n"
	.string "Pokémon learnsets.\p"
	.string "It does not randomize TMs or\n"
	.string "move tutors.\p"
	.string "Boss Pokémon also keep their normal\n"
	.string "movesets.\p"
	.string "Do you want to turn on the\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Learnset Randomizer?$"

RandomLearnsetsEnabled::
# 709 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Learnset Randomizer enabled.$"

RandomLearnsetsDisabled::
# 714 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Learnset Randomizer disabled.$"

NormalSpeciesRandomizerAlreadyOnYesNo::
# 720 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Species Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes\n"
	.string "encounters, trainers, and gifts.\l"
	.string "It does not randomize boss battles.\p"
	.string "Many legendaries cannot be\n"
	.string "encountered.\p"
	.string "Do you want to turn off the\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Species Randomizer?$"

NormalSpeciesRandomizerAlreadyOffYesNo::
# 731 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Species Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} randomizes\n"
	.string "encounters, trainers, and gifts.\l"
	.string "It does not randomize boss battles.\p"
	.string "Many legendaries cannot be\n"
	.string "encountered.\p"
	.string "Do you want to turn on the\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Species Randomizer?$"

NormalSpeciesRandomizerEnabled::
# 743 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Species Randomizer enabled.$"

NormalSpeciesRandomizerDisabled::
# 748 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Species Randomizer disabled.$"

ScaledSpeciesRandomizerAlreadyOnYesNo::
# 754 "data/maps/InsideOfTruck/scripts.pory"
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
# 767 "data/maps/InsideOfTruck/scripts.pory"
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
# 781 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Scaled Randomizer enabled.$"

ScaledSpeciesRandomizerDisabled::
# 786 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Scaled Randomizer disabled.$"

LegendsAwareRandomizerAlreadyOnYesNo::
# 791 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Legendary-aware Species Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} is\n"
	.string "the same thing as the Species\l"
	.string "Randomizer, with the only difference\l"
	.string "being that legendary Pokémon will be\l"
	.string "guaranteed to be randomized into\l"
	.string "legendary Pokémon.\p"
	.string "Do you want to turn off the\n"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Legendary-aware Species Randomizer?$"

LegendsAwareRandomizerAlreadyOffYesNo::
# 803 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Legendary-aware Species Randomizer{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} is\n"
	.string "the same thing as the Species\l"
	.string "Randomizer, with the only difference\l"
	.string "being that legendary Pokémon will be\l"
	.string "guaranteed to be randomized into\l"
	.string "legendary Pokémon.\p"
	.string "Do you want to turn on the\n"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Legendary-aware Species Randomizer?$"

LegendsAwareRandomizerEnabled::
# 816 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Legendary-aware Species Randomizer\n"
	.string "enabled.$"

LegendsAwareRandomizerDisabled::
# 822 "data/maps/InsideOfTruck/scripts.pory"
	.string "{COLOR RED}{SHADOW LIGHT_RED}Legendary-aware Species Randomizer\n"
	.string "disabled.$"

CustomSettingsSaved::
# 829 "data/maps/InsideOfTruck/scripts.pory"
	.string "Custom settings saved.\n"
	.string "Good luck!$"
