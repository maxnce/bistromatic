/*
** EPITECH PROJECT, 2020
** my_putchar_error
** File description:
** error door
*/
#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
