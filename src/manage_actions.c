/*
** EPITECH PROJECT, 2024
** manage
** File description:
** action
*/
#include <stdio.h>
#include "my_rpg.h"
#include "my_macro.h"

void manage_action_save(button_t *button, param_win_t *win)
{
    sfText* text = sfText_create();
    sfFont* font = sfFont_createFromFile("text_font/Arial.ttf");
    char *to_print = verif_save(1, win,
        win->player->save != NOTHING_TO_SAVE ? TO_SAVE : NOTHING_TO_SAVE);

    if (is_hover_button(button, win)
            && win->click == sfTrue && win->player->save == TO_SAVE) {
        win->click = sfFalse;
        if (save_game())
            to_print = "System error with read";
        sfRenderWindow_waitEvent(win->window, &win->event);
    }
    sfText_setString(text, to_print);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f) {760, 450});
    sfRenderWindow_drawText(win->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void manage_action_loading(button_t *button, param_win_t *win)
{
    sfText* text = sfText_create();
    sfFont* font = sfFont_createFromFile("text_font/Arial.ttf");
    char *to_print = verif_save(2, win,
        win->player->save != NOTHING_TO_SAVE ? TO_SAVE : NOTHING_TO_SAVE);

    if (is_hover_button(button, win)
            && win->click == sfTrue && win->player->save == TO_SAVE) {
        if (save_game())
            to_print = "System error with read";
        win->click = sfFalse;
        sfRenderWindow_waitEvent(win->window, &win->event);
    }
    sfText_setString(text, to_print);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f) {760, 450});
    sfRenderWindow_drawText(win->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

static void win_size_management(param_win_t *win,
    button_t *def_size, button_t *resize)
{
    display_size_win(win, (sfVector2f) {win->language ?
        800 : 820, 450});
    resize_win(win, resize, (sfVector2u) {WINDOW_WIDTH, WINDOW_LENGTH},
        (sfVector2f) {800, 550});
    resize_win(win, def_size,
        (sfVector2u) {RESIZE_WINDOW_WIDTH, RESIZE_WINDOW_LENGTH},
        (sfVector2f) {1000, 550});
}

static void set_volume(button_t *up_volum, button_t *d_volum, param_win_t *win)
{
    display_volume(win, (sfVector2f) {800, 680});
    manage_volume(up_volum, win, (sfVector2f) {990, 740}, true);
    manage_volume(d_volum, win, (sfVector2f) {850, 765}, false);
}

void manage_action_setting(button_t *button, param_win_t *win)
{
    button_t *def_size = init_button(P_RESIZE, P_RESIZE_R, 0.3, 0.3);
    button_t *resize = init_button(P_DEF_SIZE, P_DEF_SIZE_R, 0.3, 0.3);
    button_t *up_volum = init_button(P_PLUS_B, P_PLUS_BR, 0.25, 0.25);
    button_t *d_volum = init_button(P_MINUS_B, P_MINUS_B_R, 0.15, 0.15);
    button_t *english = init_button(P_ANGLAIS, P_ANGLAIS_B, 0.1, 0.1);
    button_t *french = init_button(P_FRENCH, P_FRENCH_B, 0.06, 0.06);

    if (is_hover_button(button, win)
            && win->click == sfTrue) {
        win->click = sfFalse;
        sfRenderWindow_waitEvent(win->window, &win->event);
    }
    set_language(win, english, french);
    set_volume(up_volum, d_volum, win);
    win_size_management(win, def_size, resize);
}

void manage_action_player_option(button_t *button, param_win_t *win)
{
    meat_management(win, (sfVector2f) {800, 200});
    bread_management(win, (sfVector2f) {1000, 200});
    apple_management(win, (sfVector2f) {800, 300});
    shield_management(win, (sfVector2f) {1000, 300});
    speed_potion(win, (sfVector2f) {800, 400});
    skull_management(win, (sfVector2f) {1000, 400});
    bag_management(win, (sfVector2f) {800, 600});
    armor_management(win, (sfVector2f) {800, 500});
    if (is_hover_button(button, win)
            && win->click == sfTrue) {
        win->click = sfFalse;
        sfRenderWindow_waitEvent(win->window, &win->event);
    }
}
