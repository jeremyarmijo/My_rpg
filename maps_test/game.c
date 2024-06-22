/*
** EPITECH PROJECT, 2024
** maps
** File description:
** game functions for my_rpg
*/

#include "rpg.h"


void game_loop(render_context_t *context, sfFloatRect player_bounds)
{
    sfVector2f movement;
    sfFloatRect new_bounds;

    while (sfRenderWindow_isOpen(context->window)) {
        handle_events(context->window);
        movement = get_player_movement();
        new_bounds = update_player_bounds(player_bounds, movement);
        if (is_within_map(new_bounds, context->map) &&
            !check_collision(context->tilesets, context->map, new_bounds,
            get_tileset_count(context->map))) {
            player_bounds = new_bounds;
            sfView_setCenter(context->view, (sfVector2f){player_bounds.left +
            player_bounds.width / 2, player_bounds.top +
            player_bounds.height / 2});
        }
        render(context, player_bounds);
    }
}

void handle_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

sfVector2f get_player_movement(void)
{
    sfVector2f movement = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        movement.y -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        movement.y += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        movement.x -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        movement.x += 1;
    }
    return movement;
}

sfFloatRect update_player_bounds(sfFloatRect player_bounds,
    sfVector2f movement)
{
    sfFloatRect new_bounds = player_bounds;

    new_bounds.left += movement.x;
    new_bounds.top += movement.y;
    return new_bounds;
}

bool is_within_map(sfFloatRect bounds, tmx_map *map)
{
    return bounds.left >= 0 && bounds.top >= 0 &&
        bounds.left + bounds.width <= map->width * map->tile_width &&
        bounds.top + bounds.height <= map->height * map->tile_height;
}
