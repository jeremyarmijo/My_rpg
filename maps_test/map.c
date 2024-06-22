/*
** EPITECH PROJECT, 2024
** maps
** File description:
** map functions for my_rpg
*/

#include "rpg.h"

static unsigned int count_tilesets(tmx_map *map)
{
    tmx_tileset_list *tileset_list = map->ts_head;
    unsigned int tileset_count = 0;

    while (tileset_list) {
        tileset_count++;
        tileset_list = tileset_list->next;
    }
    return tileset_count;
}

int get_tileset_count(tmx_map *map)
{
    tmx_tileset_list *tileset_list = map->ts_head;
    unsigned int tileset_count = 0;

    while (tileset_list) {
        tileset_count++;
        tileset_list = tileset_list->next;
    }
    return tileset_count;
}

static bool *load_collidable(tmx_tileset *tileset)
{
    bool *collidable = malloc(tileset->tilecount * sizeof(bool));
    tmx_tile *tile = NULL;
    tmx_property *prop = NULL;

    for (unsigned int i = 0; i < tileset->tilecount; i++) {
        collidable[i] = false;
        tile = &(tileset->tiles[i]);
        if (!tile)
            continue;
        prop = tmx_get_property(tile->properties, "collidable");
        if (prop && prop->type == PT_BOOL) {
            collidable[i] = prop->value.boolean;
        }
    }
    return collidable;
}

tmx_map *load_map(const char *path)
{
    tmx_map *map = tmx_load(path);

    if (!map)
        exit(1);
    return map;
}

tileset_t *load_tilesets(tmx_map *map)
{
    unsigned int tileset_count = count_tilesets(map);
    tileset_t *tilesets = malloc(tileset_count * sizeof(tileset_t));
    tmx_tileset_list *tileset_list = NULL;

    if (!tilesets) {
        return NULL;
    }
    tileset_list = map->ts_head;
    for (unsigned int i = 0; i < tileset_count; i++) {
        tilesets[i] = load_tileset(tileset_list->tileset->image->source,
            tileset_list->tileset);
        tileset_list = tileset_list->next;
    }
    return tilesets;
}

tileset_t load_tileset(const char *image_path, tmx_tileset *tileset)
{
    tileset_t ts;

    ts.texture = sfTexture_createFromFile(image_path, NULL);
    if (!ts.texture) {
        exit(1);
    }
    ts.collidable = load_collidable(tileset);
    if (!ts.collidable) {
        exit(1);
    }
    return ts;
}

sfFloatRect initialize_player_bounds(tmx_map *map)
{
    sfFloatRect player_bounds = {
        .left = map->width * map->tile_width / 2,
        .top = map->height * map->tile_height / 2,
        .width = 8,
        .height = 8
    };

    return player_bounds;
}
