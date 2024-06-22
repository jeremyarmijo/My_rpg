/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include "my_rpg.h"
#include "my_macro.h"

bool set_scene(scene_start_t **scene, const char *path_picture,
    float x, float y)
{
    (*scene)->sprite = sfSprite_create();
    (*scene)->texture = sfTexture_createFromFile(path_picture, NULL);
    sfSprite_setTexture((*scene)->sprite, (*scene)->texture, sfTrue);
    sfSprite_setPosition((*scene)->sprite, (sfVector2f) {x, y});
    if (!(*scene)->sprite || !(*scene)->texture)
        return true;
    return false;
}

void set_scale(scene_start_t **scene, sfVector2f scale)
{
    sfSprite_setScale((*scene)->sprite, scale);
}
