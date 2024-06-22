##
## EPITECH PROJECT, 2024
## for
## File description:
## rpg
##

SRC	=	./src/my_rpg.c				\
		./src/main.c 				\
		./src/duplicate_string.c	\
		./src/init_game_status.c	\
		./src/check_event_type.c	\
		./src/set_scene.c			\
		./src/set_sprite_and_texture.c		\
		./src/set_position_size.c	\
		./src/init_start_scene.c	\
		./src/is_hover_button.c		\
		./src/set_state_button.c	\
		./src/close_win.c			\
		./src/player_move.c			\
		./src/load_start_scene.c	\
		./src/init_menu.c			\
		./src/init_button.c			\
		./src/init_player.c			\
		./src/set_previous_state.c	\
		./src/display_menu.c		\
		./src/button_management.c	\
		./src/return_back_state.c	\
		./src/start_fight.c			\
		./src/time.c				\
		./src/level1.c				\
		./src/manage_actions.c		\
		./src/verif_save.c			\
		./src/save_game.c			\
		./src/free_button.c			\
		./src/resize_win.c			\
		./src/display_volume.c		\
		./src/display_size_win.c	\
		./src/display_command_list.c	\
		./src/draw_text.c	\
		./src/shield_management.c	\
		./src/apple_management.c	\
		./src/bag_management.c	\
		./src/bread_management.c	\
		./src/meat_management.c	\
		./src/armor_management.c	\
		./src/display_stat.c	\
		./src/speed_potion.c	\
		./src/skull_management.c	\
		./src/manage_volume.c		\
		./src/set_language.c		\
		./src/sounds_manage.c		\
		./src/fight_animation/fight_player_animation.c	\
		./src/fight_animation/fight_death_bringer.c	\
		./src/my_grep.c				\
		./src/free_all.c			\
		./src/main_scene.c			\
		./src/level.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

COMP	=	-o $(NAME)

CPPFLAGS	=	-iquote ./include

CFLAGS	=	-Wall -Wextra

CSFMLFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(COMP) $(CFLAGS) $(CSFMLFLAGS) $(OBJ)

test:
	$(MAKE) re
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) ./src/*#
	$(RM) ./src/*~
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

debug:  CFLAGS += -ggdb3
debug:  fclean re

re: fclean all

.PHONY: all clean fclean re test
