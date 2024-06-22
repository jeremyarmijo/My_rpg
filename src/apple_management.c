/*
** EPITECH PROJECT, 2024
** apple
** File description:
** manage
*/
#include "my_macro.h"
#include "my_rpg.h"

static void action_apple(button_t *options, param_win_t *win)
{
    if (options->is_active == ACTIVE && win->player->inventory.apple > 0) {
        win->player->inventory.apple -= 1;
        win->battle_stage->player->hp += 5;
        if (win->battle_stage->player->hp > 100)
            win->battle_stage->player->hp = 100;
    }
}

void apple_management(param_win_t *win, sfVector2f pos)
{
    button_t *options = NULL;

    draw_text_dynamic(win, (sfVector2f) {pos.x + 60, pos.y + 10}, " = ",
        win->player->inventory.apple);
    if (win->player->inventory.apple)
            options = init_button(P_APPLE, P_APPLE_R, 2, 2);
        else {
            options = init_button(P_APPLE_R, NULL, 2, 2);
            sfSprite_setPosition(options->sprite, pos);
            sfRenderWindow_drawSprite(win->window, options->sprite, NULL);
            return;
        }
    sfSprite_setPosition(options->sprite, pos);
    button_management(options, win);
    active_button(options, win);
    action_apple(options, win);
    free_button(options);
}
