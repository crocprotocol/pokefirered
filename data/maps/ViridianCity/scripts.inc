# 1 "data/maps/ViridianCity/scripts.pory"

# 2 "data/maps/ViridianCity/scripts.pory"
.set LOCALID_OLD_MAN,      3
# 3 "data/maps/ViridianCity/scripts.pory"
.set LOCALID_TUTORIAL_MAN, 4
# 4 "data/maps/ViridianCity/scripts.pory"
.set LOCALID_WOMAN,        5
# 5 "data/maps/ViridianCity/scripts.pory"
.set LOCALID_POLICEMAN,    10
# 6 "data/maps/ViridianCity/scripts.pory"

# 7 "data/maps/ViridianCity/scripts.pory"
ViridianCity_MapScripts::
# 8 "data/maps/ViridianCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
# 9 "data/maps/ViridianCity/scripts.pory"
	.byte 0
# 10 "data/maps/ViridianCity/scripts.pory"

# 11 "data/maps/ViridianCity/scripts.pory"
ViridianCity_OnTransition::
# 12 "data/maps/ViridianCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
# 13 "data/maps/ViridianCity/scripts.pory"
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_SetOldManBlockingRoad
# 14 "data/maps/ViridianCity/scripts.pory"
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_SetOldManStandingByRoad
# 15 "data/maps/ViridianCity/scripts.pory"
	call_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_SetOldManNormal
# 16 "data/maps/ViridianCity/scripts.pory"
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 0, ViridianCity_EventScript_TryUnlockGym
# 17 "data/maps/ViridianCity/scripts.pory"
	end
# 18 "data/maps/ViridianCity/scripts.pory"

# 19 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_SetOldManNormal::
# 20 "data/maps/ViridianCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
# 21 "data/maps/ViridianCity/scripts.pory"
	return
# 22 "data/maps/ViridianCity/scripts.pory"

# 23 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_SetOldManStandingByRoad::
# 24 "data/maps/ViridianCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
# 25 "data/maps/ViridianCity/scripts.pory"
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 8
# 26 "data/maps/ViridianCity/scripts.pory"
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_LOOK_AROUND
# 27 "data/maps/ViridianCity/scripts.pory"
	return
# 28 "data/maps/ViridianCity/scripts.pory"

# 29 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_SetOldManBlockingRoad::
# 30 "data/maps/ViridianCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_PIKACHU
# 31 "data/maps/ViridianCity/scripts.pory"
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 11
# 32 "data/maps/ViridianCity/scripts.pory"
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_FACE_DOWN
# 33 "data/maps/ViridianCity/scripts.pory"
	return
# 34 "data/maps/ViridianCity/scripts.pory"

# 35 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TryUnlockGym::
# 36 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE02_GET, EventScript_Return
# 37 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, EventScript_Return
# 38 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE04_GET, EventScript_Return
# 39 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE05_GET, EventScript_Return
# 40 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, EventScript_Return
# 41 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE07_GET, EventScript_Return
# 42 "data/maps/ViridianCity/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
# 43 "data/maps/ViridianCity/scripts.pory"
	return
# 44 "data/maps/ViridianCity/scripts.pory"

# 45 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_GymDoorLocked::
# 46 "data/maps/ViridianCity/scripts.pory"
	lockall
# 47 "data/maps/ViridianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 48 "data/maps/ViridianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 49 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 50 "data/maps/ViridianCity/scripts.pory"
	delay 20
# 51 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GymDoorsAreLocked
# 52 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 53 "data/maps/ViridianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_JumpDownLedge
# 54 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 55 "data/maps/ViridianCity/scripts.pory"
	releaseall
# 56 "data/maps/ViridianCity/scripts.pory"
	end
# 57 "data/maps/ViridianCity/scripts.pory"

# 58 "data/maps/ViridianCity/scripts.pory"
ViridianCity_Movement_JumpDownLedge::
# 59 "data/maps/ViridianCity/scripts.pory"
	jump_2_down
# 60 "data/maps/ViridianCity/scripts.pory"
	step_end
