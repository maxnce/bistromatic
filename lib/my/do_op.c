/*
** EPITECH PROJECT, 2020
** my_advanced_do_op
** File description:
** calculator
*/

#include "../../include/bistromatic.h"
#include <stdlib.h>

struct operator
{
    char operator;
    char *(*f)(char *, char *);
};

struct operator OPERATORS_FUNCS []= {{'+', &my_add}, {'-', &my_sub}, \
    {'/', &my_div}, {'*', &my_mul}, {'%', &my_mod}};


char *my_strnum(char *str)
{
    int count = 0;
    int i = 0;
    char *new;
    if (str[0] == '-') {
        count++;
        i++;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++, count++);
    new = malloc(sizeof(char) * (count + 1));
    new[count] = '\0';
    for (int j = 0; j < count; j++)
        new[j] = str[j];
    return (new);
}

char *do_op(char *str)
{
    char *nbr_1 = my_strnum(str);
    char *nbr_2;
    int j = 1 + (str[0] == '-');
    char operator;

    for (; my_isnum(str[j - 1]) == 1; j += 1);
    nbr_2 = str + j;
    operator = str[j - 1];
    for (int i = 0; OPERATORS_FUNCS[i].operator != 0; i += 1) {
        if (OPERATORS_FUNCS[i].operator == operator) {
            return (OPERATORS_FUNCS[i].f(nbr_1, nbr_2));
        }
    }
    return (OPERATORS_FUNCS[5].f(nbr_1, nbr_2));
}
