/*
** EPITECH PROJECT, 2020
** bistromatic
** File description:
** Modulo operation of the calculator
*/
#include "../../include/bistromatic.h"

char *infin_mod(char *nb, char *modulo)
{
    char *div = infin_div(nb, modulo);

    if ((my_strlen_nosign(modulo) > my_strlen_nosign(nb)) ||
        (my_strlen_nosign(modulo) == my_strlen_nosign(nb) &&
        my_strcmp(my_nosign(nb), my_nosign(modulo)) == -1))
        return (nb);
    if (my_strcmp(infin_mult(div, modulo), nb) != 0) {
        return (infin_sub(nb, infin_mult(div, modulo)));
    }
    return ("0");
}
