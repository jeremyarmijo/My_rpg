/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include "my_rpg.h"
#include "my_macro.h"

void check_event_type(param_win_t *win)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        win->click = sfTrue;
    else
        win->click = sfFalse;
}
