/*
** EPITECH PROJECT, 2024
** level
** File description:
** scene
*/
#include "my_rpg.h"
#include "ennemy.h"
#include "player.h"

void print_menu_attack(param_win_t *win, int mana)
{
    sfRenderWindow_drawSprite(win->window,
        win->battle_stage->player->menu_attack, NULL);
    button_management(win->battle_stage->player->attack, win);
    draw_text("+25 mana", (sfVector2f) {910, 730}, win, 18);
    if (mana >= 50) {
        draw_text("atk +25\n-50 mana", (sfVector2f) {910, 800}, win, 18);
        button_management(win->battle_stage->player->attack_sp1, win);
    }
    if (mana == 100) {
        draw_text("atk +50\n-100 mana", (sfVector2f) {910, 870}, win, 18);
        button_management(win->battle_stage->player->attack_sp2, win);
    }
}

void level2(param_win_t *win)
{
    if (win->gamestat->level->start_fight == false) {
        reset_level("assets/map_3.png", &win, (sfVector2f)
            {4, 4}, (sfVector2f) {0, -290});
        win->battle_stage->enemy->hp = 300;
        win->battle_stage->enemy->hp_max = 300;
        win->battle_stage->enemy->atk = 40;
        win->battle_stage->enemy->def = 15;
        win->gamestat->level->player_turn = true;
    }
    start_fight(win);
    if ((win->battle_stage->player->hp <= 0 ||
        win->battle_stage->enemy->hp <= 0) &&
        win->gamestat->level->dead_step == false){
        win->player->inventory.apple = 5;
        win->player->inventory.bread = 15;
        win->player->inventory.shield = 5;
        win->gamestat->level->dead_step = true;
    }
}

void level3(param_win_t *win)
{
    if (win->gamestat->level->start_fight == false) {
        reset_level("assets/map_4.png", &win, (sfVector2f)
            {4.1, 4.1}, (sfVector2f) {0, -195});
        win->battle_stage->enemy->hp = 500;
        win->battle_stage->enemy->hp_max = 500;
        win->battle_stage->enemy->atk = 50;
        win->battle_stage->enemy->def = 25;
        win->gamestat->level->player_turn = true;
    }
    start_fight(win);
    if ((win->battle_stage->player->hp <= 0 ||
        win->battle_stage->enemy->hp <= 0) &&
        win->gamestat->level->dead_step == false){
        win->gamestat->level->dead_step = true;
    }
}
