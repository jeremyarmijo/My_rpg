/*
** EPITECH PROJECT, 2024
** speed
** File description:
** potion
*/
#include "my_macro.h"
#include "my_rpg.h"

void speed_action(button_t *options, param_win_t *win)
{
    if (options->is_active == ACTIVE
        && win->player->inventory.speed_potion > 0) {
        win->player->inventory.speed_potion -= 1;
        win->player->speed += 3;
    }
}

void speed_potion(param_win_t *win, sfVector2f pos)
{
    button_t *options = NULL;

    draw_text_dynamic(win, (sfVector2f) {pos.x + 60, pos.y + 10}, " = ",
        win->player->inventory.speed_potion);
    if (win->player->inventory.speed_potion)
        options = init_button(P_SPEED, P_SPEED_R, 2, 2);
        else {
            options = init_button(P_SPEED_R, NULL, 2, 2);
            sfSprite_setPosition(options->sprite, pos);
            sfRenderWindow_drawSprite(win->window, options->sprite, NULL);
            return;
        }
    sfSprite_setPosition(options->sprite, pos);
    button_management(options, win);
    active_button(options, win);
    speed_action(options, win);
    free_button(options);
}
