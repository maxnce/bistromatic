/*
** EPITECH PROJECT, 2020
** operation
** File description:
** all operations needed for doop
*/
#include "../../include/bistromatic.h"

char *my_add(char *s1, char *s2)
{
    return (infin_add(s1, s2));
}

char *my_sub(char *s1, char *s2)
{
    return (infin_sub(s1, s2));
}

char *my_div(char *nbr_1, char *nbr_2)
{
    if (my_strcmp(nbr_2, "0") == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_USAGE);
    }
    return (infin_div(nbr_1, nbr_2));
}

char *my_mul(char *s1, char *s2)
{
    return (infin_mult(s1, s2));
}

char *my_mod(char *nbr_1, char *nbr_2)
{
    if (my_strcmp(nbr_2, "0") == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_USAGE);
    }
    return (infin_mod(nbr_1, nbr_2));
}
