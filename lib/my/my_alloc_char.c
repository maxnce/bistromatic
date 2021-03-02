/*
** EPITECH PROJECT, 2020
** my_alloc_char
** File description:
** alloc characters
*/
#include <stdlib.h>

char *my_alloc_char(int length, char char_needed)
{
    char *dest = malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i += 1)
        dest[i] = char_needed;
    dest[length] = '\0';
    return (dest);
}
