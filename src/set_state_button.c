/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include "my_rpg.h"
#include "my_macro.h"

void set_state_button(button_t *button, enum statement button_state)
{
    sfTexture_destroy(button->texture);
    if (button_state == NONE && button->paths->is_hover)
        button->texture = sfTexture_createFromFile(
            button->paths->basic, NULL);
    if (button_state == PRESSED && button->paths->is_pressed)
        button->texture = sfTexture_createFromFile(
            button->paths->is_pressed, NULL);
    if (button_state == HOVER && button->paths->basic)
        button->texture = sfTexture_createFromFile(
            button->paths->is_hover, NULL);
    sfSprite_setTexture(button->sprite,
        button->texture, sfTrue);
}

void set_sprite_button_state(button_t *button, param_win_t *win)
{
    if (!is_hover_button(button, win)
        && button->paths->basic) {
        set_state_button(button, NONE);
        button->button_state = NONE;
        return;
    }
    if (win->click == sfTrue
        && is_hover_button(button, win)) {
        if (button->paths->is_pressed)
            set_state_button(button, PRESSED);
        button->button_state = PRESSED;
        return;
    }
    if (button->paths->is_hover) {
        button->button_state = HOVER;
        set_state_button(button, HOVER);
        return;
    }
}
