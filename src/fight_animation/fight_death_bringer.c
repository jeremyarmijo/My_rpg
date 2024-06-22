/*
** EPITECH PROJECT, 2024
** fight_death_bringer.c
** File description:
** death bringer figthing animation
*/

#include "ennemy.h"
#include "my_macro.h"
#include "my_rpg.h"

static void death_bringer_idle(param_win_t *win)
{
    sfIntRect move = {db_idle.left, db_idle.top, db_idle.width,
        db_idle.height};

    if (win->gamestat->level->player_turn == false)
        return;
    if (win->gamestat->level->enemy_fight == false){
        win->battle_stage->enemy->move = move;
        win->gamestat->level->enemy_fight = true;
        sfSprite_setPosition(win->battle_stage->enemy->sprite, (sfVector2f)
        {1200, 300});
    }
    if (win->battle_stage->enemy->move.left < max_db_idle){
        win->battle_stage->enemy->move.left += db_offset;
    } else {
        win->battle_stage->enemy->move.left = 0;
    }
}

bool choice_bot_100(battle_t **player, battle_t **enemy)
{
    int atk = 0;
    bool attack = false;

    if ((*enemy)->mana == -100) {
        atk = (((*enemy)->atk + ((*enemy)->atk / 2))- (*player)->def);
        if (atk > 0) {
            (*player)->hp -= atk;
            attack = false;
            (*enemy)->mana = 0;
        }
    }
    return attack;
}

void choice_bot_attack(battle_t **player, battle_t **enemy)
{
    int atk = choice_bot_100(player, enemy);
    static bool attack = false;

    if ((*enemy)->mana == -50 && attack == false) {
        atk = (((*enemy)->atk + ((*enemy)->atk / 4))- (*player)->def);
        if (atk > 0) {
            (*player)->hp -= atk;
            attack = true;
            (*enemy)->mana += 50;
        }
    } else {
        atk = ((*enemy)->atk - (*player)->def);
        if (atk > 0)
            (*player)->hp -= atk;
        if ((*enemy)->mana != -100)
            (*enemy)->mana -= 25;
        return;
    }
    if ((*player)->hp < 0)
        (*player)->hp = 0;
}

static void death_bringer_attack(param_win_t *win)
{
    sfIntRect move = {db_atk.left, db_atk.top, db_atk.width,
        db_atk.height};

    if (win->gamestat->level->player_turn == false &&
        win->battle_stage->enemy->move.top != move.top){
        win->battle_stage->enemy->move = move;
        sfSprite_setPosition(win->battle_stage->enemy->sprite, (sfVector2f)
        {200, 300});
    }
    if (win->battle_stage->enemy->move.left < max_db_atk){
        win->battle_stage->enemy->move.left += db_offset;
        sfSprite_setTextureRect(win->battle_stage->enemy->sprite,
        win->battle_stage->enemy->move);
    } else {
        choice_bot_attack(&win->battle_stage->player,
            &win->battle_stage->enemy);
        win->gamestat->level->player_turn = true;
        win->gamestat->level->enemy_fight = false;
    }
}

static void death_bringer_dead_animation(param_win_t *win)
{
    sfIntRect move = {db_die.left, db_die.top, db_die.width,
        db_die.height};

    if (win->battle_stage->enemy->move.top != move.top){
        win->battle_stage->enemy->move = move;
        sfSprite_setPosition(win->battle_stage->enemy->sprite, (sfVector2f)
        {1200, 300});
    }
    if (win->battle_stage->enemy->move.left < max_db_die){
        win->battle_stage->enemy->move.left += db_offset;
    } else {
        set_gamestatus(win);
        win->gamestat->level->enemy_fight = false;
    }
}

void death_bringer_hurt_animation(param_win_t *win)
{
    sfIntRect move = {db_hurt.left, db_hurt.top, db_hurt.width,
        db_hurt.height};

    if (win->battle_stage->enemy->move.top != move.top){
        win->battle_stage->enemy->move = move;
        sfSprite_setPosition(win->battle_stage->enemy->sprite, (sfVector2f)
        {1200, 300});
    }
    if (win->battle_stage->enemy->move.left < max_db_hurt){
        win->battle_stage->enemy->move.left += db_offset;
        sfSprite_setTextureRect(win->battle_stage->enemy->sprite,
        win->battle_stage->enemy->move);
    }
}

void death_bringer_fight_move(param_win_t *win)
{
    if (win->gamestat->level->dead_step == true &&
        win->battle_stage->enemy->hp <= 0){
        death_bringer_dead_animation(win);
        sfSprite_setTextureRect(win->battle_stage->enemy->sprite,
        win->battle_stage->enemy->move);
        return;
    }
    if (win->gamestat->level->atk_move == true){
        death_bringer_hurt_animation(win);
        return;
    }
    death_bringer_idle(win);
    if (win->gamestat->level->player_turn == false) {
        death_bringer_attack(win);
        if (win->battle_stage->player->hp < 0)
            win->battle_stage->player->hp = 0;
    }
    sfSprite_setTextureRect(win->battle_stage->enemy->sprite,
        win->battle_stage->enemy->move);
}
