/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include <string.h>
#include "player.h"
#include "my_rpg.h"
#include "my_macro.h"

static void set_run_animation(param_win_t *win)
{
    sfIntRect run = {run_anim.left, run_anim.top, run_anim.width,
        run_anim.height};

    if (win->player->is_moving == false)
        win->player->move = run;
    if (win->player->move.left < max_run)
        win->player->move.left += offset;
    else
        win->player->move.left = 0;
    sfSprite_setTextureRect(win->player->body, win->player->move);
    if (win->player->is_left == true)
        sfSprite_setScale(win->player->body, (sfVector2f) {-2, 2});
    else
        sfSprite_setScale(win->player->body, (sfVector2f) {2, 2});
}

static void move_left(param_win_t *win)
{
    sfVector2f move = {-5 * win->player->speed, 0};

    set_run_animation(win);
    sfSprite_move(win->player->body, move);
    if (win->player->is_moving == false)
        win->player->is_moving = true;
}

static void move_right(param_win_t *win)
{
    sfVector2f move = {5 * win->player->speed, 0};

    set_run_animation(win);
    sfSprite_move(win->player->body, move);
    if (win->player->is_moving == false)
        win->player->is_moving = true;
}

static void move_up(param_win_t *win)
{
    sfVector2f move = {0, -5 * win->player->speed};

    set_run_animation(win);
    sfSprite_move(win->player->body, move);
    if (win->player->is_moving == false)
        win->player->is_moving = true;
}

static void move_down(param_win_t *win)
{
    sfVector2f move = {0, 5 * win->player->speed};

    set_run_animation(win);
    sfSprite_move(win->player->body, move);
    if (win->player->is_moving == false)
        win->player->is_moving = true;
}

void idle_animation(param_win_t *win)
{
    sfIntRect idle = {idle_anim.left, idle_anim.top, idle_anim.width,
        idle_anim.height};

    if (win->player->is_moving == true)
        win->player->move = idle;
    win->player->is_moving = false;
    if (win->player->move.left < max_idle)
        win->player->move.left += offset;
    else
        win->player->move.left = 0;
    sfSprite_setTextureRect(win->player->body, win->player->move);
}

void player_moves(param_win_t *win)
{
    if (sfKeyboard_isKeyPressed((sfKeyCode)sfKeyUp)) {
        move_up(win);
        return;
    } else if (sfKeyboard_isKeyPressed((sfKeyCode)sfKeyDown)) {
        move_down(win);
        return;
    }
    if (sfKeyboard_isKeyPressed((sfKeyCode)sfKeyRight)) {
        win->player->is_left = false;
        move_right(win);
        return;
    } else if (sfKeyboard_isKeyPressed((sfKeyCode)sfKeyLeft)) {
        win->player->is_left = true;
        move_left(win);
        return;
    }
    idle_animation(win);
}