# 61 "data/maps/ViridianCity/scripts.pory"

# 62 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_CitySign::
# 63 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
# 64 "data/maps/ViridianCity/scripts.pory"
	end
# 65 "data/maps/ViridianCity/scripts.pory"

# 66 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TrainerTips1::
# 67 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
# 68 "data/maps/ViridianCity/scripts.pory"
	end
# 69 "data/maps/ViridianCity/scripts.pory"

# 70 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TrainerTips2::
# 71 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
# 72 "data/maps/ViridianCity/scripts.pory"
	end
# 73 "data/maps/ViridianCity/scripts.pory"

# 74 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_GymSign::
# 75 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
# 76 "data/maps/ViridianCity/scripts.pory"
	end
# 77 "data/maps/ViridianCity/scripts.pory"

# 78 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_GymDoor::
# 79 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_SIGN
# 80 "data/maps/ViridianCity/scripts.pory"
	end
# 81 "data/maps/ViridianCity/scripts.pory"

# 82 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_Boy::
# 83 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_NPC
# 84 "data/maps/ViridianCity/scripts.pory"
	end
# 85 "data/maps/ViridianCity/scripts.pory"

# 86 "data/maps/ViridianCity/scripts.pory"
@ Other old man, not the tutorial old man
# 87 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_OldMan::
# 88 "data/maps/ViridianCity/scripts.pory"
	lock
# 89 "data/maps/ViridianCity/scripts.pory"
	faceplayer
# 90 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1, ViridianCity_EventScript_OldManGymLeaderReturned
# 91 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs
# 92 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 93 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_OLD_MAN, Common_Movement_FaceOriginalDirection
# 94 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 95 "data/maps/ViridianCity/scripts.pory"
	release
# 96 "data/maps/ViridianCity/scripts.pory"
	end
# 97 "data/maps/ViridianCity/scripts.pory"

# 98 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_OldManGymLeaderReturned::
# 99 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned
# 100 "data/maps/ViridianCity/scripts.pory"
	release
# 101 "data/maps/ViridianCity/scripts.pory"
	end
# 102 "data/maps/ViridianCity/scripts.pory"

# 103 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialOldMan::
# 104 "data/maps/ViridianCity/scripts.pory"
	lock
# 105 "data/maps/ViridianCity/scripts.pory"
	faceplayer
# 106 "data/maps/ViridianCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, ViridianCity_EventScript_AskIfTeachyTVHelpful
# 107 "data/maps/ViridianCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_TutorialCompleted
# 108 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_TutorialStart
# 109 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_TutorialNotReady
# 110 "data/maps/ViridianCity/scripts.pory"
	end
# 111 "data/maps/ViridianCity/scripts.pory"

# 112 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_AskIfTeachyTVHelpful::
# 113 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_HowsTeachyTVHelping, MSGBOX_YESNO
# 114 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_TeachyTVNotHelpful
# 115 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_MyGrandsonOnTheShow
# 116 "data/maps/ViridianCity/scripts.pory"
	release
# 117 "data/maps/ViridianCity/scripts.pory"
	end
# 118 "data/maps/ViridianCity/scripts.pory"

# 119 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TeachyTVNotHelpful::
# 120 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_TooBusyForTeachyTV
# 121 "data/maps/ViridianCity/scripts.pory"
	release
# 122 "data/maps/ViridianCity/scripts.pory"
	end
# 123 "data/maps/ViridianCity/scripts.pory"

# 124 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialCompleted::
# 125 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_WeakenMonsFirstToCatch
# 126 "data/maps/ViridianCity/scripts.pory"
	release
# 127 "data/maps/ViridianCity/scripts.pory"
	end
# 128 "data/maps/ViridianCity/scripts.pory"

# 129 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialStart::
# 130 "data/maps/ViridianCity/scripts.pory"
	call ViridianCity_EventScript_DoTutorialBattle
# 131 "data/maps/ViridianCity/scripts.pory"
	release
# 132 "data/maps/ViridianCity/scripts.pory"
	end
# 133 "data/maps/ViridianCity/scripts.pory"

