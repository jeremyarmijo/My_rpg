/*
** EPITECH PROJECT, 2024
** display
** File description:
** stat
*/
#include "my_macro.h"
#include "my_rpg.h"

static void attack_stat(param_win_t *win, button_t *attack, sfVector2f pos)
{
    sfSprite_setPosition(attack->sprite, (sfVector2f) {pos.x, pos.y});
    sfRenderWindow_drawSprite(win->window, attack->sprite, NULL);
    draw_text_dynamic(win, (sfVector2f) {pos.x + 50, pos.y}, " = ",
        win->battle_stage->player->atk);
}

static void def_stat(param_win_t *win, button_t *def, sfVector2f pos)
{
    sfSprite_setPosition(def->sprite, (sfVector2f) {pos.x, pos.y + 50});
    sfRenderWindow_drawSprite(win->window, def->sprite, NULL);
    draw_text_dynamic(win, (sfVector2f) {pos.x + 50, pos.y + 50}, " = ",
        win->battle_stage->player->def);
}

static void hp_stat(param_win_t *win, button_t *hp, sfVector2f pos)
{
    sfSprite_setPosition(hp->sprite, (sfVector2f) {pos.x, pos.y + 100});
    sfRenderWindow_drawSprite(win->window, hp->sprite, NULL);
    draw_text_dynamic(win, (sfVector2f) {pos.x + 50, pos.y + 100}, " = ",
        win->battle_stage->player->hp);
}

void display_stat(param_win_t *win, sfVector2f pos)
{
    button_t *attack = init_button(P_ATTACK, NULL, 1.4, 1.4);
    button_t *def = init_button(P_DEF, NULL, 1.4, 1.4);
    button_t *hp = init_button(P_HP, NULL, 1.4, 1.4);
    button_t *background = init_button("assets/menu_attaque",
        "assets/menu_attaque", 0.2, 0.25);

    sfSprite_setPosition(background->sprite,
        (sfVector2f) {pos.x - 10, pos.y - 10});
    sfRenderWindow_drawSprite(win->window, background->sprite, NULL);
    attack_stat(win, attack, pos);
    def_stat(win, def, pos);
    hp_stat(win, hp, pos);
    free_button(attack);
    free_button(def);
    free_button(hp);
    free_button(background);
}
