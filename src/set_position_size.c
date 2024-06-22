/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include "my_rpg.h"
#include "my_macro.h"

void set_position_size(button_t **button, sfVector2f
    position, sfVector2f scale)
{
    sfSprite_setPosition((*button)->sprite, position);
    sfSprite_setScale((*button)->sprite, scale);
}
