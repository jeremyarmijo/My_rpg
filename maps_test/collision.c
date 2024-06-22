/*
** EPITECH PROJECT, 2024
** maps
** File description:
** collision functions for my_rpg
*/

#include "rpg.h"

static int is_valid_tile_position(unsigned int x,
    unsigned int y, tmx_map *map)
{
    return (x < map->width && y < map->height);
}

static bool check_tile_in_bounds(collision_context_t *context, int x, int y)
{
    return is_valid_tile_position(x, y, context->map) &&
        check_tile_collision(context, x, y);
}

static bool check_row_collision(collision_context_t *context,
    collision_bounds_t bounds, int y)
{
    for (int x = bounds.start_x; x <= bounds.end_x; x++) {
        if (check_tile_in_bounds(context, x, y)) {
            return true;
        }
    }
    return false;
}

static bool check_collision_in_layer(collision_context_t *context,
    collision_bounds_t bounds)
{
    for (int y = bounds.start_y; y <= bounds.end_y; y++) {
        if (check_row_collision(context, bounds, y)) {
            return true;
        }
    }
    return false;
}

bool check_tile_range(collision_context_t *context,
    unsigned int x, unsigned int y)
{
    if (!is_valid_tile_position(x, y, context->map)) {
        return false;
    }
    return check_tile_collision(context, x, y);
}

static collision_bounds_t compute_collision_bounds(sfFloatRect entity_bounds,
    unsigned int tile_width, unsigned int tile_height)
{
    collision_bounds_t bounds;

    bounds.start_x = entity_bounds.left / tile_width;
    bounds.end_x = (entity_bounds.left + entity_bounds.width) / tile_width;
    bounds.start_y = entity_bounds.top / tile_height;
    bounds.end_y = (entity_bounds.top + entity_bounds.height) / tile_height;
    return bounds;
}

static collision_context_t initialize_collision_context(tmx_map *map,
    tileset_t *tilesets, unsigned int num_tilesets)
{
    collision_context_t context;

    context.map = map;
    context.tilesets = tilesets;
    context.num_tilesets = num_tilesets;
    return context;
}

static bool check_layer_for_collision(tmx_layer *layer,
    collision_context_t *context, collision_bounds_t bounds)
{
    if (layer->type != L_LAYER) {
        return false;
    }
    context->layer = layer;
    return check_collision_in_layer(context, bounds);
}

static bool check_collision_in_map(tmx_map *map, collision_context_t *context,
    collision_bounds_t bounds)
{
    tmx_layer *layer;

    for (layer = map->ly_head; layer != NULL; layer = layer->next) {
        if (check_layer_for_collision(layer, context, bounds)) {
            return true;
        }
    }
    return false;
}

bool check_collision(tileset_t *tilesets, tmx_map *map,
    sfFloatRect entity_bounds, unsigned int num_tilesets)
{
    unsigned int tile_width = map->tile_width;
    unsigned int tile_height = map->tile_height;
    collision_bounds_t bounds = compute_collision_bounds(entity_bounds,
        tile_width, tile_height);
    collision_context_t context = initialize_collision_context(map,
        tilesets, num_tilesets);

    return check_collision_in_map(map, &context, bounds);
}
