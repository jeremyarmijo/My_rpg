/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include <string.h>
#include "my_rpg.h"
#include "my_macro.h"

sfBool is_hover_button(button_t *button, param_win_t *config)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(button->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(config->window);

    if (sfFloatRect_contains(&hitbox, mouse_pos.x, mouse_pos.y))
        return sfTrue;
    return sfFalse;
}
