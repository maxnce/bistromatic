/*
** EPITECH PROJECT, 2020
** my_putstr_error
** File description:
** error door
*/
#include "../../include/bistromatic.h"

int my_putstr_error(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar_error(str[i]);
}
