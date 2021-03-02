/*
** EPITECH PROJECT, 2020
** infin_sub.c
** File description:
** sub
*/
#include "../../include/bistromatic.h"
#include <stdlib.h>

char *myneg(char *str)
{
    int i = 1;
    int j = 0;
    char *dest = malloc(sizeof(char *) * (my_strlen(str) + 2));

    dest[0] = '-';
    if (dest == 0 || str == 0)
        return (dest);
    for (; str[j] != '\0'; j += 1, i++)
        dest[i] = str[j];
    dest[i] = '\0';
    return (dest);
}

char *infin_sub(char *s1, char *s2)
{
    return (infin_add(s1, myneg(s2)));
}
