/*
** EPITECH PROJECT, 2024
** return 1
** File description:
** if true
*/

int cmp_char(char *haystack, char *needle, int i, int len)
{
    int cmp = 0;
    int cpt = 0;

    for (int bis = i; haystack[bis] != '\0'
        && needle[cpt] != '\0'; bis++) {
        if (haystack[bis] == needle[cmp])
            ++cmp;
        ++cpt;
        if (cmp == len)
            return 1;
    }
    return 0;
}

int str_cmp(char *haystack, char *needle, int i, int len)
{
    if (haystack[i] == needle[0]) {
        if (cmp_char(haystack, needle, i, len) == 1)
            return 1;
    }
    return 0;
}

int my_grep(char *haystack, char *needle)
{
    int len = 0;

    if (haystack == 0 || needle == 0)
        return -1;
    while (needle[len] != '\0'){
        ++len;
    }
    for (int i = 0; haystack[i] != '\0'; ++i) {
        if (str_cmp(haystack, needle, i, len) == 1)
            return 1;
    }
    return 0;
}
