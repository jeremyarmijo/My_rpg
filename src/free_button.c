/*
** EPITECH PROJECT, 2024
** free
** File description:
** function button
*/
#include "player.h"
#include "my_rpg.h"
#include "my_macro.h"

void free_button(button_t *button)
{
    if (button->sprite)
        sfSprite_destroy(button->sprite);
    if (button->texture)
        sfTexture_destroy(button->texture);
    if (button->paths->basic)
        free(button->paths->basic);
    if (button->paths->is_hover)
        free(button->paths->is_hover);
    if (button->paths->is_pressed)
        free(button->paths->is_pressed);
    if (button->paths)
        free(button->paths);
    if (button)
        free(button);
}
