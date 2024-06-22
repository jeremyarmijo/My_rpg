/*
** EPITECH PROJECT, 2024
** sounds
** File description:
** manage
*/
#include "my_rpg.h"

void set_default_music(param_win_t *win)
{
    sfMusic_setLoop(win->main_music, sfTrue);
    sfMusic_setLoop(win->sounds.in_fight, sfTrue);
    sfMusic_setLoop(win->sounds.hit, sfTrue);
    sfMusic_play(win->main_music);
}

void hit_sound(param_win_t *win)
{
    sfMusic_play(win->sounds.hit);
    sfRenderWindow_waitEvent(win->window, &win->event);
    sfMusic_pause(win->sounds.hit);
    sfMusic_destroy(win->sounds.hit);
    win->sounds.hit = sfMusic_createFromFile(MUSIC_PATH_HIT);
}

void sound_in_fight(param_win_t *win)
{
    sfMusic_pause(win->main_music);
    sfMusic_play(win->sounds.in_fight);
}

void reset_sound(param_win_t *win)
{
    sfMusic_pause(win->sounds.in_fight);
    sfMusic_play(win->main_music);
}
