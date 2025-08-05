# 1 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"

# 2 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
PalletTown_PlayersHouse_2F_MapScripts::
# 3 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
# 4 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
# 5 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.byte 0
# 6 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"

# 7 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
PalletTown_PlayersHouse_2F_OnTransition::
# 8 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_EventScript_SetRespawn
# 9 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	end
# 10 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"

# 11 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
PalletTown_PlayersHouse_2F_EventScript_SetRespawn::
# 12 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setrespawn SPAWN_PALLET_TOWN
# 13 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	return
# 14 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"

# 15 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
PalletTown_PlayersHouse_2F_OnWarp::
# 16 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
# 17 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.2byte 0
# 18 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"

# 19 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
PalletTown_PlayersHouse_2F_FirstWarpIn::
# 20 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 21 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 1
# 22 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	end
# 23 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"

# 24 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
PalletTown_PlayersHouse_2F_EventScript_NES::
# 25 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
# 26 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	end
# 27 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"

# 28 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
PalletTown_PlayersHouse_2F_EventScript_Sign::
# 29 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_Text_PressLRForHelp, MSGBOX_SIGN
# 30 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	end
# 31 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"

# 32 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
PalletTown_PlayersHouse_2F_EventScript_PC::
# 33 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 34 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	lockall
# 35 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8004, HELPCONTEXT_BEDROOM_PC
# 36 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	special Script_SetHelpContext
# 37 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8004, 1
# 38 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	special AnimatePcTurnOn
# 39 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	playse SE_PC_ON
# 40 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox Text_PlayerBootedUpPC
# 41 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	special BedroomPC
# 42 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 43 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	special SetHelpContextForMap
# 44 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	releaseall
# 45 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	end
# 46 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"

# 47 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
EventScript_PalletTown_PlayersHouse_2F_ShutDownPC::
# 48 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8004, 1
# 49 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	playse SE_PC_OFF
# 50 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	special AnimatePcTurnOff
# 51 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	special SetHelpContextForMap
# 52 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	releaseall
# 53 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	end

PalletTown_PlayersHouse_2F_EventScript_Bookshelf1::
# 56 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	lock
# 57 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_EventScript_Bookshelf1_Text_0
# 58 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	release
	end


PalletTown_PlayersHouse_2F_EventScript_Bookshelf2::
# 63 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	lock
# 64 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_EventScript_Bookshelf2_Text_0
# 65 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	release
	end


PalletTown_PlayersHouse_2F_EventScript_MewSketch::
# 70 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	lock
# 71 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	showmonpic SPECIES_MEWTHREE, 10, 3
# 72 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_EventScript_MewSketch_Text_0
# 73 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	waitmessage
# 74 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	hidemonpic
# 75 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	release
	end


PalletTown_PlayersHouse_2F_EventScript_BirthdayPlush::
# 80 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	lock
# 81 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_EventScript_BirthdayPlush_Text_0
# 82 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	release
	end


PalletTown_PlayersHouse_2F_EventScript_KantoMap::
# 87 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	lock
# 88 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_EventScript_KantoMap_Text_0
# 89 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	release
	end


PalletTown_PlayersHouse_2F_EventScript_MomTrigger::
# 94 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	compare VAR_MAP_SCENE_PLAYERHOUSE_2F, 0
	goto_if_eq PalletTown_PlayersHouse_2F_EventScript_MomTrigger_1
# 104 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	lock
# 105 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	release
	end

PalletTown_PlayersHouse_2F_EventScript_MomTrigger_1:
# 95 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	lock
# 96 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	call PalletTown_PlayersHouse_2F_EventScript_MomShake
# 97 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 98 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	msgbox PalletTown_PlayersHouse_2F_EventScript_MomTrigger_Text_0
# 99 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	call PalletTown_PlayersHouse_2F_EventScript_MomShake
# 100 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	delay 60
# 101 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	release
	end


PalletTown_PlayersHouse_2F_EventScript_MomShake::
# 111 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	delay 30
# 112 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8004, 2
# 113 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8005, 6
# 114 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8006, 4
# 115 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x8007, 4
# 116 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	special ShakeScreen
# 117 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	waitstate
# 118 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_MAP_SCENE_PLAYERHOUSE_2F, 1
# 119 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	setvar VAR_0x4100, 1
	return


PalletTown_PlayersHouse_2F_EventScript_Bookshelf1_Text_0:
# 57 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "There is a book on wool upkeep.$"

PalletTown_PlayersHouse_2F_EventScript_Bookshelf2_Text_0:
# 64 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "The entire shelf is filled with\n"
	.string "encylopedias about POKéMON.$"

PalletTown_PlayersHouse_2F_EventScript_MewSketch_Text_0:
# 72 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "An old picture.\n"
	.string "...\l"
	.string "...\l"
	.string "You don't remember when you drew it.$"

PalletTown_PlayersHouse_2F_EventScript_BirthdayPlush_Text_0:
# 81 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "Happy birthday Blue!\l--Gramps$"

PalletTown_PlayersHouse_2F_EventScript_KantoMap_Text_0:
# 88 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "Your eyes are drawn to a bright red\n"
	.string "circle surrounding LAVENDER TOWN.$"

PalletTown_PlayersHouse_2F_EventScript_MomTrigger_Text_0:
# 98 "data/maps/PalletTown_PlayersHouse_2F/scripts.pory"
	.string "BLUE!!!!$"
