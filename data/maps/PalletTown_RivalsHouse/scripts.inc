# 1 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 2 "data/maps/PalletTown_RivalsHouse/scripts.pory"
.equ LOCALID_DAISY,    1
# 3 "data/maps/PalletTown_RivalsHouse/scripts.pory"
.equ LOCALID_TOWN_MAP, 2
# 4 "data/maps/PalletTown_RivalsHouse/scripts.pory"
.equ LOCALID_MOM,      3
# 5 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 6 "data/maps/PalletTown_RivalsHouse/scripts.pory"
.equ RECEIVED_TOWN_MAP, VAR_TEMP_1
# 7 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 8 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_MapScripts::
# 9 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
# 10 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, PalletTown_RivalsHouse_OnLoad
# 11 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.byte 0
# 12 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 13 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_OnTransition::
# 14 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
# 15 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
# 16 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 17 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 18 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
# 19 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
# 20 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setobjectxyperm LOCALID_DAISY, 5, 4
# 21 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	return
# 22 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 23 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap::
# 24 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setvar RECEIVED_TOWN_MAP, TRUE
# 25 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	return
# 26 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 27 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_Daisy::
# 28 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	lock
# 29 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	faceplayer
# 30 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 31 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
# 32 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq RECEIVED_TOWN_MAP, TRUE, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
# 33 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_ExplainTownMap
# 34 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_GiveTownMap
# 35 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_RivalsHouse_EventScript_HeardBattledRival
# 36 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
# 37 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	closemessage
# 38 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
# 39 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 40 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 41 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 42 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 43 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_HeardBattledRival::
# 44 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
# 45 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 46 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 47 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 48 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_GroomMon::
# 49 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 50 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special QuestLog_CutRecording
# 51 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
# 52 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
# 53 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
# 54 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
# 55 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special ChoosePartyMon
# 56 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitstate
# 57 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	lock
# 58 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	faceplayer
# 59 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
# 60 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	specialvar VAR_RESULT, GetPartyMonSpecies
# 61 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
# 62 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
# 63 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	closemessage
# 64 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 65 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	playfanfare MUS_HEAL
# 66 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitfanfare
# 67 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special DaisyMassageServices
# 68 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 69 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special BufferMonNickname
# 70 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
# 71 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 72 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 73 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 74 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_CantGroomEgg::
# 75 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
# 76 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 77 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 78 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 79 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_DeclineGrooming::
# 80 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
# 81 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 82 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 83 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 84 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_RateMonFriendship::
# 85 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
# 86 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	specialvar VAR_RESULT, GetLeadMonFriendship
# 87 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	switch VAR_RESULT
# 88 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
# 89 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
# 90 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
# 91 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
# 92 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
# 93 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
# 94 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
# 95 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 96 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 97 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
# 98 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
# 99 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 100 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 101 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 102 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
# 103 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
# 104 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 105 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 106 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 107 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
# 108 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
# 109 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 110 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 111 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 112 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
# 113 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
# 114 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 115 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 116 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 117 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
# 118 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
# 119 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 120 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 121 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 122 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
# 123 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
# 124 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 125 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 126 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 127 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
# 128 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
# 129 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 130 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 131 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 132 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
# 133 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
# 134 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 135 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 136 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 137 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_GiveTownMap::
# 138 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp
# 139 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	closemessage
# 140 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	checkitemspace ITEM_TOWN_MAP
# 141 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
# 142 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
# 143 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 144 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	removeobject LOCALID_TOWN_MAP
# 145 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
# 146 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	delay 15
# 147 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
# 148 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 149 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	delay 12
# 150 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_OBTAIN_KEY_ITEM
# 151 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 152 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 153 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 154 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_NoRoomForTownMap::
# 155 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
# 156 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 157 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 158 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 159 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_ExplainTownMap::
# 160 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
# 161 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 162 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 163 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 164 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_TownMap::
# 165 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
# 166 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 167 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 168 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_Bookshelf::
# 169 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
# 170 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 171 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 172 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_Picture::
# 173 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
# 174 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end

