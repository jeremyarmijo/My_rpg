/*
** EPITECH PROJECT, 2024
** mainfonction
** File description:
** for rpg
*/
#include <string.h>
#include "my_rpg.h"
#include "my_macro.h"

void close_win(param_win_t **win, scene_start_t *start_scene)
{
    sfRenderWindow_setFramerateLimit((*win)->window, MAX_FRAME);
    sfRenderWindow_clear((*win)->window, sfWhite);
    while (sfRenderWindow_pollEvent((*win)->window, &(*win)->event)){
        if ((*win)->event.type == sfEvtClosed ||
            start_scene->exit_game->button_state == PRESSED)
            sfRenderWindow_close((*win)->window);
        check_event_type((*win));
    }
}
