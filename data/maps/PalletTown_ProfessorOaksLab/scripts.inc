# 1 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 2 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_PROF_OAK,        4
# 3 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_BULBASAUR_BALL,  5
# 4 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_SQUIRTLE_BALL,   6
# 5 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_CHARMANDER_BALL, 7
# 6 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_RIVAL,           8
# 7 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_POKEDEX_1,       9
# 8 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_POKEDEX_2,       10
# 9 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 10 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ PLAYER_STARTER_NUM,      VAR_TEMP_1
# 11 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ PLAYER_STARTER_SPECIES,  VAR_TEMP_2
# 12 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ RIVAL_STARTER_SPECIES,   VAR_TEMP_3
# 13 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ RIVAL_STARTER_ID,        VAR_TEMP_4
# 14 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 15 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ SHOWED_OAK_COMPLETE_DEX, FLAG_TEMP_2
# 16 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 17 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_MapScripts::
# 18 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_ProfessorOaksLab_OnTransition
# 19 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_ProfessorOaksLab_OnWarp
# 20 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_ProfessorOaksLab_OnFrame
# 21 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.byte 0
# 22 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 23 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnTransition::
# 24 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_VISITED_OAKS_LAB
# 25 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_EventScript_ReadyOakForStarterScene
# 26 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7, PalletTown_ProfessorOaksLab_EventScript_ReadyOakForNationalDexScene
# 27 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8, PalletTown_ProfessorOaksLab_EventScript_SetNationalDexSceneFinished
# 28 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, PalletTown_ProfessorOaksLab_EventScript_SetSkipPokeBallCheck
# 29 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 30 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 31 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SetSkipPokeBallCheck::
# 32 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_OAK_SKIP_22_RIVAL_CHECK
# 33 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 34 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 35 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SetNationalDexSceneFinished::
# 36 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 9
# 37 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 38 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 39 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyOakForStarterScene::
# 40 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 11
# 41 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_UP
# 42 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	savebgm MUS_OAK
# 43 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 44 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 45 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyOakForNationalDexScene::
# 46 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 11
# 47 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_UP
# 48 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 49 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 50 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnWarp::
# 51 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_EventScript_ReadyPlayerForStarterScene
# 52 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.2byte 0
# 53 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 54 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyPlayerForStarterScene::
# 55 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 56 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 57 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 58 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnFrame::
# 59 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_ChooseStarterScene
# 60 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7, PalletTown_ProfessorOaksLab_EventScript_EnterForNationalDexScene
# 61 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.2byte 0
# 62 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 63 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_EnterForNationalDexScene:: @ 8169002 
# 64 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 65 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_FACING, DIR_NORTH
# 66 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 67 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakEnter
# 68 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 69 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_PROF_OAK
# 70 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 3
# 71 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_DOWN
# 72 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 73 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerEnter
# 74 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 75 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_NationalDexScene
# 76 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 77 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 78 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexScene::
# 79 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakSightingsOfRareMons
# 80 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 81 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterNorth
# 82 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterSouth
# 83 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest
# 84 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest
# 85 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalJustLetMeHandleEverything
# 86 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 87 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakNeedYourHelpTooNeedToSeePokedexes
# 88 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakNorth
# 89 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakWest
# 90 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 91 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakTookBothPokedexUnits
# 92 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 93 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 94 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskNorth
# 95 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskSouth
# 96 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskEast
# 97 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskWest
# 98 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_POKEDEX_1
# 99 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_POKEDEX_2
# 100 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 101 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakNowTheseUnitsCanRecordMoreData
# 102 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 103 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_1
# 104 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_2
# 105 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 106 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth
# 107 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth
# 108 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast
# 109 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest
# 110 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 111 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 112 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_PlayersPokedexWasUpgraded
# 113 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 114 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 115 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 116 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special EnableNationalPokedex
# 117 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakMustReallyWorkToFillPokedex
# 118 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalIllCompleteThePokedex
# 119 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 120 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 121 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth
# 122 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 123 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 124 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 125 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_RIVAL
# 126 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 127 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8
# 128 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 129 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 130 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 131 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterNorth::
# 132 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 133 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 134 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 135 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth
# 136 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 137 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 138 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 139 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 140 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest::
# 141 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 142 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 143 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 144 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 145 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 146 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 147 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 148 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 149 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 150 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterSouth::
# 151 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 152 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 153 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 154 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 155 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 156 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 157 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 158 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 159 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakNorth::
# 160 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 161 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 162 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 163 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 164 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakWest::
# 165 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 166 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 167 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 168 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 169 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskNorth::
# 170 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 171 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 172 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 173 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 174 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskSouth::
# 175 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDeskSouth
# 176 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 177 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 178 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 179 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 180 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 181 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskEast::
# 182 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 183 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast
# 184 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 185 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 186 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 187 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskWest::
# 188 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 189 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 190 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 191 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 192 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk::
# 193 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 194 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 195 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 196 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 197 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 198 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 199 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 200 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDeskSouth::
# 201 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 202 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 203 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 204 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 205 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 206 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 207 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 208 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_ChooseStarterScene::
# 209 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 210 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 211 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakWaiting
# 212 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 213 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 60
# 214 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakEnter
# 215 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 216 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_PROF_OAK
# 217 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 3
# 218 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_DOWN
# 219 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 220 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerEnter
# 221 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 222 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 223 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 224 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 225 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	savebgm MUS_DUMMY
# 226 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 227 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalFedUpWithWaiting
# 228 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 229 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 60
# 230 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakThreeMonsChooseOne
# 231 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 232 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 233 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalReact2
# 234 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 235 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalNoFairWhatAboutMe
# 236 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakBePatientRival
# 237 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalReact
# 238 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 239 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalResearch
# 240 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakBeOnYourWay
# 241 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2
# 242 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 243 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 244 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 245 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakEnter::
# 246 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 247 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 248 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 249 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 250 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 251 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 252 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 253 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 254 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerEnter::
# 255 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 256 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 257 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 258 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 259 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 260 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 261 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 262 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 263 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 264 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 265 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalReact::
# 266 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 267 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 268 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 269 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 270 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalReact2::
# 271 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 272 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 273 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 274 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 275 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LeaveStarterSceneTrigger::
# 276 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 277 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 278 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
# 279 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 280 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHeyDontGoAwayYet
# 281 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 282 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWalkUp
# 283 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 284 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 285 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 286 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 287 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWalkUp::
# 288 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 289 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 290 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 291 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerLeft::
# 292 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 293 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 1
# 294 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 295 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 296 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 297 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerMid::
# 298 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 299 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 2
# 300 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 301 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 302 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 303 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerRight::
# 304 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 305 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 3
# 306 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 307 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 308 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 309 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattle::
# 310 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 311 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 312 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
# 313 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 314 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 315 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 316 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons
# 317 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 318 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
# 319 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 320 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 0, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmander
# 321 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaur
# 322 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtle
# 323 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 324 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 325 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ The scripts for the rival approaching the player for battle are a bit bloated because
# 326 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ both the player and rival can be in 3 different positions, so theres 9 different approaches
# 327 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ NOTE: Names below refer to the Rival's mon (e.g. for RivalBattleSquirtle, player has Charmander)
# 328 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 329 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtle::
# 330 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleLeft
# 331 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleMid
# 332 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleRight
# 333 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 334 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 335 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleLeft::
# 336 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleLeft
# 337 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 338 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 339 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 340 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 341 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleMid::
# 342 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleMid
# 343 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 344 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 345 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 346 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 347 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleRight::
# 348 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleRight
# 349 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 350 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 351 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 352 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 353 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle::
# 354 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_SQUIRTLE, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 355 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 356 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 357 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 358 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleLeft::
# 359 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 360 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 361 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 362 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 363 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 364 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 365 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 366 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 367 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleMid::
# 368 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 369 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 370 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 371 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 372 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 373 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 374 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 375 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleRight::
# 376 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 377 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 378 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 379 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 380 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 381 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 382 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmander::
# 383 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderLeft
# 384 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderMid
# 385 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderRight
# 386 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 387 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 388 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderLeft::
# 389 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderLeft
# 390 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 391 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 392 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 393 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 394 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderMid::
# 395 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderMid
# 396 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 397 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 398 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 399 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 400 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderRight::
# 401 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderRight
# 402 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 403 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 404 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 405 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 406 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander::
# 407 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_CHARMANDER, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 408 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 409 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 410 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 411 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderLeft::
# 412 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 413 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 414 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 415 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 416 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 417 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 418 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 419 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 420 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 421 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderMid::
# 422 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 423 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 424 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 425 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 426 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 427 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 428 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 429 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 430 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_ApproachForBattleCharmanderRight::
# 431 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 432 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 433 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 434 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 435 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 436 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 437 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 438 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaur::
# 439 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurLeft
# 440 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurMid
# 441 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurRight
# 442 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 443 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 444 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurLeft::
# 445 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurLeft
# 446 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 447 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 448 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 449 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 450 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurMid::
# 451 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurMid
# 452 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 453 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 454 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 455 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 456 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurRight::
# 457 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurRight
# 458 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 459 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 460 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 461 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 462 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur::
# 463 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_BULBASAUR, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 464 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 465 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 466 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 467 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurLeft::
# 468 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 469 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 470 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 471 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 472 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 473 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 474 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 475 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurMid::
# 476 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 477 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 478 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 479 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 480 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 481 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 482 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurRight::
# 483 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 484 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 485 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 486 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 487 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 488 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle::
# 489 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special HealPlayerParty
# 490 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon
# 491 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 492 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 493 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleLeft
# 494 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleMid
# 495 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleRight
# 496 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_RIVAL
# 497 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playse SE_EXIT
# 498 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 499 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4
# 500 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_BEAT_RIVAL_IN_OAKS_LAB
# 501 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 502 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 503 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 504 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleLeft::
# 505 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleLeft
# 506 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle
# 507 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_RIVAL
# 508 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 509 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 510 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleMid::
# 511 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleMid
# 512 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle
# 513 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_RIVAL
# 514 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 515 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 516 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleRight::
# 517 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleRight
# 518 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattleRight
# 519 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_RIVAL
# 520 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 521 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 522 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleLeft::
# 523 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 524 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 525 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 526 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 527 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 528 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 529 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 530 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 531 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 532 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleRight::
# 533 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 534 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 535 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 536 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 537 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 538 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 539 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 540 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 541 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 542 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleMid::
# 543 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 544 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 545 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 546 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 547 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 548 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 549 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 550 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 551 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 552 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 553 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle::
# 554 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 555 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 556 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 557 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 558 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 559 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 560 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 561 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattleRight::
# 562 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 563 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 564 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 565 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 566 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 567 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 568 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 569 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Rival::
# 570 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 571 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 572 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_RivalChoseStarter
# 573 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_RivalWaitingForStarter
# 574 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGrampsIsntAround
# 575 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 576 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 577 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 578 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWaitingForStarter::
# 579 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoChoosePlayer
# 580 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 581 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 582 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 583 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalChoseStarter::
# 584 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalMyMonLooksTougher
# 585 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 586 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 587 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 588 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ProfOak::
# 589 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 590 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 591 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set SHOWED_OAK_COMPLETE_DEX, PalletTown_ProfessorOaksLab_EventScript_OakJustShownCompleteDex
# 592 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 9, PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 593 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8, PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 594 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_TryStartNationalDexScene
# 595 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1, PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 596 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, PalletTown_ProfessorOaksLab_EventScript_RatePokedexOrTryGiveBalls
# 597 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 1, PalletTown_ProfessorOaksLab_EventScript_ReceiveDexScene
# 598 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4, PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow
# 599 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon
# 600 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakWhichOneWillYouChoose
# 601 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 602 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 603 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 604 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakJustShownCompleteDex::
# 605 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PokedexRating_Text_ThankYouMadeDreamReality
# 606 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 607 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 608 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 609 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon::
# 610 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon
# 611 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 612 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 613 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 614 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow::
# 615 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow
# 616 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 617 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 618 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 619 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReceiveDexScene::
# 620 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveSomethingForMe
# 621 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 622 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_TMHM
# 623 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_DeliveredOaksParcel
# 624 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 625 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 626 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 627 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeitem ITEM_OAKS_PARCEL
# 628 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCustomBallIOrdered
# 629 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 630 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGramps
# 631 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 632 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterNorth
# 633 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterSouth
# 634 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest
# 635 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest
# 636 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 637 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor
# 638 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 639 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 640 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playse SE_PIN
# 641 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_ExclamationMark
# 642 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 643 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_Delay48
# 644 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 645 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalSouth
# 646 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalEast
# 647 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalWest
# 648 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalNorth
# 649 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveRequestForYouTwo
# 650 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 651 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskNorth
# 652 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskSouth
# 653 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskEast
# 654 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskWest
# 655 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakPokedexOnDesk
# 656 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 657 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 40
# 658 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakTakeTheseWithYou
# 659 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 660 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterUp
# 661 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 662 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_1
# 663 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 10
# 664 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_2
# 665 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 25
# 666 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth
# 667 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth
# 668 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast
# 669 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest
# 670 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 10
# 671 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 672 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 673 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_ReceivedPokedexFromOak
# 674 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 675 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 676 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 677 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 678 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special SetUnlockedPokedexFlags
# 679 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1
# 680 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese
# 681 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	giveitem_msg PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls, ITEM_POKE_BALL, 5
# 682 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakExplainCatching
# 683 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 1
# 684 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream
# 685 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLeaveItToMeGramps
# 686 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerNorth
# 687 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerSouth
# 688 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest
# 689 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest
# 690 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalTellSisNotToGiveYouMap
# 691 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 692 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 693 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth
# 694 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 695 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 696 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 697 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_RIVAL
# 698 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 699 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6
# 700 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2
# 701 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
# 702 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1
# 703 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_ROUTE22, 1
# 704 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 705 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 706 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 707 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth::
# 708 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 709 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 710 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 711 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 712 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth::
# 713 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOverSouth
# 714 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 715 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 716 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 717 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast::
# 718 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 719 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerFaceOakForDexEast
# 720 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 721 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 722 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 723 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest::
# 724 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 725 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 726 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 727 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 728 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerFaceOakForDexEast::
# 729 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 730 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 731 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 732 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 733 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 734 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver::
# 735 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 736 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 737 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 738 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 739 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesOverSouth::
# 740 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 741 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 742 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 743 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 744 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskNorth::
# 745 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 746 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 747 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 748 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 749 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskSouth::
# 750 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDeskSouth
# 751 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 752 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 753 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 754 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 755 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 756 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskEast::
# 757 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 758 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast
# 759 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 760 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 761 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 762 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskWest::
# 763 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 764 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 765 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 766 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 767 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast::
# 768 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 769 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 770 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 771 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 772 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 773 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk::
# 774 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 775 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 776 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 777 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 778 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 779 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk::
# 780 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 781 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 782 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 783 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 784 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 785 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 786 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakWalkToDeskSouth::
# 787 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 788 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 789 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 790 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 791 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 792 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 793 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 794 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RatePokedexOrTryGiveBalls::
# 795 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_0x8004, 0
# 796 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	specialvar VAR_RESULT, GetPokedexCount
# 797 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 798 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 799 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 800 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 801 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_0x8009, 1, PalletTown_ProfessorOaksLab_EventScript_CheckIfPlayerNeedsBalls  @ Player only has starter
# 802 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 803 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 804 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 805 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RatePokedex::
# 806 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call PokedexRating_EventScript_RateInPerson
# 807 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_OAK_SAW_DEX_COMPLETION, PalletTown_ProfessorOaksLab_EventScript_DexCompleted
# 808 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 809 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 810 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 811 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexCompleted::
# 812 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 813 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 40
# 814 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PokedexRating_Text_Wroooaaarrr
# 815 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 816 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakExcitedNorth
# 817 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakExcitedSouth
# 818 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakExcitedEast
# 819 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakExcitedWest
# 820 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 821 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 822 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 823 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 70
# 824 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PokedexRating_Text_ThankYouMadeDreamReality
# 825 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag SHOWED_OAK_COMPLETE_DEX
# 826 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 827 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 828 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 829 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedNorth::
# 830 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedNorth
# 831 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 832 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 833 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 834 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedSouth::
# 835 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedSouth
# 836 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 837 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 838 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 839 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedEast::
# 840 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedEast
# 841 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 842 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 843 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 844 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedWest::
# 845 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedWest
# 846 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 847 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 848 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 849 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedNorth::
# 850 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 851 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_down
# 852 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 853 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 854 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_down
# 855 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 856 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 857 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 858 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedSouth::
# 859 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 860 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_up
# 861 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 862 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 863 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_up
# 864 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 865 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 866 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 867 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedEast::
# 868 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 869 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_left
# 870 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 871 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 872 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_left
# 873 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 874 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 875 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 876 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedWest::
# 877 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 878 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_right
# 879 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 880 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 881 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_right
# 882 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 883 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 884 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 885 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ Unused
# 886 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_Search:
# 887 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 888 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 889 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 890 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 891 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 892 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 893 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 894 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 895 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 896 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 897 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 898 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 899 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 900 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 901 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 902 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 903 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 904 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 905 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 906 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 907 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 908 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 909 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 910 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 911 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 912 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 913 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ Unused
# 914 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_VerticalPacing:
# 915 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 916 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 917 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 918 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 919 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 920 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 921 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 922 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 923 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 924 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 925 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_TryStartNationalDexScene::
# 926 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call PokedexRating_EventScript_RateInPerson
# 927 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 928 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene
# 929 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene
# 930 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 931 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakFavorToAskYouPlayer
# 932 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_NationalDexScene
# 933 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 934 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 935 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene::
# 936 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 937 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 938 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 939 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_CheckIfPlayerNeedsBalls::
# 940 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 941 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special QuestLog_CutRecording
# 942 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_OAK_SKIP_22_RIVAL_CHECK, PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 943 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, PalletTown_ProfessorOaksLab_EventScript_PlayerAlreadyGotBalls
# 944 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	checkitem ITEM_POKE_BALL
# 945 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PalletTown_ProfessorOaksLab_EventScript_PlayerOutOfBalls
# 946 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 947 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 948 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 949 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerOutOfBalls::
# 950 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ROUTE22, 2, PalletTown_ProfessorOaksLab_EventScript_GivePlayerMoreBalls
# 951 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 952 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 953 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 954 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_GivePlayerMoreBalls::
# 955 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakAddedNothingToPokedex
# 956 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	giveitem_msg PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls, ITEM_POKE_BALL, 5
# 957 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL
# 958 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 959 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 960 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 961 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait::
# 962 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakMonsAroundWorldWait
# 963 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 964 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 965 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 966 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerAlreadyGotBalls::
# 967 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakComeSeeMeSometime
# 968 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 969 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 970 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 971 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterNorth::
# 972 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 973 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 974 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth
# 975 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 976 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 977 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 978 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 979 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest::
# 980 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 981 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 982 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 983 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 984 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 985 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 986 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 987 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 988 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterSouth::
# 989 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 990 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 991 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 992 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 993 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 994 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 995 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 996 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalSouth::
# 997 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 998 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 999 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 1000 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 1001 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1002 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1003 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1004 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalWest::
# 1005 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 1006 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1007 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 1008 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 1009 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 1010 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1011 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1012 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1013 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalEast::
# 1014 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 1015 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1016 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 1017 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 1018 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 1019 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1020 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1021 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1022 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerNorth::
# 1023 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 1024 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 1025 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1026 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1027 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1028 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerSouth::
# 1029 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 1030 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1031 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1032 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1033 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1034 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest::
# 1035 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 1036 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1037 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1038 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1039 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1040 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth::
# 1041 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 1042 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExit
# 1043 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1044 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1045 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1046 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExit::
# 1047 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExit
# 1048 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1049 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1050 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1051 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalNorth::
# 1052 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1053 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1054 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1055 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1056 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest::
# 1057 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 1058 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 1059 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1060 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1061 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth::
# 1062 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 1063 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1064 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1065 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1066 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1067 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1068 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 1069 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 1070 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1071 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1072 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalEnter::
# 1073 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1074 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1075 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1076 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1077 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1078 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1079 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1080 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1081 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExit::
# 1082 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1083 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1084 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1085 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1086 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1087 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1088 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1089 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1090 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_BulbasaurBall::
# 1091 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1092 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1093 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 0
# 1094 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_BULBASAUR
# 1095 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_CHARMANDER
# 1096 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_CHARMANDER_BALL
# 1097 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1098 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1099 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1100 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1101 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1102 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1103 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice::
# 1104 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceRight
# 1105 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1106 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
# 1107 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 1108 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 0, PalletTown_ProfessorOaksLab_EventScript_ConfirmBulbasaur
# 1109 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 1, PalletTown_ProfessorOaksLab_EventScript_ConfirmSquirtle
# 1110 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmCharmander
# 1111 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1112 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1113 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmBulbasaur::
# 1114 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingBulbasaur, MSGBOX_YESNO
# 1115 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1116 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1117 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1118 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1119 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmSquirtle::
# 1120 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingSquirtle, MSGBOX_YESNO
# 1121 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1122 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1123 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1124 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1125 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmCharmander::
# 1126 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingCharmander, MSGBOX_YESNO
# 1127 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1128 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1129 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1130 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1131 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter::
# 1132 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	hidemonpic
# 1133 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1134 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1135 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1136 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ChoseStarter::
# 1137 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	hidemonpic
# 1138 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1139 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakThisMonIsEnergetic
# 1140 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 1141 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1142 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_PALLET_LADY_NOT_BLOCKING_SIGN
# 1143 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	givemon PLAYER_STARTER_SPECIES, 5
# 1144 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_STARTER_MON, PLAYER_STARTER_NUM
# 1145 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
# 1146 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_ReceivedMonFromOak
# 1147 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 1148 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 1149 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 1150 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 1151 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, EventScript_GiveNicknameToStarter
# 1152 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_RivalPicksStarter
# 1153 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1154 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1155 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
EventScript_GiveNicknameToStarter::
# 1156 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_0x8004, 0
# 1157 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_RIVAL_HOUSE_BLUE_MOM, 2
# 1158 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
# 1159 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_ChangePokemonNickname
# 1160 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1161 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1162 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalPicksStarter::
# 1163 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 1164 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 0, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToCharmander
# 1165 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 1, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToBulbasaur
# 1166 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 2, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToSquirtle
# 1167 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1168 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1169 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToCharmander::
# 1170 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalWalksToCharmander
# 1171 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1172 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1173 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1174 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1175 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToSquirtle::
# 1176 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalWalksToSquirtle
# 1177 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1178 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1179 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1180 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1181 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToBulbasaur::
# 1182 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalWalksToBulbasaur
# 1183 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1184 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1185 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1186 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1187 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter::
# 1188 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 1189 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalIllTakeThisOneThen
# 1190 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject RIVAL_STARTER_ID
# 1191 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 1192 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	bufferspeciesname STR_VAR_1, RIVAL_STARTER_SPECIES
# 1193 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_RivalReceivedMonFromOak
# 1194 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 1195 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 1196 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 1197 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3
# 1198 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_set FLAG_OPENED_START_MENU, PalletTown_ProfessorOaksLab_EventScript_ReadyEndSignLadyScene
# 1199 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1200 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1201 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1202 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyEndSignLadyScene::
# 1203 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 1204 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1205 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1206 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToCharmander::
# 1207 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1208 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1209 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1210 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1211 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1212 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1213 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1214 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1215 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1216 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1217 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToSquirtle::
# 1218 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1219 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1220 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1221 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1222 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1223 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 1224 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1225 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1226 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToBulbasaur::
# 1227 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1228 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1229 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1230 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 1231 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 1232 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1233 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1234 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SquirtleBall::
# 1235 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1236 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1237 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 1
# 1238 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_SQUIRTLE
# 1239 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_BULBASAUR
# 1240 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_BULBASAUR_BALL
# 1241 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1242 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1243 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1244 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1245 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1246 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1247 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_CharmanderBall::
# 1248 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1249 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1250 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 2
# 1251 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHARMANDER
# 1252 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_SQUIRTLE
# 1253 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_SQUIRTLE_BALL
# 1254 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1255 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1256 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1257 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1258 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1259 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1260 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LastPokeBall::
# 1261 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OaksLastMon
# 1262 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1263 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1264 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1265 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide1::
# 1266 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1267 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1268 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_Aide1GameClear
# 1269 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide
# 1270 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1271 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1272 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1273 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide1GameClear::
# 1274 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 5
# 1275 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakIsGoingToHaveRadioShow
# 1276 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1277 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1278 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1279 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide2::
# 1280 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1281 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1282 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_Aide2GameClear
# 1283 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide
# 1284 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1285 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1286 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1287 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide2GameClear::
# 1288 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_DAISY, 0
# 1289 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_DaisyWillGroomMons
# 1290 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1291 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1292 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1293 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide3::
# 1294 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1295 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1296 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 2
# 1297 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakIsAuthorityOnMons
# 1298 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1299 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1300 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1301 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Pokedex::
# 1302 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia, MSGBOX_NPC
# 1303 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1304 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1305 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Computer::
# 1306 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_EmailMessage, MSGBOX_SIGN
# 1307 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1308 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1309 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LeftSign::
# 1310 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_PressStartToOpenMenu, MSGBOX_SIGN
# 1311 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1312 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1313 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RightSign::
# 1314 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 1315 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, PalletTown_ProfessorOaksLab_EventScript_RightSignAlt
# 1316 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_SaveOptionInMenu
# 1317 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 1318 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1319 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1320 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RightSignAlt::
# 1321 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints
# 1322 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 1323 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
