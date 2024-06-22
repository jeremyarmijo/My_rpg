/*
** EPITECH PROJECT, 2024
** display the curent
** File description:
** volume
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my_macro.h"

static void print_in_window(param_win_t *win, sfVector2f pos, sfText* text)
{
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f) {pos.x, pos.y});
    sfRenderWindow_drawText(win->window, text, NULL);
}

void display_volume(param_win_t *win, sfVector2f pos)
{
    sfText* text = sfText_create();
    sfFont* font = sfFont_createFromFile("text_font/Arial.ttf");
    char *to_print = duplicate_string(win->language ?
        "Current volume level : " : "Volume actuelle du son :");
    char str[20];

    str[20] = '\0';
    sprintf(str, "\n\t\t\t  %d",
        (int)sfMusic_getVolume(win->main_music) > 100 ?
            100 : (int)sfMusic_getVolume(win->main_music));
    to_print = realloc(to_print, strlen(to_print) + 20);
    to_print = strcat(to_print, str);
    sfText_setString(text, to_print);
    sfText_setFont(text, font);
    print_in_window(win, pos, text);
    free(to_print);
    sfFont_destroy(font);
    sfText_destroy(text);
}
