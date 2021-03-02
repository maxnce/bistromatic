/*
** EPITECH PROJECT, 2020
** infin_add res & display
** File description:
** calculates the res ans displays the answer
*/
#include <unistd.h>
#include "../../include/bistromatic.h"

void display_complex(char const *str)
{
    if (str[0] == '-')
        my_putchar('-');
    int i = 2;
    while (str[i] <= 57 && str[i] >= 48) {
        my_putchar(str[i]);
        i++;
    }
    my_putchar('\n');
}

int display_simple(char const *str)
{
    int index = 1;
    int booltest = 0;
    if (str[0] == '-')
        my_putchar('-');
    while (booltest == 0 && str[index]) {
        if (str[index] != '0')
            booltest = 1;
        index++;
    }
    my_putchar(str[index-1]);
    while (str[index] <= 57 && str[index] >= 48) {
        my_putchar(str[index]);
        index++;
    }
    my_putchar('\n');
    return (0);
}

char test_sign(char *tab1, char *tab2, char sign1, char sign2)
{
    int test = my_strcmp(tab1, tab2);
    if (sign1 == '+' && sign2 == '+')
        return (sign1);
    if (sign1 == '-' && sign2 == '-')
        return (sign1);
    if (test > 0)
        return (sign1);
    if (test == 0)
        return ('+');
    if (test < 0)
        return (sign2);
    return (0);
}

char *get_op(char *tab1, char *tab2, char sign1, char sign2)
{
    int testneg;
    char *final;

    if (sign1 == '-' && sign2 == '-' && my_strcmp(tab1, tab2) == 0) {
        return ("0");
    }
    if ((sign1 == '-' && sign2 == '-') || (sign1 == '+' && sign2 == '+')) {
        final = get_add(tab1, tab2, sign1, sign2);
        return (final);
    } else {
        testneg = my_strcmp(tab1, tab2);
        if (testneg == 1)
            return (get_substract(tab1, tab2, sign1, sign2));
        if (testneg == -1)
            return (get_substract(tab2, tab1, sign2, sign1));
        if (testneg == 0)
            return ("0");
    }
    return ("0");
}
