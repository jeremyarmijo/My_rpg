/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include <string.h>
#include "my_rpg.h"
#include "my_macro.h"

int my_rpg(void)
{
    param_win_t *win = init_game_status();
    scene_start_t *start_scene = init_start_scene();

    set_default_music(win);
    while (sfRenderWindow_isOpen(win->window)) {
        sfMusic_pause(win->sounds.in_fight);
        close_win(&win, start_scene);
        load_start_scene(start_scene, win);
        sfRenderWindow_display(win->window);
        time_mov(100000.0);
    }
    free_all(win, start_scene);
    return EXIT_WITH_SUCCESS;
}
