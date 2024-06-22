/*
** EPITECH PROJECT, 2024
** button
** File description:
** management
*/

#include "my_rpg.h"

void button_management(button_t *button, param_win_t *win)
{
    set_sprite_button_state(button, win);
    sfRenderWindow_drawSprite(win->window,
        button->sprite, NULL);
}
