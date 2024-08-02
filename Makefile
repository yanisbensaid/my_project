##
## EPITECH PROJECT, 2023
## makefile
## File description:
## csfml
##

NAME	=	my_rpg

SRCS	=	src/main.c 									\
			src/gestion_windows_menu.c					\
			src/gestion_windows_adv.c					\
			src/init_sprite_menu.c						\
			src/map.c 									\
			src/player/player.c							\
			src/player/player_mouve.c					\
			src/player/animation_player.c				\
			src/gestion_overlay.c						\
			src/exit_and_cross_overlay.c 				\
			src/song.c 									\
			src/save_overlay.c 							\
			src/sound_overlay.c 						\
			src/volume_barre.c 							\
			src/player_s.c								\
			src/player_q.c 								\
			src/player_z.c 								\
			src/player_d.c 								\
			src/life_player.c 							\
			src/parsingpos.c 							\
			src/parsing_follow.c 						\
			src/game_over.c 							\
			src/inventory.c 							\
			src/click_on_inventory.c 					\
			src/combat/lancer_combat.c					\
			src/combat/create_sprite_player_and_enemi.c	\
			src/combat/sprite_menu.c					\
			src/combat/attack_button.c					\
			src/combat/attack_detected.c				\
			src/combat/click_on_menbre.c				\
			src/combat/enemi_sprite_modif.c				\
			src/combat/is_colision.c					\
			src/donjon_one.c							\
			src/pnj_one.c 								\
			src/create_sword.c							\
			src/donjon_two.c							\
			src/map_follow.c 							\
			src/create_sprite.c 						\
			src/draw_button.c 							\
			src/calculate_pos.c 						\
			src/click_on_cross_inv.c 					\
			src/pnj_villageois.c 						\
			src/interact_with_object.c 					\
			src/disp_player.c 							\
			src/parse_collisions.c 						\
			src/move_player_in_donjon.c 				\
			src/combat/init_parameter_fight.c			\
			src/pnj_draven.c 							\
			src/win_the_first_room.c 					\
			src/interact_object_donjon_one.c 			\
			src/combat/fight_donjon_two.c 				\
			src/parsing_three.c 						\
			src/end_game.c 								\

OBJS	=	$(SRCS:.c=.o)

CFLAGS = -g3 -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CPPFLAGS = -I./includes -lcsfml-graphics

$(NAME):	$(OBJS)
	gcc -o $(NAME) $(OBJS) $(CPPFLAGS) $(CFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
