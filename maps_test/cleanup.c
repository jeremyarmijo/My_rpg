/*
** EPITECH PROJECT, 2024
** maps
** File description:
** cleanup functions for my_rpg
*/

#include "rpg.h"

static bool check_layer_row(collision_context_t *context,
    collision_bounds_t bounds, int y)
{
    for (int x = bounds.start_x; x <= bounds.end_x; x++) {
        if (check_tile_range(context, x, y)) {
            return true;
        }
    }
    return false;
}

bool check_layer_collision(collision_context_t *context,
    collision_bounds_t bounds)
{
    for (int y = bounds.start_y; y <= bounds.end_y; y++) {
        if (check_layer_row(context, bounds, y)) {
            return true;
        }
    }
    return false;
}

void cleanup(sfRenderWindow *window, sfView *view, tmx_map *map,
    tileset_t *tilesets)
{
    if (window) {
        sfRenderWindow_destroy(window);
    }
    if (view) {
        sfView_destroy(view);
    }
    if (map) {
        tmx_map_free(map);
    }
    if (tilesets) {
        for (int i = 0; i < get_tileset_count(map); i++) {
            sfTexture_destroy(tilesets[i].texture);
            free(tilesets[i].collidable);
        }
        free(tilesets);
    }
}
