/*
** EPITECH PROJECT, 2024
** time
** File description:
** time
*/

#include "my_rpg.h"

void time_mov(float level)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds = 0;

    while (1){
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / level;
        if (seconds > 1.0){
            sfClock_destroy(clock);
            return;
        }
    }
    return;
}
