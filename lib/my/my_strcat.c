/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** cut
*/
#include "../../include/bistromatic.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int destlen = my_strlen(dest);

    for (i = 0; src[i] != '\0'; i += 1) {
        dest[destlen] = src[i];
        destlen += 1;
    }
    dest[destlen] = '\0';
    return (dest);
}
