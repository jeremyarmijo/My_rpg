/*
** EPITECH PROJECT, 2024
** display
** File description:
** the current size window
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_macro.h"

void display_size_win(param_win_t *win, sfVector2f pos)
{
    sfText* text = sfText_create();
    sfFont* font = sfFont_createFromFile("text_font/Arial.ttf");
    char *to_print = duplicate_string(win->language ?
        "Current window size : " : "Taille de la fenetre ");
    char str[20];
    sfVector2u size = sfRenderWindow_getSize(win->window);

    str[20] = '\0';
    sprintf(str, "\n\t\t%dx%d", size.x, size.y);
    to_print = realloc(to_print, strlen(to_print) + 20);
    to_print = strcat(to_print, str);
    sfText_setString(text, to_print);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f) {pos.x, pos.y});
    sfRenderWindow_drawText(win->window, text, NULL);
    free(to_print);
    sfFont_destroy(font);
    sfText_destroy(text);
}