# 134 "data/maps/ViridianCity/scripts.pory"
@ Unused
# 135 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_WatchToLearnBasics::
# 136 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_WatchThatToLearnBasics
# 137 "data/maps/ViridianCity/scripts.pory"
	release
# 138 "data/maps/ViridianCity/scripts.pory"
	end
# 139 "data/maps/ViridianCity/scripts.pory"

# 140 "data/maps/ViridianCity/scripts.pory"
@ Unused. Starts battle after the post battle text, which is odd.
# 141 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialUnused::
# 142 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
# 143 "data/maps/ViridianCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 144 "data/maps/ViridianCity/scripts.pory"
	special QuestLog_CutRecording
# 145 "data/maps/ViridianCity/scripts.pory"
	special StartOldManTutorialBattle
# 146 "data/maps/ViridianCity/scripts.pory"
	waitstate
# 147 "data/maps/ViridianCity/scripts.pory"
	release
# 148 "data/maps/ViridianCity/scripts.pory"
	end
# 149 "data/maps/ViridianCity/scripts.pory"

# 150 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialNotReady::
# 151 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ThisIsPrivateProperty
# 152 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 153 "data/maps/ViridianCity/scripts.pory"
	release
# 154 "data/maps/ViridianCity/scripts.pory"
	end
# 155 "data/maps/ViridianCity/scripts.pory"

# 156 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_Youngster::
# 157 "data/maps/ViridianCity/scripts.pory"
	lock
# 158 "data/maps/ViridianCity/scripts.pory"
	faceplayer
# 159 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
# 160 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, ViridianCity_EventScript_YoungsterExplainCaterpillars
# 161 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_YoungsterDeclineExplanation
# 162 "data/maps/ViridianCity/scripts.pory"
	end
# 163 "data/maps/ViridianCity/scripts.pory"

# 164 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_YoungsterExplainCaterpillars::
# 165 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ExplainCaterpieWeedle
# 166 "data/maps/ViridianCity/scripts.pory"
	release
# 167 "data/maps/ViridianCity/scripts.pory"
	end
# 168 "data/maps/ViridianCity/scripts.pory"

# 169 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_YoungsterDeclineExplanation::
# 170 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_OhOkayThen
# 171 "data/maps/ViridianCity/scripts.pory"
	release
# 172 "data/maps/ViridianCity/scripts.pory"
	end
# 173 "data/maps/ViridianCity/scripts.pory"

# 174 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_Woman::
# 175 "data/maps/ViridianCity/scripts.pory"
	lock
# 176 "data/maps/ViridianCity/scripts.pory"
	faceplayer
# 177 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_WomanRoadBlocked
# 178 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally
# 179 "data/maps/ViridianCity/scripts.pory"
	release
# 180 "data/maps/ViridianCity/scripts.pory"
	end
# 181 "data/maps/ViridianCity/scripts.pory"

# 182 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_WomanRoadBlocked::
# 183 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GrandpaHasntHadCoffeeYet
# 184 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 185 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_WOMAN, Common_Movement_FaceOriginalDirection
# 186 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 187 "data/maps/ViridianCity/scripts.pory"
	release
# 188 "data/maps/ViridianCity/scripts.pory"
	end
# 189 "data/maps/ViridianCity/scripts.pory"

# 190 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_DreamEaterTutor::
# 191 "data/maps/ViridianCity/scripts.pory"
	goto EventScript_DreamEaterTutor
# 192 "data/maps/ViridianCity/scripts.pory"
	end
# 193 "data/maps/ViridianCity/scripts.pory"

# 194 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_RoadBlocked::
# 195 "data/maps/ViridianCity/scripts.pory"
	lockall
# 196 "data/maps/ViridianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 197 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ThisIsPrivateProperty
# 198 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 199 "data/maps/ViridianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, ViridianCity_Movement_WalkDown
# 200 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 201 "data/maps/ViridianCity/scripts.pory"
	releaseall
# 202 "data/maps/ViridianCity/scripts.pory"
	end
