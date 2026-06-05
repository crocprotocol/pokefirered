# 1 "data/maps/OakHouse/scripts.pory"

# 2 "data/maps/OakHouse/scripts.pory"
OakHouse_MapScripts::
# 3 "data/maps/OakHouse/scripts.pory"
	.byte 0

OakHouse_EventScript_Agatha::
# 6 "data/maps/OakHouse/scripts.pory"
	lock
# 7 "data/maps/OakHouse/scripts.pory"
	faceplayer
# 8 "data/maps/OakHouse/scripts.pory"
	compare VAR_MAP_SCENE_OAK_HOUSE_AGATHA, 0
	goto_if_eq OakHouse_EventScript_Agatha_1
	return

OakHouse_EventScript_Agatha_1:
# 9 "data/maps/OakHouse/scripts.pory"
	msgbox OakHouse_EventScript_Agatha_Text_0
# 10 "data/maps/OakHouse/scripts.pory"
	msgbox OakHouse_EventScript_Agatha_Text_1
# 11 "data/maps/OakHouse/scripts.pory"
	msgbox OakHouse_EventScript_Agatha_Text_2
# 12 "data/maps/OakHouse/scripts.pory"
	release
	end


OakHouse_EventScript_Agatha_Text_0:
# 9 "data/maps/OakHouse/scripts.pory"
	.string "Oh, hello {PLAYER}.$"

OakHouse_EventScript_Agatha_Text_1:
# 10 "data/maps/OakHouse/scripts.pory"
	.string "There are some things in the basement\n"
	.string "I'd like you to take back to your\l"
	.string "mother.$"

OakHouse_EventScript_Agatha_Text_2:
# 11 "data/maps/OakHouse/scripts.pory"
	.string "Can you at least handle that?$"
