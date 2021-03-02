/*
** EPITECH PROJECT, 2020
** my_add_zeros
** File description:
** add n zeros at the end of a string
*/
//#include "../../include/bistromatic.h"
#include <stdlib.h>

char *my_add_zeros(char *str, int nb)
{
    char *dest;
    int i = 0;

    if (nb <= 0)
        return (str);
    dest = malloc(sizeof(char) * (my_strlen(str) + nb + 1));
    for (; str[i]; i++)
        dest[i] = str[i];
    for (; i < (my_strlen(str) + nb); i++)
        dest[i] = '0';
    dest[i] = '\0';
    return (dest);
}
