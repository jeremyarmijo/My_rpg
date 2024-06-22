/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** displays the number
*/
#include <stdlib.h>

char *duplicate_string(char const *src)
{
    char *dest;
    int cpt2 = 0;
    int cpt = 0;

    if (!src)
        return NULL;
    while (src[cpt] != '\0'){
        cpt += 1;
    }
    dest = malloc((sizeof(char)) * (cpt + 1));
    while (src[cpt2] != '\0'){
        dest[cpt2] = src[cpt2];
        cpt2 += 1;
    }
    dest[cpt2] = '\0';
    return dest;
}
