/*
** EPITECH PROJECT, 2024
** main
** File description:
** scene
*/
#include "player.h"
#include "my_rpg.h"
#include "my_macro.h"

void main_scene(param_win_t *win)
{
    button_t *map = init_button("scenes/map.png", "scenes/map.png", 5, 5);

    sfSprite_setPosition(map->sprite, (sfVector2f) {-50, -50});
    sfRenderWindow_drawSprite(win->window,
        map->sprite, NULL);
    free_button(map);
}
