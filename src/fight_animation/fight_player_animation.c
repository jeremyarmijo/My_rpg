/*
** EPITECH PROJECT, 2024
** fight_player_animation.c
** File description:
** all animations for player's animation
*/

#include "player.h"
#include "my_rpg.h"
#include "my_macro.h"

void handle_battle_animation(param_win_t *win)
{
    sfIntRect move = {idle_battle.left, idle_battle.top, idle_battle.width,
        idle_battle.height};

    if (win->gamestat->level->atk_move == true)
        return;
    if (win->gamestat->run_anim == false) {
        win->battle_stage->player->move = move;
        win->gamestat->run_anim = true;
        sfSprite_setPosition(win->battle_stage->player->sprite, (sfVector2f)
        {150, 400});
    }
    if (win->battle_stage->player->move.left < max_battle)
        win->battle_stage->player->move.left += offset;
    else
        win->battle_stage->player->move.left = 0;
}

static void player_set_sleash(param_win_t **win, int who)
{
    if (who == 0) {
        (*win)->gamestat->level->atk_move = false;
        (*win)->gamestat->level->slash = false;
        (*win)->gamestat->run_anim = false;
        (*win)->gamestat->level->player_turn = false;
        (*win)->battle_stage->enemy->hp -= ((*win)->battle_stage->player->atk
        + 5 - (*win)->battle_stage->enemy->def);
    }
    if (who == 1) {
        (*win)->gamestat->level->player_turn = false;
        (*win)->battle_stage->enemy->hp -= ((*win)->battle_stage->player->atk -
            (*win)->battle_stage->enemy->def);
    }
    if (who == 2) {
        (*win)->gamestat->run_anim = false;
        (*win)->gamestat->level->player_turn = false;
        (*win)->battle_stage->enemy->hp -= ((*win)->battle_stage->player->atk);
    }
}

static void player_slash(param_win_t *win)
{
    sfIntRect move = {slash.left, slash.top, slash.width, slash.height};

    if (win->gamestat->level->slash == true &&
        win->battle_stage->player->move.top != move.top){
        win->gamestat->run_anim = false;
    }
    if (win->gamestat->run_anim == false){
        win->battle_stage->player->move = move;
        win->gamestat->run_anim = true;
        sfSprite_setPosition(win->battle_stage->player->sprite, (sfVector2f)
        {1250, 400});
    }
    if (win->battle_stage->player->move.left < max_slash){
        win->battle_stage->player->move.left += offset;
    } else {
        player_set_sleash(&win, 0);
    }
}

static void player_up_slash(param_win_t *win)
{
    sfIntRect move = {up_slash.left, up_slash.top, up_slash.width,
        up_slash.height};

    if (win->gamestat->level->up_slash == true &&
        win->battle_stage->player->move.top != move.top)
        win->gamestat->run_anim = false;
    if (win->gamestat->run_anim == false){
        win->battle_stage->player->move = move;
        win->gamestat->run_anim = true;
        sfSprite_setPosition(win->battle_stage->player->sprite, (sfVector2f)
        {1250, 400});
    }
    if (win->battle_stage->player->move.left < max_up_slash){
        win->battle_stage->player->move.left += offset;
    } else {
        win->gamestat->level->atk_move = false;
        win->gamestat->level->up_slash = false;
        win->gamestat->run_anim = false;
        player_set_sleash(&win, 1);
    }
}

static void player_back_slash(param_win_t *win)
{
    sfIntRect move = {back_slash.left, back_slash.top, back_slash.width,
        back_slash.height};

    if (win->gamestat->level->atk_sp == true &&
        win->battle_stage->player->move.top != move.top){
        win->gamestat->run_anim = false;
    }
    if (win->gamestat->run_anim == false){
        win->battle_stage->player->move = move;
        win->gamestat->run_anim = true;
        sfSprite_setPosition(win->battle_stage->player->sprite, (sfVector2f)
        {1250, 400});
    }
    if (win->battle_stage->player->move.left < max_back_slash){
        win->battle_stage->player->move.left += offset;
    } else {
        win->gamestat->level->atk_move = false;
        win->gamestat->level->atk_sp = false;
        player_set_sleash(&win, 2);
    }
}

static void player_ult_attack(param_win_t *win)
{
    sfIntRect move = {final_slash.left, final_slash.top, final_slash.width,
        final_slash.height};

    if (win->battle_stage->player->move.top != move.top)
        win->gamestat->run_anim = false;
    if (win->gamestat->run_anim == false){
        win->battle_stage->player->move = move;
        sfSprite_setPosition(win->battle_stage->player->sprite,
            (sfVector2f) {1250, 400});
        win->gamestat->run_anim = true;
        sfSprite_setPosition(win->battle_stage->player->sprite, (sfVector2f)
        {1250, 400});
    }
    if (win->battle_stage->player->move.left < max_final_slash){
        win->battle_stage->player->move.left += offset;
    } else {
        set_player_ult_attack(&win);
    }
}

void player_dead_animation(param_win_t *win)
{
    sfIntRect move = {dying_anim.left, dying_anim.top, dying_anim.width,
        dying_anim.height};

    if (win->battle_stage->player->move.top != move.top){
        win->battle_stage->player->move = move;
        sfSprite_setPosition(win->battle_stage->player->sprite, (sfVector2f)
        {150, 400});
    }
    if (win->battle_stage->player->move.left < max_dying){
        win->battle_stage->player->move.left += offset;
        sfSprite_setTextureRect(win->battle_stage->player->sprite,
        win->battle_stage->player->move);
    } else
        set_gamestatus(win);
}

void player_hurt_animation(param_win_t *win)
{
    sfIntRect move = {hurt_anim.left, hurt_anim.top, hurt_anim.width,
        hurt_anim.height};

    if (win->battle_stage->player->move.top != move.top){
        win->battle_stage->player->move = move;
        sfSprite_setPosition(win->battle_stage->player->sprite, (sfVector2f)
        {150, 400});
    }
    if (win->battle_stage->player->move.left < max_hurt){
        win->battle_stage->player->move.left += offset;
        sfSprite_setTextureRect(win->battle_stage->player->sprite,
        win->battle_stage->player->move);
    }
}

void set_player_attack_move(param_win_t *win)
{
    if (win->gamestat->level->atk_move == true){
        if (win->gamestat->level->slash == true)
            player_slash(win);
        if (win->gamestat->level->up_slash == true)
            player_up_slash(win);
        if (win->gamestat->level->atk_sp == true)
            player_back_slash(win);
        if (win->gamestat->level->ult_sp == true)
            player_ult_attack(win);
    }
}

void player_battle_animation(param_win_t *win)
{
    if (win->gamestat->level->dead_step == true &&
        win->battle_stage->player->hp <= 0){
        player_dead_animation(win);
        return;
    }
    if (win->gamestat->level->player_turn == false){
        player_hurt_animation(win);
        return;
    }
    if (win->gamestat->level->atk_move == false)
        handle_battle_animation(win);
    set_player_attack_move(win);
    sfSprite_setTextureRect(win->battle_stage->player->sprite,
        win->battle_stage->player->move);
}
