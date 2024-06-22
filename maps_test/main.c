/*
** EPITECH PROJECT, 2024
** maps
** File description:
** main file for my_rpg
*/

#include "rpg.h"

int main(void)
{
    sfRenderWindow *window = create_window(1920, 1080, "MAPS");
    sfView *view = sfView_create();
    tmx_map *map = load_map("maps/map.tmx");
    tileset_t *tilesets = load_tilesets(map);
    sfFloatRect player_bounds = initialize_player_bounds(map);
    render_context_t render_context;

    sfView_setCenter(view, (sfVector2f){player_bounds.left +
        player_bounds.width / 2,
        player_bounds.top + player_bounds.height / 2});
    sfView_setSize(view, (sfVector2f){350, 180});
    render_context.window = window;
    render_context.view = view;
    render_context.map = map;
    render_context.tilesets = tilesets;
    game_loop(&render_context, player_bounds);
    cleanup(window, view, map, tilesets);
    return 0;
}
