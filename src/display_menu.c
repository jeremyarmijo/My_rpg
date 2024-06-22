/*
** EPITECH PROJECT, 2024
** display
** File description:
** menu
*/
#include "my_rpg.h"

bool active_button(button_t *button, param_win_t *win)
{
    if (is_hover_button(button, win) && win->click == sfTrue) {
        button->is_active = ACTIVE;
        return true;
    }
    if (button->is_active == ACTIVE) {
        sfRenderWindow_drawSprite(win->window,
            win->menu->back_menu_sprite, NULL);
        return true;
    }
    return false;
}

void reset_action(param_win_t *win)
{
    win->menu->setting->is_active = NOT_ACTIVE;
    win->menu->setting->next->is_active = NOT_ACTIVE;
    win->menu->player_option->is_active = NOT_ACTIVE;
    win->menu->loading->is_active = NOT_ACTIVE;
    win->menu->saving->is_active = NOT_ACTIVE;
}

void init_background_menu(param_win_t *win)
{
    sfRenderWindow_clear(win->window, sfBlack);
    button_management(win->menu->exit_menu, win);
    sfRenderWindow_drawSprite(win->window, win->menu->back_menu_sprite, NULL);
}

bool buttons_are_active(param_win_t *win)
{
    if (win->menu->setting->next->is_active == ACTIVE
        || win->menu->saving->is_active == ACTIVE
        || win->menu->loading->is_active == ACTIVE
        || win->menu->player_option->is_active == ACTIVE)
        return true;
    if (active_button(win->menu->setting->next, win)
        || active_button(win->menu->saving, win)
        || active_button(win->menu->loading, win)
        || active_button(win->menu->player_option, win))
        return true;
    return false;
}

static void all_button_menu(param_win_t *win)
{
    button_management(win->menu->setting->next, win);
    button_management(win->menu->saving, win);
    button_management(win->menu->loading, win);
    button_management(win->menu->player_option, win);
}

void display_menu(param_win_t *win)
{
    init_background_menu(win);
    if (is_hover_button(win->menu->exit_menu, win) && win->click == sfTrue) {
        reset_action(win);
        win->gamestat->menu = false;
        return;
    }
    if (buttons_are_active(win)) {
        return_back_state(win);
        return;
    }
    all_button_menu(win);
    display_command_list(win);
}
