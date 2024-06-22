/*
** EPITECH PROJECT, 2024
** put
** File description:
** state on NOT ACTIVE
*/

#include "my_rpg.h"

void return_back_state(param_win_t *win)
{
    if (attribute_back_action(win->menu->player_option,
        win->menu->player_option->previous_state, win)) {
        manage_action_player_option(win->menu->player_option, win);
        return;
    }
    if (attribute_back_action(win->menu->loading,
        win->menu->loading->previous_state, win)) {
        manage_action_loading(win->menu->loading, win);
        return;
    }
    if (attribute_back_action(win->menu->saving,
        win->menu->saving->previous_state, win)) {
        manage_action_save(win->menu->saving, win);
        return;
    }
    if (attribute_back_action(win->menu->setting->next,
        win->menu->setting->next->previous_state, win)) {
        manage_action_setting(win->menu->setting->next, win);
        return;
    }
}
