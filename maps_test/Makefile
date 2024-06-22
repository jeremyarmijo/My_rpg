##
## EPITECH PROJECT, 2024
## MAKEFILE
## File description:
## TEST MAPS
##

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I include
LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -ltmx -lz -lxml2

SRC = main.c cleanup.c collision.c game.c map.c render.c tileset.c window.c
OBJ = $(SRC:.c=.o)
TARGET = the_map

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)
	mv the_map ../
	cd ..

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
