/*
** EPITECH PROJECT, 2024
** function
** File description:
** for draw text in window
*/
#include <string.h>
#include <stdio.h>
#include "intro.h"
#include "my_rpg.h"

static void introduction_english(param_win_t *win, int i, sfText *text,
    sfFont *font)
{
    sfText_setString(text, intro_en[i]);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){WINDOW_WIDTH / 2 - 500,
        WINDOW_LENGTH / 2 + 100});
    sfRenderWindow_drawText(win->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

static void introduction_french(param_win_t *win, int i, sfText *text,
    sfFont *font)
{
    sfText_setString(text, intro_fr[i]);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){WINDOW_WIDTH / 2 - 500,
        WINDOW_LENGTH / 2 + 100});
    sfRenderWindow_drawText(win->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

static void call_introduction(param_win_t *win, int i, sfText *text,
    sfFont *font)
{
    if (win->language == false)
        introduction_french(win, i, text, font);
    if (win->language == true)
        introduction_english(win, i, text, font);
}

void draw_intro(param_win_t *win)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("text_font/Arial.ttf");
    static size_t i = 0;
    float seconds = 0;

    if (win->clock == NULL)
        win->clock = sfClock_create();
    if (i != 6){
        call_introduction(win, i, text, font);
        win->time = sfClock_getElapsedTime(win->clock);
        seconds = win->time.microseconds / 100000.0;
        if (seconds > 10.0){
            sfClock_destroy(win->clock);
            win->clock = NULL;
            ++i;
        }
    }
    if (i == 6)
        win->gamestat->intro = false;
}

void draw_text_dynamic(param_win_t *win, sfVector2f pos, char *ref, int nb)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("text_font/Arial.ttf");
    char *to_print = strdup(ref);
    char str[10];

    sprintf(str, "%d", nb);
    to_print = realloc(to_print, strlen(to_print) + 5);
    to_print = strcat(to_print, str);
    sfText_setString(text, to_print);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 35);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f) {pos.x, pos.y});
    sfRenderWindow_drawText(win->window, text, NULL);
    free(to_print);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void draw_text(char *str, sfVector2f pos, param_win_t *win,
    unsigned int police_size)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("text_font/Arial.ttf");

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, police_size);
    sfText_setColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f) {pos.x, pos.y});
    sfRenderWindow_drawText(win->window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}
