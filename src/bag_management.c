/*
** EPITECH PROJECT, 2024
** bag
** File description:
** management
*/
#include "langage.h"
#include "my_macro.h"
#include "my_rpg.h"

void action_bag(button_t *options, param_win_t *win)
{
    if (options->is_active == ACTIVE) {
        win->player->inventory.bag =
            win->player->inventory.bag ? false : true;
        win->player->inventory.max_item = win->player->inventory.bag ? 15 : 1;
        if (win->player->inventory.apple > 15)
            win->player->inventory.apple = 15;
        if (win->player->inventory.bread > 15)
            win->player->inventory.bread = 15;
        if (win->player->inventory.meat > 15)
            win->player->inventory.meat = 15;
        if (win->player->inventory.shield > 15)
            win->player->inventory.shield = 15;
        if (win->player->inventory.skull > 15)
            win->player->inventory.skull = 15;
        if (win->player->inventory.speed_potion > 15)
            win->player->inventory.speed_potion = 15;
    }
}

void bag_management(param_win_t *win, sfVector2f pos)
{
    button_t *options = NULL;

    draw_text(win->player->inventory.bag ? STRING_ACTIVE : STRING_NOT_ACTIVE
        STRING_F, (sfVector2f) {pos.x + 60, pos.y + 10}, win, 30);
    if (win->player->inventory.bag || win->player->level != 0)
        options = init_button(P_BAG, P_BAG_R, 2, 2);
        else {
            options = init_button(P_BAG_R, NULL, 2, 2);
            sfSprite_setPosition(options->sprite, pos);
            sfRenderWindow_drawSprite(win->window, options->sprite, NULL);
            return;
        }
    sfSprite_setPosition(options->sprite, pos);
    button_management(options, win);
    active_button(options, win);
    action_bag(options, win);
    free_button(options);
}
