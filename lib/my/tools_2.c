/*
** EPITECH PROJECT, 2020
** tools_2
** File description:
** tools_2
*/
#include <unistd.h>
#include <stdlib.h>
#include "../../include/bistromatic.h"

int require_help(void)
{
    write(1, "USAGE\n./calc base operators size_read\n\n", 39);
    write(1, "DESCRIPTION\n- base: all the symbols of the base\n", 48);
    write(1, "- operators: the symbols for the parantheses ", 45);
    write(1, "and the 5 operators\n", 20);
    write(1, "- size_read: number of characters ", 34);
    write(1, "to be read\n", 11);
}

int my_unknown_sign(char const *str, char *ops, char *b)
{
    int j = 0;
    int n = 0;
    for (int i = 0; str[i]; i++) {
        for (j = 0; b[j] && j != -1; j++)
            str[i] == b[j] ? j = -2 : 0;
        for (n = 0; ops[n] && j != -1 && n != -1; n++)
            str[i] == ops[n] ? n = -2 : 0;
        if (j == my_strlen(b) && n == my_strlen(ops)) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_OPS);
        }
    }
    return (0);
}

int verify_op_str(char const *str, char *ops, char *b)
{
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if ((str[i] == '*' || str[i] == '/' || str[i] == '%') && (i == 0 ||
        (str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == '%') ||
        str[i + 1] == '\0')) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_OPS);
        }
        if (str[i] == '(')
            count++;
        if (str[i] == ')')
            count--;
    }
    if (count != 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    return (my_unknown_sign(str, ops, b));
}

char *my_slice_str(char *src, int n)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src)));
    int i;

    for (i = 0; src[i] != '\0' && i < n; i += 1)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
