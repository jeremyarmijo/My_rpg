/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include <stdbool.h>
#include <string.h>
#include "player.h"
#include "my_rpg.h"
#include "my_macro.h"

bool attribute_back_action(button_t *button_to_active,
    button_t *button_to_exit, param_win_t *win)
{
    if (button_to_active->is_active == ACTIVE) {
        button_management(button_to_exit, win);
        if (is_hover_button(button_to_exit, win)
            && win->click == sfTrue) {
            button_to_active->is_active = NOT_ACTIVE;
            return true;
        }
        return true;
    }
    return false;
}

bool menu_is_active(param_win_t *win)
{
    if (win->menu->setting->button_state == PRESSED
        || (win->event.key.code == sfKeyEscape)) {
        win->gamestat->menu = true;
        win->menu->setting->is_active = ACTIVE;
    }
    if (win->menu->setting->is_active == ACTIVE) {
        return true;
    }
    return false;
}

sfBool is_hover_sprite(param_win_t *config)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(config->player->body);
    sfVector2f enemy_pos = sfSprite_getPosition(config->map_enemy->sprite);

    if (sfFloatRect_contains(&hitbox, enemy_pos.x, enemy_pos.y))
        return sfTrue;
    return sfFalse;
}

void display_start_scene(param_win_t *win, scene_start_t *start_scene)
{
    sfRenderWindow_drawSprite(win->window, start_scene->sprite, NULL);
    button_management(win->menu->setting, win);
    button_management(start_scene->button, win);
    button_management(start_scene->exit_game, win);
    if (start_scene->button->button_state == PRESSED){
        start_scene->status = NOT_ACTIVE;
        win->gamestat->start_menu = false;
        win->gamestat->game_in = true;
        win->gamestat->enable_move = true;
        win->gamestat->intro = true;
        sfRenderWindow_clear(win->window, sfWhite);
        sfSprite_setPosition(win->player->body, (sfVector2f){WINDOW_WIDTH / 2,
            WINDOW_LENGTH / 2});
    }
}

static void select_stage(param_win_t *win, scene_start_t *start_scene)
{
    if (win->gamestat->menu) {
        display_menu(win);
        return;
    }
    if (win->gamestat->start_menu)
        display_start_scene(win, start_scene);
    if (win->gamestat->game_in) {
        main_scene(win);
        sfRenderWindow_drawSprite(win->window, win->player->body, NULL);
        win->gamestat->display = true;
    }
    if (win->gamestat->level->level_1 == true)
        level1(win);
    if (win->gamestat->level->level_2 == true)
        level2(win);
    if (win->gamestat->level->level_3 == true)
        level3(win);
    if (win->gamestat->display)
        display_stat(win, (sfVector2f) {10, WINDOW_LENGTH - 155});
}

void load_start_scene(scene_start_t *start_scene, param_win_t *win)
{
    select_stage(win, start_scene);
    if (menu_is_active(win))
        return;
    if (is_hover_sprite(win)) {
        if (win->gamestat->level->level == 0)
            win->gamestat->level->level_1 = true;
        if (win->gamestat->level->level == 2)
            win->gamestat->level->level_2 = true;
        if (win->gamestat->level->level == 3)
            win->gamestat->level->level_3 = true;
    }
    if (win->gamestat->game_in == true && win->gamestat->level->level == 0
        && win->gamestat->level->start_fight == false)
        sfRenderWindow_drawSprite(win->window, win->map_enemy->sprite, NULL);
    if (win->gamestat->intro == true &&
        win->gamestat->level->start_fight == false)
        draw_intro(win);
    if (win->gamestat->game_in == true && win->gamestat->enable_move == true)
        player_moves(win);
}
