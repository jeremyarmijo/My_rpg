/*
** EPITECH PROJECT, 2024
** skull
** File description:
** number
*/
#include "my_macro.h"
#include "my_rpg.h"

void skull_management(param_win_t *win, sfVector2f pos)
{
    button_t *options = NULL;

    draw_text_dynamic(win, (sfVector2f) {pos.x + 60, pos.y + 10}, " = ",
        win->player->inventory.skull);
    if (win->player->inventory.skull)
        options = init_button(P_SKULL, P_SKULL_R, 2, 2);
        else {
            options = init_button(P_SKULL_R, NULL, 2, 2);
            sfSprite_setPosition(options->sprite, pos);
            sfRenderWindow_drawSprite(win->window, options->sprite, NULL);
            return;
        }
    sfSprite_setPosition(options->sprite, pos);
    button_management(options, win);
    active_button(options, win);
    if (options->is_active == ACTIVE && win->player->inventory.skull > 0) {
        win->player->inventory.skull -= 1;
        win->player->level += 1;
    }
    free_button(options);
}
