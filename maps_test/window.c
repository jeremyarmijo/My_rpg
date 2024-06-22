/*
** EPITECH PROJECT, 2024
** maps
** File description:
** window functions for my_rpg
*/

#include "rpg.h"

sfRenderWindow *create_window(unsigned int width,
    unsigned int height, const char *title)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){width,
        height, 32}, title, sfResize | sfClose, NULL);

    if (!window) {
        printf("Failed to create SFML window\n");
    }
    return window;
}
