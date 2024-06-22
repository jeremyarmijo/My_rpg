/*
** EPITECH PROJECT, 2024
** set
** File description:
** previous state
*/
#include "my_rpg.h"

void set_previous_state(main_menu_t *menu)
{
    menu->setting->next->previous_state = init_button(BACK_BUTTON, 0.3, 0.3);
    menu->exit_menu->previous_state = init_button(BACK_BUTTON, 0.3, 0.3);
    menu->saving->previous_state = init_button(BACK_BUTTON, 0.3, 0.3);
    menu->loading->previous_state = init_button(BACK_BUTTON, 0.3, 0.3);
    menu->player_option->previous_state = init_button(BACK_BUTTON, 0.3, 0.3);
    sfSprite_setPosition(menu->player_option->previous_state->sprite,
        (sfVector2f) {750, 870});
    sfSprite_setPosition(menu->loading->previous_state->sprite,
        (sfVector2f) {750, 870});
    sfSprite_setPosition(menu->saving->previous_state->sprite,
        (sfVector2f) {750, 870});
    sfSprite_setPosition(menu->exit_menu->previous_state->sprite,
        (sfVector2f) {750, 870});
    sfSprite_setPosition(menu->setting->next->previous_state->sprite,
        (sfVector2f) {750, 870});
}
