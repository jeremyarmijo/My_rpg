/*
** EPITECH PROJECT, 2024
** free
** File description:
** all
*/

#include "my_rpg.h"

static void free_start_scene(param_win_t *win, scene_start_t *start_scene)
{
    free(win);
    free_button(start_scene->button);
    free_button(start_scene->exit_game);
    sfSprite_destroy(start_scene->sprite);
    sfTexture_destroy(start_scene->texture);
    free(start_scene);
}

void free_all(param_win_t *win, scene_start_t *start_scene)
{
    free(win->battle_stage->enemy);
    free(win->battle_stage->player);
    sfSprite_destroy(win->battle_stage->sprite);
    sfTexture_destroy(win->battle_stage->texture);
    free(win->battle_stage);
    free(win->gamestat->level);
    sfSprite_destroy(win->menu->back_menu_sprite);
    sfTexture_destroy(win->menu->back_menu_texture);
    free_button(win->menu->exit_menu);
    free_button(win->menu->loading->previous_state);
    free_button(win->menu->loading);
    free_button(win->menu->player_option->previous_state);
    free_button(win->menu->player_option);
    free_button(win->menu->saving->previous_state);
    free_button(win->menu->saving);
    free_button(win->menu->setting->next->previous_state);
    free_button(win->menu->setting->next);
    free_button(win->menu->setting);
    free_start_scene(win, start_scene);
    sfMusic_destroy(win->main_music);
}
