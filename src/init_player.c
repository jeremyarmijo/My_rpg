/*
** EPITECH PROJECT, 2024
** init
** File description:
** player
*/
#include "player.h"
#include "my_rpg.h"

void init_inventory(option_t *inventory)
{
    inventory->skull = 0;
    inventory->speed_potion = 0;
    inventory->shield = 0;
    inventory->apple = 0;
    inventory->bag = false;
    inventory->bread = 0;
    inventory->meat = 0;
    inventory->armor = false;
    inventory->max_item = 1;
}

void player_init_value(player_t *player, sfIntRect move, char *path_picture)
{
    player->level = 0;
    player->save = NOTHING_TO_SAVE;
    player->hp = 100;
    player->mana = 0;
    player->atk = 10;
    player->def = 10;
    player->body = sfSprite_create();
    player->skin = sfTexture_createFromFile(path_picture, NULL);
    player->move = move;
    player->speed = 1.0;
    player->is_moving = false;
    player->is_left = false;
}

player_t *init_player(char *path_picture)
{
    player_t *player = malloc(sizeof(player_t));
    sfIntRect move = {idle_anim.left, idle_anim.top, idle_anim.width,
        idle_anim.height};
    sfVector2f scale = {2, 2};

    init_inventory(&player->inventory);
    player_init_value(player, move, path_picture);
    sfSprite_setTexture(player->body, player->skin, sfTrue);
    sfSprite_setTextureRect(player->body, player->move);
    sfSprite_setScale(player->body, scale);
    return player;
}