PalletTown_RivalsHouse_EventScript_Mother::
# 177 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	lock
# 178 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	faceplayer
# 179 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	compare VAR_MAP_SCENE_RIVAL_HOUSE_BLUE_MOM, 0
	goto_if_eq PalletTown_RivalsHouse_EventScript_Mother_1
# 184 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	compare VAR_MAP_SCENE_RIVAL_HOUSE_BLUE_MOM, 1
	goto_if_eq PalletTown_RivalsHouse_EventScript_Mother_2
	return

PalletTown_RivalsHouse_EventScript_Mother_1:
# 180 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_EventScript_Mother_Text_0
# 181 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
	end

PalletTown_RivalsHouse_EventScript_Mother_2:
# 185 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_EventScript_Mother_Text_1
# 186 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_EventScript_Mother_Text_2
# 187 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
	end


PalletTown_RivalsHouse_EventScript_MoveMom::
# 193 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setobjectxyperm LOCALID_MOM, 9, 2
# 194 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_RIGHT
	return


PalletTown_RivalsHouse_EventScript_MomLecture::
# 199 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	compare VAR_0x4100, 1
	goto_if_eq PalletTown_RivalsHouse_EventScript_MomLecture_1
	return

PalletTown_RivalsHouse_EventScript_MomLecture_1:
# 200 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	lock
# 201 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 202 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_EventScript_MomLecture_Text_0
# 203 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_EventScript_MomLecture_Text_1
# 204 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_EventScript_MomLecture_Text_2
# 205 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_EventScript_MomLecture_Text_3
# 206 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_EventScript_MomLecture_Text_4
# 207 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement 3, MomGiveMovement
# 208 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 209 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 210 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	giveitem_msg PalletTown_RivalsHouse_EventScript_MomLecture_Text_5, ITEM_OAKS_PARCEL
# 211 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setvar VAR_0x4100, 2
# 212 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setvar VAR_MAP_SCENE_RIVAL_HOUSE_BLUE_MOM, 1
# 213 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
	end


PalletTown_RivalsHouse_OnLoad::
# 219 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	compare VAR_0x4100, 1
	goto_if_eq PalletTown_RivalsHouse_OnLoad_1
	return

PalletTown_RivalsHouse_OnLoad_1:
# 220 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	call PalletTown_RivalsHouse_EventScript_MoveMom
	return


# 224 "data/maps/PalletTown_RivalsHouse/scripts.pory"
MomGiveMovement:
# 225 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	walk_down
# 226 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	face_right
	step_end

PalletTown_RivalsHouse_EventScript_Mother_Text_0:
# 180 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.string "...$"

PalletTown_RivalsHouse_EventScript_Mother_Text_1:
# 185 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.string "Did you find your pet?$"

PalletTown_RivalsHouse_EventScript_Mother_Text_2:
# 186 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.string "I don't want a repeat of last time...$"

PalletTown_RivalsHouse_EventScript_MomLecture_Text_0:
# 202 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.string "You forgot this.$"

PalletTown_RivalsHouse_EventScript_MomLecture_Text_1:
# 203 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.string "I told you about it a hundred times.$"

PalletTown_RivalsHouse_EventScript_MomLecture_Text_2:
# 204 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.string "This is exactly why I don't trust you\n"
	.string "to be in Saffron City on your own!$"

PalletTown_RivalsHouse_EventScript_MomLecture_Text_3:
# 205 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.string "You need to be more responsible or\n"
	.string "you'll never amount to anything!$"

PalletTown_RivalsHouse_EventScript_MomLecture_Text_4:
# 206 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.string "Please don't forget to give this to\n"
	.string "gramps, at least.$"

PalletTown_RivalsHouse_EventScript_MomLecture_Text_5:
# 210 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.string "{PLAYER} received OAK'S PARCEL from\n"
	.string "MOM.$"
