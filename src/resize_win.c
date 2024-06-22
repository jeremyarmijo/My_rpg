/*
** EPITECH PROJECT, 2024
** resize
** File description:
** window
*/
#include "player.h"
#include "my_rpg.h"
#include "my_macro.h"

void resize_win(param_win_t *win, button_t *button,
    sfVector2u size, sfVector2f pos)
{
    sfSprite_setPosition(button->sprite, pos);
    button_management(button, win);
    active_button(button, win);
    if (button->is_active == ACTIVE)
        sfRenderWindow_setSize(win->window, size);
    free_button(button);
}
