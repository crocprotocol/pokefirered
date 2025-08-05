# 1 "data/maps/PalletTown_ChaosRoom/scripts.pory"

# 2 "data/maps/PalletTown_ChaosRoom/scripts.pory"
PalletTown_ChaosRoom_MapScripts::
# 3 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	.byte 0

PalletTown_ChaosRoom_EventScript_Ghost::
# 7 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	lock
# 8 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	playse SE_LISA
# 9 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	release
	end


PalletTown_ChaosRoom_EventScript_Ghost2::
# 14 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	lock
# 15 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	playse SE_LISA_2
# 16 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	release
	end


PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic::
# 21 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	lock
# 22 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	message PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_Text_0
# 23 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	multichoice 25, 5, MULTICHOICE_MUSIC_BOX, 0
# 24 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	closemessage
# 25 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_2
# 28 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_3
# 31 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_4
# 34 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_5
PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_1:
# 37 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	release
	end

PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_2:
# 26 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	playbgm MUS_CELADON, 0
	goto PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_1

PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_3:
# 29 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	playbgm MUS_DESERT_STORM, 0
	goto PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_1

PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_4:
# 32 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	playbgm MUS_MIDNAS_THEME, 0
	goto PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_1

PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_5:
# 35 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	playbgm MUS_LEGEND_DRAGON, 0
	goto PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_1


PalletTown_ChaosRoom_EventScript_SoundwavePlayMusic_Text_0:
# 22 "data/maps/PalletTown_ChaosRoom/scripts.pory"
	.string "What do you want to hear?$"
