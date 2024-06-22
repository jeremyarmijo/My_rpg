/*
** EPITECH PROJECT, 2024
** maps
** File description:
** rendering functions for my_rpg
*/

#include "rpg.h"

void render(render_context_t *context, sfFloatRect player_bounds)
{
    sfRenderWindow_clear(context->window, sfBlack);
    sfRenderWindow_setView(context->window, context->view);
    for (tmx_layer *layer = context->map->ly_head;
        layer != NULL; layer = layer->next) {
        if (layer->type == L_LAYER)
            draw_layer(context, layer);
    }
    draw_player(context->window, player_bounds);
    sfRenderWindow_display(context->window);
}

sfIntRect get_tile_rect(tmx_map *map, tileset_t *ts, tile_id_t tile_id)
{
    sfIntRect rect;
    sfVector2u texture_size = sfTexture_getSize(ts->texture);

    rect.left = (tile_id.local_id %
        (texture_size.x / map->tile_width)) *
        map->tile_width;
    rect.top = (tile_id.local_id /
        (texture_size.x / map->tile_width)) *
        map->tile_height;
    rect.width = map->tile_width;
    rect.height = map->tile_height;
    return rect;
}

void draw_tile(draw_tile_data_t *data)
{
    tile_id_t tile_id = get_tile_id(data->map, data->gid);
    tileset_t *ts = &data->tilesets[tile_id.tileset_index];
    sfIntRect rect = get_tile_rect(data->map, ts, tile_id);
    sfVector2f position = {data->x * data->map->tile_width,
        data->y * data->map->tile_height};

    sfSprite_setTexture(data->sprite, ts->texture, sfTrue);
    sfSprite_setTextureRect(data->sprite, rect);
    sfSprite_setPosition(data->sprite, position);
    sfRenderWindow_drawSprite(data->window, data->sprite, NULL);
}

static void draw_layer_row(render_context_t *context,
    tmx_layer *layer, sfSprite *sprite, unsigned int y)
{
    draw_tile_data_t data;
    unsigned int gid;

    for (unsigned int x = 0; x < context->map->width; x++) {
        gid = layer->content.gids[y * context->map->width + x];
        if (gid != 0) {
            data.window = context->window;
            data.map = context->map;
            data.tilesets = context->tilesets;
            data.sprite = sprite;
            data.x = x;
            data.y = y;
            data.gid = gid;
            draw_tile(&data);
        }
    }
}

void draw_layer(render_context_t *context, tmx_layer *layer)
{
    sfSprite *sprite = sfSprite_create();

    for (unsigned int y = 0; y < context->map->height; y++) {
        draw_layer_row(context, layer, sprite, y);
    }
    sfSprite_destroy(sprite);
}

void draw_player(sfRenderWindow *window, sfFloatRect player_bounds)
{
    sfRectangleShape *player = sfRectangleShape_create();

    sfRectangleShape_setPosition(player, (sfVector2f){player_bounds.left,
        player_bounds.top});
    sfRectangleShape_setSize(player, (sfVector2f){player_bounds.width,
        player_bounds.height});
    sfRectangleShape_setFillColor(player, sfColor_fromRGB(255, 0, 0));
    sfRenderWindow_drawRectangleShape(window, player, NULL);
    sfRectangleShape_destroy(player);
}
