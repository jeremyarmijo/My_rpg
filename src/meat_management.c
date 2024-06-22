/*
** EPITECH PROJECT, 2024
** meat
** File description:
** management
*/
#include "my_macro.h"
#include "my_rpg.h"

void meat_action(button_t *options, param_win_t *win)
{
    if (options->is_active == ACTIVE && win->player->inventory.meat > 0) {
        win->player->inventory.meat -= 1;
        win->battle_stage->player->hp += 15;
        if (win->battle_stage->player->hp > 100)
            win->battle_stage->player->hp = 100;
    }
}

void meat_management(param_win_t *win, sfVector2f pos)
{
    button_t *options = NULL;

    draw_text_dynamic(win, (sfVector2f) {pos.x + 60, pos.y + 10}, " = ",
        win->player->inventory.meat);
    if (win->player->inventory.meat)
        options = init_button(P_MEAT, P_MEAT_R, 2, 2);
        else {
            options = init_button(P_MEAT_R, NULL, 2, 2);
            sfSprite_setPosition(options->sprite, pos);
            sfRenderWindow_drawSprite(win->window, options->sprite, NULL);
            return;
        }
    sfSprite_setPosition(options->sprite, pos);
    button_management(options, win);
    active_button(options, win);
    meat_action(options, win);
    free_button(options);
}
