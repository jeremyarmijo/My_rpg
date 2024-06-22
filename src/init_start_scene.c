/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include <string.h>
#include "my_rpg.h"
#include "my_macro.h"

button_t *init_exit_button(char *normal, char *over)
{
    button_t *exit = malloc(sizeof(button_t));
    path_sprites_t *paths = malloc(sizeof(path_sprites_t));

    if (!exit)
        return NULL;
    paths->basic = strdup(normal);
    paths->is_hover = strdup(over);
    paths->is_pressed = NULL;
    exit->paths = paths;
    exit->sprite = sfSprite_create();
    exit->texture = sfTexture_createFromFile(paths->basic, NULL);
    sfSprite_setTexture(exit->sprite, exit->texture, sfTrue);
    if (!exit->sprite || !exit->texture || !exit->paths)
        return NULL;
    set_position_size(&exit, (sfVector2f) {
        (WINDOW_WIDTH - 150),
        (20)},
            (sfVector2f) {0.2, 0.2});
    return exit;
}

scene_start_t *init_start_scene(void)
{
    scene_start_t *scene = malloc(sizeof(scene_start_t));
    button_t *button = malloc(sizeof(button_t));
    button_t *exit = init_exit_button(P_EXIT_BUTTON,
        "scenes/start/button_large/Exit Button_r.png");

    if (set_scene(&scene, "scenes/start/start_backgrounds.png", 0, 0)
        || set_sprite_and_texture(&button,
            "scenes/start/button_large/Start Button.png",
            "scenes/start/button_large/Start Button_r.png", NULL))
        return NULL;
    set_position_size(&button, (sfVector2f) {
            (WINDOW_WIDTH / 2) - (190 / 2),
            (WINDOW_LENGTH / 2) - (125 / 2)},
                (sfVector2f) {0.35, 0.35});
    scene->exit_game = exit;
    scene->button = button;
    scene->status = ACTIVE;
    scene->next = NULL;
    return scene;
}

scene_start_t *init_fight_scene(void)
{
    scene_start_t *scene = malloc(sizeof(scene_start_t));
    button_t *button = malloc(sizeof(button_t));
    button_t *exit = NULL;

    if (set_scene(&scene, "assets/map_fight_1", 0, 0))
        return NULL;
    set_scale(&scene, (sfVector2f) {1.5, 1.25});
    scene->exit_game = exit;
    scene->button = button;
    scene->status = ACTIVE;
    scene->next = NULL;
    return scene;
}
