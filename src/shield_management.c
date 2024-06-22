/*
** EPITECH PROJECT, 2024
** shield
** File description:
** management and disp
*/
#include "my_macro.h"
#include "my_rpg.h"

void shield_management(param_win_t *win, sfVector2f pos)
{
    button_t *options = NULL;

    draw_text_dynamic(win, (sfVector2f) {pos.x + 60, pos.y + 10}, " = ",
        win->player->inventory.shield);
    if (win->player->inventory.shield)
        options = init_button(P_POTION, P_POTION_R, 2, 2);
        else {
            options = init_button(P_POTION_R, NULL, 2, 2);
            sfSprite_setPosition(options->sprite, pos);
            sfRenderWindow_drawSprite(win->window, options->sprite, NULL);
            return;
        }
    sfSprite_setPosition(options->sprite, pos);
    button_management(options, win);
    active_button(options, win);
    if (options->is_active == ACTIVE && win->player->inventory.shield > 0) {
        win->player->inventory.shield -= 1;
        win->battle_stage->player->atk += 10;
    }
    free_button(options);
}
