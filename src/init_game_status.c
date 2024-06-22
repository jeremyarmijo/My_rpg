/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include <string.h>
#include "player.h"
#include "my_rpg.h"
#include "ennemy.h"
#include "my_macro.h"

void configure_setting(button_t *setting, main_menu_t *menu)
{
    menu->back_menu_sprite = sfSprite_create();
    menu->back_menu_texture = sfTexture_createFromFile(PATH_BACK_BUTTON, NULL);
    sfSprite_setTexture(menu->back_menu_sprite,
        menu->back_menu_texture, sfTrue);
    sfSprite_setPosition(menu->back_menu_sprite, (sfVector2f) {700, 100});
    sfSprite_setScale(menu->back_menu_sprite, (sfVector2f) {0.7, 0.7});
    setting->next = init_button(P_SETTING_BUTTON,
        "scenes/start/button_large/Settings Button_r.png", 0.30, 0.30);
    sfSprite_setPosition(setting->next->sprite, (sfVector2f) {880, 250});
    menu->setting = setting;
}

void set_position_sprites(button_t *exit_menu, button_t *saving,
    button_t *loading, button_t *player_option)
{
    sfSprite_setPosition(player_option->sprite,
        (sfVector2f) {880, 350});
    sfSprite_setPosition(loading->sprite,
        (sfVector2f) {880, 450});
    sfSprite_setPosition(saving->sprite,
        (sfVector2f) {940, 550});
    sfSprite_setPosition(exit_menu->sprite,
        (sfVector2f) {50, (WINDOW_WIDTH / 2) + 20});
}

static fight_event_t *create_fight_event(void)
{
    fight_event_t *level = malloc(sizeof(fight_event_t));

    level->level_1 = false;
    level->level_2 = false;
    level->level_3 = false;
    level->level = 0;
    level->atk_move = false;
    level->player_turn = true;
    level->end_fight = false;
    level->start_fight = false;
    level->slash = false;
    level->up_slash = false;
    level->atk_sp = false;
    level->ult_sp = false;
    level->enemy_fight = false;
    level->dead_step = false;
    return level;
}

gamestat_t *init_gamestat(void)
{
    gamestat_t *gamestat = malloc(sizeof(gamestat));

    gamestat->start_menu = true;
    gamestat->menu = false;
    gamestat->game_in = false;
    gamestat->in_fight = false;
    gamestat->music = true;
    gamestat->son = true;
    gamestat->enable_move = false;
    gamestat->depressed = true;
    gamestat->run_anim = false;
    gamestat->intro = false;
    gamestat->level = create_fight_event();
    return gamestat;
}

static battle_t *init_caractere(void)
{
    battle_t *tmp = malloc(sizeof(battle_t));

    tmp->hp = 100;
    tmp->atk = 10;
    tmp->def = 10;
    tmp->move = (sfIntRect){0, 0, 0, 0};
    tmp->sprite = NULL;
    tmp->texture = NULL;
    tmp->life_bar = sfRectangleShape_create();
    sfRectangleShape_setFillColor(tmp->life_bar, sfBlack);
    tmp->bord = sfRectangleShape_create();
    sfRectangleShape_setFillColor(tmp->bord, sfWhite);
    tmp->part_of_life = sfRectangleShape_create();
    sfRectangleShape_setFillColor(tmp->part_of_life, sfRed);
    tmp->energy = sfRectangleShape_create();
    sfRectangleShape_setFillColor(tmp->energy, sfBlue);
    tmp->m_tex = NULL;
    tmp->menu_attack = NULL;
    tmp->attack = NULL;
    return tmp;
}

static blank_stage_t *init_battle_stage(void)
{
    blank_stage_t *battle_stage = malloc(sizeof(blank_stage_t));

    battle_stage->sprite = NULL;
    battle_stage->texture = NULL;
    battle_stage->player = init_caractere();
    battle_stage->enemy = init_caractere();
    return battle_stage;
}

static void init_sounds(sound_database_t *sounds)
{
    sounds->hit = sfMusic_createFromFile(MUSIC_PATH_HIT);
    sounds->in_fight = sfMusic_createFromFile(MUSIC_PATH_FIGHT);
}

static void init_config(param_win_t *config, player_t *player)
{
    config->language = true;
    config->gamestat = init_gamestat();
    config->menu = init_menu();
    config->player = player;
    config->click = sfFalse;
    config->battle_stage = init_battle_stage();
}

map_enemy_t *init_map_enemy(void)
{
    map_enemy_t *tmp = malloc(sizeof(map_enemy_t));
    sfIntRect move = {db_idle.left, db_idle.top, db_idle.width,
        db_idle.height};

    tmp->sprite = sfSprite_create();
    tmp->texture = sfTexture_createFromFile("assets/skull.png", NULL);
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    sfSprite_setTextureRect(tmp->sprite, move);
    sfSprite_setOrigin(tmp->sprite, (sfVector2f){db_idle_origin.x,
        db_idle_origin.y});
    sfSprite_setPosition(tmp->sprite, (sfVector2f){1200, 380});
    sfSprite_setScale(tmp->sprite, (sfVector2f){2, 2});
    return tmp;
}

param_win_t *init_game_status(void)
{
    param_win_t *config = malloc(sizeof(param_win_t));
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_LENGTH, BIT_PER_PIXEL};
    player_t *player = init_player("assets/player.png");

    config->window = sfRenderWindow_create(mode, "Epiworld",
        sfResize | sfClose, NULL);
    config->map_enemy = init_map_enemy();
    config->size_window = (sfVector2u) {WINDOW_WIDTH, WINDOW_LENGTH};
    config->main_music = sfMusic_createFromFile(MUSIC_PATH);
    if (!config || !player || !config->window || !config->main_music)
        return NULL;
    config->clock = NULL;
    init_sounds(&config->sounds);
    init_config(config, player);
    sfSprite_setOrigin(player->body, (sfVector2f){idle_origin.x,
        idle_origin.y});
    sfSprite_setPosition(player->body, (sfVector2f) {-1000, -1000});
    return config;
}
