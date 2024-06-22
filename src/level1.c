/*
** EPITECH PROJECT, 2024
** level1
** File description:
** scene
*/
#include "my_rpg.h"
#include "ennemy.h"
#include "player.h"

void set_enemy_caractere(param_win_t *win, char *filename, stat_t ennemy)
{
    sfIntRect base = {db_idle.left, db_idle.top, db_idle.width,
            db_idle.height};

    win->battle_stage->enemy->hp = ennemy.hp;
    win->battle_stage->enemy->hp_max = ennemy.hp;
    win->battle_stage->enemy->atk = ennemy.atk;
    win->battle_stage->enemy->def = ennemy.def;
    win->battle_stage->enemy->mana = 0;
    if (win->gamestat->level->level_1 == true)
        win->battle_stage->enemy->sprite = sfSprite_create();
    win->battle_stage->enemy->texture = sfTexture_createFromFile(filename,
        NULL);
    sfSprite_setTexture(win->battle_stage->enemy->sprite,
        win->battle_stage->enemy->texture, sfTrue);
    sfSprite_setTextureRect(win->battle_stage->enemy->sprite, base);
}

void set_player_caractere(param_win_t *win, char *name)
{
    sfIntRect base = {draw_sw.left, draw_sw.top, draw_sw.width,
        draw_sw.height};

    win->battle_stage->player->hp = win->player->hp;
    win->battle_stage->player->mana = win->player->mana;
    win->battle_stage->player->hp_max = win->player->hp;
    win->battle_stage->player->atk = win->player->atk;
    win->battle_stage->player->def = win->player->def;
    win->battle_stage->player->sprite = sfSprite_create();
    win->battle_stage->player->texture =
        sfTexture_createFromFile("assets/hero_battle.png", NULL);
    sfSprite_setTexture(win->battle_stage->player->sprite,
        win->battle_stage->player->texture, sfTrue);
    sfSprite_setTextureRect(win->battle_stage->player->sprite, base);
    win->battle_stage->player->menu_attack = sfSprite_create();
    win->battle_stage->player->m_tex = sfTexture_createFromFile(name, NULL);
    sfSprite_setTexture(win->battle_stage->player->menu_attack,
        win->battle_stage->player->m_tex, sfTrue);
    set_player_caractere_sprite(&win);
}

void set_player_caractere_sprite(param_win_t **win)
{
    sfSprite_setScale((*win)->battle_stage->player->menu_attack,
        (sfVector2f){0.5, 0.5});
    (*win)->battle_stage->player->attack = init_button("assets/espada.png",
        "assets/espada.png", 0.2, 0.2);
    (*win)->battle_stage->player->attack_sp1 = init_button("assets/espada.png",
        "assets/espada.png", 0.2, 0.2);
    (*win)->battle_stage->player->attack_sp2 = init_button("assets/espada.png",
        "assets/espada.png", 0.2, 0.2);
    sfSprite_setPosition((*win)->battle_stage->player->menu_attack,
        (sfVector2f){((WINDOW_WIDTH / 2) - 210), 650});
    sfSprite_setPosition((*win)->battle_stage->player->attack->sprite,
        (sfVector2f){800, 700});
    sfSprite_setPosition((*win)->battle_stage->player->attack_sp1->sprite,
        (sfVector2f){800, 775});
    sfSprite_setPosition((*win)->battle_stage->player->attack_sp2->sprite,
        (sfVector2f){800, 850});
}

static void set_scale_position_for_fight(battle_t **caractere,
    sfVector2f position, sfVector2f scale)
{
    sfSprite_setPosition((*caractere)->sprite, position);
    sfSprite_setScale((*caractere)->sprite, scale);
}

static void set_hp_and_energy_bar(battle_t **caractere, int pos, int coef)
{
    sfRectangleShape_setPosition((*caractere)->life_bar,
        (sfVector2f){pos, 50});
    sfRectangleShape_setPosition((*caractere)->bord,
        (sfVector2f){pos - (coef * 5), 45});
    sfRectangleShape_setPosition((*caractere)->part_of_life,
        (sfVector2f){pos + (coef * 10), 60});
    sfRectangleShape_setPosition((*caractere)->energy,
        (sfVector2f){pos + (coef * 10), 90});
    sfRectangleShape_setSize((*caractere)->bord, (sfVector2f){560 * coef, 85});
    sfRectangleShape_setSize((*caractere)->life_bar,
        (sfVector2f){550 * coef, 75});
}

static void set_scene_fight(param_win_t **win)
{
    (*win)->battle_stage->sprite = sfSprite_create();
    (*win)->battle_stage->texture =
        sfTexture_createFromFile("assets/map_fight_1", NULL);
    sfSprite_setTexture((*win)->battle_stage->sprite,
        (*win)->battle_stage->texture, sfTrue);
    sfSprite_setPosition((*win)->battle_stage->sprite, (sfVector2f){0, 0});
    sfSprite_setScale((*win)->battle_stage->sprite, (sfVector2f){1.5, 1.25});
    set_player_caractere((*win), "assets/menu_attaque");
    set_enemy_caractere((*win), "assets/skull.png", (stat_t){death_bringer.hp,
        death_bringer.atk, death_bringer.def});
    set_scale_position_for_fight(&(*win)->battle_stage->player, (sfVector2f)
        {150, 400}, (sfVector2f){7.5, 7.5});
    set_scale_position_for_fight(&(*win)->battle_stage->enemy, (sfVector2f)
        {1200, 380}, (sfVector2f){4, 4});
    set_hp_and_energy_bar(&(*win)->battle_stage->player, 50, 1);
    set_hp_and_energy_bar(&(*win)->battle_stage->enemy, 1900, -1);
    (*win)->gamestat->level->start_fight = true;
    (*win)->gamestat->enable_move = false;
}

void reset_level(const char *path_map, param_win_t **win,
    sfVector2f size, sfVector2f pos)
{
    (*win)->gamestat->level->player_turn = false;
    (*win)->gamestat->depressed = false;
    (*win)->battle_stage->player->mana = 0;
    (*win)->battle_stage->enemy->mana = 0;
    (*win)->battle_stage->texture =
        sfTexture_createFromFile(path_map, NULL);
    sfSprite_setTexture((*win)->battle_stage->sprite,
        (*win)->battle_stage->texture, sfTrue);
    sfSprite_setPosition((*win)->battle_stage->sprite, pos);
    sfSprite_setScale((*win)->battle_stage->sprite, size);
    (*win)->gamestat->level->start_fight = true;
    (*win)->gamestat->enable_move = false;
}

void level1(param_win_t *win)
{
    if (win->gamestat->level->start_fight == false){
        set_scene_fight(&win);
    }
    start_fight(win);
    if ((win->battle_stage->player->hp <= 0 ||
        win->battle_stage->enemy->hp <= 0) &&
        win->gamestat->level->dead_step == false){
        win->player->inventory.bread = 25;
        win->player->inventory.shield = 10;
        win->gamestat->level->dead_step = true;
    }
}
