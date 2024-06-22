/*
** EPITECH PROJECT, 2024
** fight_nightborne.c
** File description:
** nightborne animation
*/

#include "ennemy.h"
#include "my_macro.h"
#include "my_rpg.h"

static void night_borne_idle(param_win_t *win)
{
    sfIntRect move = {nb_idle.left, nb_idle.top, nb_idle.width,
        nb_idle.height};

    if (win->gamestat->level->player_turn == false)
        return;
    if (win->gamestat->level->enemy_fight == false){
        win->battle_stage->enemy->move = move;
        win->gamestat->level->enemy_fight = true;
        sfSprite_setPosition(win->battle_stage->enemy->sprite, (sfVector2f)
        {1200, 300});
    }
    if (win->battle_stage->enemy->move.left < max_nb_idle)
        win->battle_stage->enemy->move.left += nb_offset;
    else
        win->battle_stage->enemy->move.left = 0;
}

static void night_borne_attack(param_win_t *win)
{
    sfIntRect move = {nb_atk.left, nb_atk.top, nb_atk.width,
        nb_atk.height};

    if (win->gamestat->level->player_turn == false &&
        win->battle_stage->enemy->move.top != move.top){
        win->battle_stage->enemy->move = move;
        sfSprite_setPosition(win->battle_stage->enemy->sprite, (sfVector2f)
        {200, 300});
    }
    if (win->battle_stage->enemy->move.left < max_nb_atk){
        win->battle_stage->enemy->move.left += nb_offset;
        sfSprite_setTextureRect(win->battle_stage->enemy->sprite,
        win->battle_stage->enemy->move);
    } else {
        choice_bot_attack(&win->battle_stage->player,
            &win->battle_stage->enemy);
        win->gamestat->level->player_turn = true;
        win->gamestat->level->enemy_fight = false;
    }
}

static void night_borne_dead_animation(param_win_t *win)
{
    sfIntRect move = {nb_die.left, nb_die.top, nb_die.width,
        nb_die.height};

    if (win->battle_stage->enemy->move.top != move.top){
        win->battle_stage->enemy->move = move;
        sfSprite_setPosition(win->battle_stage->enemy->sprite, (sfVector2f)
        {1200, 300});
    }
    if (win->battle_stage->enemy->move.left < max_nb_die){
        win->battle_stage->enemy->move.left += nb_offset;
    } else {
        set_gamestatus(win);
        win->gamestat->level->enemy_fight = false;
    }
}

static void night_borne_hurt_animation(param_win_t *win)
{
    sfIntRect move = {nb_hurt.left, nb_hurt.top, nb_hurt.width,
        nb_hurt.height};

    if (win->battle_stage->enemy->move.top != move.top){
        win->battle_stage->enemy->move = move;
        sfSprite_setPosition(win->battle_stage->enemy->sprite, (sfVector2f)
        {1200, 300});
    }
    if (win->battle_stage->enemy->move.left < max_nb_hurt){
        win->battle_stage->enemy->move.left += nb_offset;
        sfSprite_setTextureRect(win->battle_stage->enemy->sprite,
        win->battle_stage->enemy->move);
    }
}

void night_borne_fight_move(param_win_t *win)
{
    if (win->gamestat->level->dead_step == true &&
        win->battle_stage->enemy->hp <= 0){
        night_borne_dead_animation(win);
        sfSprite_setTextureRect(win->battle_stage->enemy->sprite,
        win->battle_stage->enemy->move);
        return;
    }
    if (win->gamestat->level->atk_move == true){
        night_borne_hurt_animation(win);
        return;
    }
    night_borne_idle(win);
    if (win->gamestat->level->player_turn == false) {
        night_borne_attack(win);
        if (win->battle_stage->player->hp < 0)
            win->battle_stage->player->hp = 0;
    }
    sfSprite_setTextureRect(win->battle_stage->enemy->sprite,
        win->battle_stage->enemy->move);
}
