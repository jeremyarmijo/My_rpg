/*
** EPITECH PROJECT, 2024
** init
** File description:
** button
*/
#include <string.h>
#include "my_rpg.h"

button_t *init_button(char *basic, char *over, float x, float y)
{
    button_t *setting = malloc(sizeof(button_t));
    path_sprites_t *paths = malloc(sizeof(path_sprites_t));

    if (!setting)
        return NULL;
    paths->basic = strdup(basic);
    paths->is_hover = duplicate_string(over);
    paths->is_pressed = NULL;
    setting->paths = paths;
    setting->sprite = sfSprite_create();
    setting->button_state = (enum statement)NONE;
    setting->texture = sfTexture_createFromFile(paths->basic, NULL);
    setting->next = NULL;
    setting->is_active = NOT_ACTIVE;
    sfSprite_setTexture(setting->sprite, setting->texture, sfTrue);
    if (!setting->sprite || !setting->texture || !setting->paths)
        return NULL;
    set_position_size(&setting, (sfVector2f) {20, 20}, (sfVector2f) {x, y});
    return setting;
}
