/*
** EPITECH PROJECT, 2024
** check
** File description:
** if a game are saved
*/
#include <unistd.h>
#include <fcntl.h>
#include "player.h"
#include "langage.h"
#include "my_rpg.h"
#include "my_macro.h"

char *verif_save(unsigned int nb, param_win_t *win, int save)
{
    int fd = open("save_game/save_game.txt", O_RDWR);

    if (nb == 1) {
        if (fd == -1 && save == NOTHING_TO_SAVE)
            return ERROR_SAVE_E ERROR_SAVE_F;
        fd = open("save_game/save_game.txt", O_CREAT);
        close(fd);
        return SUCCESS_LOAD SUCCESS_LOAD_E SUCCESS_LOAD_F;
    }
    if (nb == 2) {
        if (fd == -1 && save == NOTHING_TO_SAVE)
            return ERROR_LOAD_E ERROR_LOAD_F;
        fd = open("save_game/save_game.txt", O_CREAT);
        close(fd);
        return SUCCESS_SAVE SUCCESS_SAVE_E SUCCESS_SAVE_F;
    }
    return "Error with save";
}
