/*
** EPITECH PROJECT, 2024
** set
** File description:
** langage
*/
#include <string.h>
#include "my_rpg.h"

void load_language(param_win_t *win, button_t *button,
    sfVector2f pos, bool language)
{
    sfSprite_setPosition(button->sprite, pos);
    button_management(button, win);
    active_button(button, win);
    if (button->is_active == ACTIVE) {
        if (language)
            win->language = 0;
            else
                win->language = 1;
    }
    free_button(button);
}

void set_language(param_win_t *win, button_t *french, button_t *english)
{
    char *text = duplicate_string(win->language ?
        "Current language " : "Language actuelle ");
    char *language = duplicate_string(win->language ? "english" : "francais");

    text = realloc(text, 50);
    text = strcat(text, language);
    draw_text(text, (sfVector2f) {win->language ?
        780 : 750, 200}, win, 35);
    load_language(win, french, (sfVector2f) {1000, 280}, false);
    load_language(win, english, (sfVector2f) {800, 280}, true);
    free(text);
    free(language);
}
