/*
** EPITECH PROJECT, 2024
** fight
** File description:
** start fight
*/

#include <stdbool.h>
#include <string.h>
#include "player.h"
#include "my_rpg.h"
#include "my_macro.h"
#include "ennemy.h"
#include <stdio.h>

static int hp_of_player(int life, int coef, int hp, int hp_max)
{
    float coef_life = ((hp * 100) / hp_max);

    life = life * (coef_life / 100);
    return (life * coef);
}

static void set_life_bar(battle_t **caractere, param_win_t *win,
    int coef)
{
    int hp_player = hp_of_player(530, coef, (*caractere)->hp,
        (*caractere)->hp_max);
    int mana = hp_of_player(530, coef, (*caractere)->mana, 100);

    sfRectangleShape_setSize((*caractere)->part_of_life,
        (sfVector2f){(hp_player), 25});
    sfRectangleShape_setSize((*caractere)->energy,
        (sfVector2f){(mana * coef), 25});
    sfRenderWindow_drawRectangleShape(win->window, (*caractere)->bord, NULL);
    sfRenderWindow_drawRectangleShape(win->window,
        (*caractere)->life_bar, NULL);
    sfRenderWindow_drawRectangleShape(win->window,
        (*caractere)->part_of_life, NULL);
    sfRenderWindow_drawRectangleShape(win->window, (*caractere)->energy, NULL);
}

void set_player_ult_attack(param_win_t **win)
{
    (*win)->gamestat->level->atk_move = false;
    (*win)->gamestat->level->ult_sp = false;
    (*win)->gamestat->run_anim = false;
    (*win)->gamestat->level->player_turn = false;
    (*win)->battle_stage->enemy->hp -= ((*win)->battle_stage->player->atk) * 2;
}

static void choice_of_attack_sp(battle_t **player, battle_t **enemy,
    param_win_t **win)
{
    if ((*win)->battle_stage->player->attack_sp1->button_state ==
            PRESSED && (*win)->gamestat->level->player_turn == true &&
            (*win)->gamestat->depressed == true && (*player)->mana >= 50) {
        (*enemy)->hp -= ((((*player)->atk + ((*player)->atk) / 4)
            ) - (*enemy)->def);
        (*win)->gamestat->depressed = false;
        (*win)->gamestat->level->atk_move = true;
        (*win)->gamestat->level->atk_sp = true;
        if ((*player)->mana >= 100)
            (*player)->mana = 50;
        (*player)->mana -= 50;
    }
    if ((*win)->battle_stage->player->attack_sp2->button_state ==
            PRESSED && (*win)->gamestat->level->player_turn == true &&
            (*win)->gamestat->depressed == true && (*player)->mana == 100) {
        (*player)->mana = 0;
        (*win)->gamestat->depressed = false;
        (*win)->gamestat->level->atk_move = true;
        (*win)->gamestat->level->ult_sp = true;
    }
}

void choice_of_attack(battle_t **player, battle_t **enemy, param_win_t **win)
{
    static bool slash = true;

    if ((*win)->battle_stage->player->attack->button_state ==
            PRESSED && (*win)->gamestat->level->player_turn == true &&
            (*win)->gamestat->depressed == true) {
        (*win)->gamestat->depressed = false;
        if (((*player)->mana + 25) <= 100)
            (*player)->mana += 25;
        slash = (slash == true) ? false : true;
        if (slash == true)
            (*win)->gamestat->level->slash = true;
        if (slash == false)
            (*win)->gamestat->level->up_slash = true;
        (*win)->gamestat->level->atk_move = true;
    }
    choice_of_attack_sp(player, enemy, win);
    if ((*enemy)->hp < 0)
        (*enemy)->hp = 0;
}

static void fight_on(battle_t **player, battle_t **enemy, param_win_t **win)
{
    set_life_bar(player, (*win), 1);
    set_life_bar(enemy, (*win), -1);
    player_battle_animation(*win);
    death_bringer_fight_move(*win);
    choice_of_attack(player, enemy, win);
    if ((*win)->battle_stage->player->attack->button_state != PRESSED) {
        (*win)->gamestat->depressed = true;
    }
    if ((*win)->gamestat->level->atk_move == false &&
        (*win)->gamestat->level->player_turn == true)
        print_menu_attack((*win), (*player)->mana);
}

void set_gamestatus(param_win_t *win)
{
    if (win->gamestat->level->level_1 == true){
        win->gamestat->level->level_1 = false;
        win->gamestat->level->level = 2;
    }
    if (win->gamestat->level->level_2 == true){
        win->gamestat->level->level_2 = false;
        win->gamestat->level->level = 3;
    }
    if (win->gamestat->level->level_3 == true){
        win->gamestat->level->level_3 = false;
        win->gamestat->level->level = -1;
    }
    win->gamestat->level->start_fight = false;
    win->gamestat->level->dead_step = false;
    win->gamestat->enable_move = true;
}

void lets_fighting(battle_t **player, battle_t **enemy, param_win_t *win)
{
    fight_on(player, enemy, &win);
}

void start_fight(param_win_t *win)
{
    sfRenderWindow_clear(win->window, sfBlack);
    sfRenderWindow_drawSprite(win->window, win->player->body, NULL);
    sfRenderWindow_drawSprite(win->window, win->battle_stage->sprite, NULL);
    sfRenderWindow_drawSprite(win->window,
        win->battle_stage->player->sprite, NULL);
    sfRenderWindow_drawSprite(win->window,
        win->battle_stage->enemy->sprite, NULL);
    lets_fighting(&win->battle_stage->player, &win->battle_stage->enemy,
        win);
}
