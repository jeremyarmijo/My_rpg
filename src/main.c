/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main function for RPG
*/
#include "my_rpg.h"
#include "my_macro.h"

bool empty_env(char **env)
{
    int nb = 0;

    for (size_t i = 0; env[i]; ++i) {
        if (my_grep(env[i], "PATH"))
            ++nb;
        if (my_grep(env[i], "DISPLAY"))
            ++nb;
    }
    if (nb <= 2)
        return true;
    return false;
}

int main(int, char **, char **env)
{
    if (empty_env(env))
        return EXIT_WITH_ERROR;
    return my_rpg();
}
