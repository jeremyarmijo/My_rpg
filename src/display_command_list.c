/*
** EPITECH PROJECT, 2024
** display
** File description:
** the list of command for the game
*/
#include "my_rpg.h"

void disp_sprite_command(char *str, param_win_t *win,
    sfVector2f pos, sfVector2f scale)
{
    button_t *arrow_up = init_button(str,
            NULL, scale.x, scale.y);

    sfSprite_setPosition(arrow_up->sprite,
        pos);
    sfRenderWindow_drawSprite(win->window, arrow_up->sprite, NULL);
    free_button(arrow_up);
}

void display_command_list(param_win_t *win)
{
    draw_text("COMMAND LIST",
        (sfVector2f) {(WINDOW_WIDTH / 2) - 130, (WINDOW_LENGTH / 2) + 170},
            win, 35);
    disp_sprite_command("scenes/settings/escape.jpg", win, (sfVector2f)
        {(WINDOW_WIDTH / 2) + 100,
            (WINDOW_LENGTH / 2) + 300}, (sfVector2f) {0.2, 0.2});
    disp_sprite_command(P_UP_BUTTON, win, (sfVector2f)
            {(WINDOW_WIDTH / 2) - 50,
                (WINDOW_LENGTH / 2) + 240}, (sfVector2f) {0.3, 0.3});
    disp_sprite_command(P_LEFT_BUTTON, win, (sfVector2f)
            {(WINDOW_WIDTH / 2) - 110,
                (WINDOW_LENGTH / 2) + 300}, (sfVector2f) {0.3, 0.3});
    disp_sprite_command(P_RIGHT_BUTTON, win, (sfVector2f)
            {(WINDOW_WIDTH / 2) + 10,
                (WINDOW_LENGTH / 2) + 300}, (sfVector2f) {0.3, 0.3});
    disp_sprite_command(P_DOWN_BUTTON, win, (sfVector2f)
            {(WINDOW_WIDTH / 2) - 50,
                (WINDOW_LENGTH / 2) + 300}, (sfVector2f) {0.3, 0.3});
}