# 203 "data/maps/ViridianCity/scripts.pory"

# 204 "data/maps/ViridianCity/scripts.pory"
ViridianCity_Movement_WalkDown::
# 205 "data/maps/ViridianCity/scripts.pory"
	walk_down
# 206 "data/maps/ViridianCity/scripts.pory"
	step_end
# 207 "data/maps/ViridianCity/scripts.pory"

# 208 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialTriggerLeft::
# 209 "data/maps/ViridianCity/scripts.pory"
	lockall
# 210 "data/maps/ViridianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 211 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterLeft
# 212 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 213 "data/maps/ViridianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 214 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 215 "data/maps/ViridianCity/scripts.pory"
	call ViridianCity_EventScript_DoTutorialBattle
# 216 "data/maps/ViridianCity/scripts.pory"
	release
# 217 "data/maps/ViridianCity/scripts.pory"
	end
# 218 "data/maps/ViridianCity/scripts.pory"

# 219 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialTriggerRight::
# 220 "data/maps/ViridianCity/scripts.pory"
	lockall
# 221 "data/maps/ViridianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 222 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
# 223 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 224 "data/maps/ViridianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 225 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 226 "data/maps/ViridianCity/scripts.pory"
	call ViridianCity_EventScript_DoTutorialBattle
# 227 "data/maps/ViridianCity/scripts.pory"
	release
# 228 "data/maps/ViridianCity/scripts.pory"
	end
# 229 "data/maps/ViridianCity/scripts.pory"

# 230 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_DoTutorialBattle::
# 231 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ShowYouHowToCatchMons
# 232 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 233 "data/maps/ViridianCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 234 "data/maps/ViridianCity/scripts.pory"
	special QuestLog_CutRecording
# 235 "data/maps/ViridianCity/scripts.pory"
	special StartOldManTutorialBattle
# 236 "data/maps/ViridianCity/scripts.pory"
	waitstate
# 237 "data/maps/ViridianCity/scripts.pory"
	lock
# 238 "data/maps/ViridianCity/scripts.pory"
	faceplayer
# 239 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
# 240 "data/maps/ViridianCity/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
# 241 "data/maps/ViridianCity/scripts.pory"
	giveitem ITEM_TEACHY_TV
# 242 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_WatchThatToLearnBasics
# 243 "data/maps/ViridianCity/scripts.pory"
	return

ViridianCity_EventScript_PoliceMan::
# 247 "data/maps/ViridianCity/scripts.pory"
	lock
# 248 "data/maps/ViridianCity/scripts.pory"
	faceplayer
# 249 "data/maps/ViridianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 250 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_EventScript_PoliceMan_Text_0
# 251 "data/maps/ViridianCity/scripts.pory"
	waitmessage
# 252 "data/maps/ViridianCity/scripts.pory"
	applymovement 10, PoliceManFaceLeft
# 253 "data/maps/ViridianCity/scripts.pory"
	waitmovement 10
# 254 "data/maps/ViridianCity/scripts.pory"
	release
	end


ViridianCity_EventScript_PoliceManTrigger::
# 259 "data/maps/ViridianCity/scripts.pory"
	lock
# 260 "data/maps/ViridianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 261 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_EventScript_PoliceMan_Text_0
# 262 "data/maps/ViridianCity/scripts.pory"
	waitmessage
# 263 "data/maps/ViridianCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkDown
# 264 "data/maps/ViridianCity/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 265 "data/maps/ViridianCity/scripts.pory"
	release
	end


# 269 "data/maps/ViridianCity/scripts.pory"
PlayerWalkDown:
# 270 "data/maps/ViridianCity/scripts.pory"
	walk_down
# 271 "data/maps/ViridianCity/scripts.pory"
	step_end

# 274 "data/maps/ViridianCity/scripts.pory"
PoliceManFaceLeft:
# 275 "data/maps/ViridianCity/scripts.pory"
	face_left
	step_end

ViridianCity_EventScript_PoliceMan_Text_0:
# 250 "data/maps/ViridianCity/scripts.pory"
	.string "cant let you do that starfox$"
