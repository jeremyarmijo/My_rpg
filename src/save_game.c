/*
** EPITECH PROJECT, 2024
** save
** File description:
** progression
*/
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "player.h"
#include "my_rpg.h"
#include "my_macro.h"

bool save_game(void)
{
    int fd = open("save_game/save_game.txt", O_RDWR);
    struct stat info_save;
    char *save = NULL;

    if (stat("save_game/save_game.txt", &info_save) == -1)
        return true;
    save = malloc(sizeof(char) * (info_save.st_size + 1));
    read(fd, save, info_save.st_size);
    save[info_save.st_size] = '\0';
    if (save == NULL)
        return true;
    return false;
}
