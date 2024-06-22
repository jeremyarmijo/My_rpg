/*
** EPITECH PROJECT, 2024
** maps
** File description:
** header file for my_rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #include <SFML/Graphics.h>
    #include <tmx.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>

typedef struct {
    sfTexture *texture;
    bool *collidable;
} tileset_t;

typedef struct {
    sfRenderWindow *window;
    sfView *view;
    tmx_map *map;
    tileset_t *tilesets;
} render_context_t;

typedef struct {
    tmx_layer *layer;
    tmx_map *map;
    tileset_t *tilesets;
    unsigned int num_tilesets;
} collision_context_t;

typedef struct {
    unsigned int tileset_index;
    unsigned int local_id;
} tile_id_t;

typedef struct {
    int start_x;
    int end_x;
    int start_y;
    int end_y;
} collision_bounds_t;

typedef struct {
    sfRenderWindow *window;
    tmx_map *map;
    tileset_t *tilesets;
    sfSprite *sprite;
} draw_context_t;

typedef struct {
    sfRenderWindow *window;
    tmx_map *map;
    tileset_t *tilesets;
    sfSprite *sprite;
    unsigned int x;
    unsigned int y;
    unsigned int gid;
} draw_tile_data_t;


// Function declarations
sfRenderWindow *create_window(unsigned int width,
    unsigned int height, const char *title);
sfView *create_view(float width, float height);
tmx_map *load_map(const char *path);
tileset_t *load_tilesets(tmx_map *map);
tileset_t load_tileset(const char *image_path, tmx_tileset *tileset);
sfFloatRect initialize_player_bounds(tmx_map *map);
void game_loop(render_context_t *context, sfFloatRect player_bounds);
void handle_events(sfRenderWindow *window);
sfVector2f get_player_movement(void);
sfFloatRect update_player_bounds(sfFloatRect player_bounds,
    sfVector2f movement);
bool is_within_map(sfFloatRect bounds, tmx_map *map);
bool check_collision(tileset_t *tilesets, tmx_map *map,
    sfFloatRect entity_bounds, unsigned int num_tilesets);
void render(render_context_t *context, sfFloatRect player_bounds);
void draw_layer(render_context_t *context, tmx_layer *layer);
void draw_player(sfRenderWindow *window, sfFloatRect player_bounds);
void cleanup(sfRenderWindow *window,
    sfView *view, tmx_map *map, tileset_t *tilesets);
bool check_tile_collision(collision_context_t *context, int x, int y);
tile_id_t get_tile_id(tmx_map *map, unsigned int gid);
int get_tileset_count(tmx_map *map);
bool is_collidable(tileset_t *tilesets, tile_id_t tile_id,
    unsigned int num_tilesets);
bool check_tile_range(collision_context_t *context,
    unsigned int x, unsigned int y);

#endif /* RPG_H_ */
