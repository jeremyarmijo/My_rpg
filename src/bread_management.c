/*
** EPITECH PROJECT, 2024
** bread
** File description:
** management
*/
#include "my_macro.h"
#include "my_rpg.h"

void bread_action(button_t *options, param_win_t *win)
{
    if (options->is_active == ACTIVE && win->player->inventory.bread > 0) {
        win->player->inventory.bread -= 1;
        win->battle_stage->player->hp += 10;
        if (win->battle_stage->player->hp > 100)
            win->battle_stage->player->hp = 100;
    }
}

void bread_management(param_win_t *win, sfVector2f pos)
{
    button_t *options = NULL;

    draw_text_dynamic(win, (sfVector2f) {pos.x + 60, pos.y + 10}, " = ",
        win->player->inventory.bread);
    if (win->player->inventory.bread)
        options = init_button(P_BREAD, P_BREAD_R, 2, 2);
        else {
            options = init_button(P_BREAD_R, NULL, 2, 2);
            sfSprite_setPosition(options->sprite, pos);
            sfRenderWindow_drawSprite(win->window, options->sprite, NULL);
            return;
        }
    sfSprite_setPosition(options->sprite, pos);
    button_management(options, win);
    active_button(options, win);
    bread_action(options, win);
    free_button(options);
}
