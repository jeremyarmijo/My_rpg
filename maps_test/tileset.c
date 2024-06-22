/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** tileset
*/

#include "rpg.h"

bool check_tile_collision(collision_context_t *context, int x, int y)
{
    int gid = context->layer->content.gids[y * context->map->width + x];
    tile_id_t tile_id;

    if (gid == 0) {
        return false;
    }
    tile_id = get_tile_id(context->map, gid);
    return is_collidable(context->tilesets, tile_id, context->num_tilesets);
}

int get_tileset_index(tmx_map *map, tmx_tileset_list *tileset_list)
{
    int index = 0;
    tmx_tileset_list *temp = map->ts_head;

    while (temp != tileset_list) {
        index++;
        temp = temp->next;
    }
    return index;
}

tile_id_t get_tile_id(tmx_map *map, unsigned int gid)
{
    tile_id_t id = {0, gid};
    tmx_tileset_list *tileset_list = map->ts_head;
    tmx_tileset *tileset = NULL;

    while (tileset_list != NULL) {
        tileset = tileset_list->tileset;
        if (gid >= tileset_list->firstgid &&
            gid < (tileset_list->firstgid + tileset->tilecount)) {
            id.tileset_index = get_tileset_index(map, tileset_list);
            id.local_id = gid - tileset_list->firstgid;
            break;
        }
        tileset_list = tileset_list->next;
    }
    return id;
}

bool is_collidable(tileset_t *tilesets, tile_id_t tile_id,
    unsigned int num_tilesets)
{
    if (tile_id.tileset_index >= num_tilesets ||
        tile_id.local_id >= 1000) {
        return false;
    }
    return tilesets[tile_id.tileset_index].collidable[tile_id.local_id];
}
