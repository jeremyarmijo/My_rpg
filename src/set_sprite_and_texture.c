/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include <string.h>
#include "my_rpg.h"
#include "my_macro.h"

bool set_sprite_and_texture(button_t **button,
    char *path_none, char *path_is_hover, char *path_is_pressed)
{
    path_sprites_t *paths = malloc(sizeof(path_sprites_t));

    paths->basic = strdup(path_none);
    paths->is_hover = strdup(path_is_hover);
    paths->is_pressed = duplicate_string(path_is_pressed);
    (*button)->paths = paths;
    (*button)->sprite = sfSprite_create();
    (*button)->texture = sfTexture_createFromFile(
        path_none, NULL);
    sfSprite_setTexture((*button)->sprite, (*button)->texture, sfTrue);
    if (!(*button)->sprite || !(*button)->texture || !(*button)->paths)
        return true;
    return false;
}
