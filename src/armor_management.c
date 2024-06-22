/*
** EPITECH PROJECT, 2024
** armor
** File description:
** management
*/
#include "langage.h"
#include "my_macro.h"
#include "my_rpg.h"

static void armor_action(button_t *options, param_win_t *win)
{
    if (win->player->inventory.armor)
        win->battle_stage->player->def = 25;
        else
            win->battle_stage->player->def = 10;
    if (options->is_active == ACTIVE) {
        win->player->inventory.armor =
            win->player->inventory.armor ? false : true;
    }
}

void armor_management(param_win_t *win, sfVector2f pos)
{
    button_t *options = NULL;

    draw_text(win->player->inventory.armor ? STRING_ACTIVE : STRING_NOT_ACTIVE
        STRING_F, (sfVector2f) {pos.x + 60, pos.y + 10}, win, 30);
    if (win->player->inventory.armor || win->player->level > 1)
            options = init_button(P_ARMOR, P_ARMOR_R, 2, 2);
        else {
            options = init_button(P_ARMOR_R, NULL, 2, 2);
            sfSprite_setPosition(options->sprite, pos);
            sfRenderWindow_drawSprite(win->window, options->sprite, NULL);
            return;
        }
    sfSprite_setPosition(options->sprite, pos);
    button_management(options, win);
    active_button(options, win);
    armor_action(options, win);
    free_button(options);
}
