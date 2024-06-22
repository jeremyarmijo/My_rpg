/*
** EPITECH PROJECT, 2024
** increase and decrease
** File description:
** the vulome of the game music
*/
#include "my_rpg.h"
#include "my_macro.h"

void manage_volume(button_t *button, param_win_t *win, sfVector2f pos
    , bool which)
{
    float ref_volume = sfMusic_getVolume(win->main_music);

    sfSprite_setPosition(button->sprite, pos);
    button_management(button, win);
    active_button(button, win);
    if (button->is_active == ACTIVE && which == true)
        ++ref_volume;
    if (button->is_active == ACTIVE && which == false) {
        reset_sound(win);
        hit_sound(win);
        --ref_volume;
    }
    sfMusic_setVolume(win->main_music, ref_volume);
    free_button(button);
}
