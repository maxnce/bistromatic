/*
** EPITECH PROJECT, 2020
** Bistromatic
** File description:
** Infin_mult
*/
#include "../../include/bistromatic.h"
#include <stdlib.h>

char *my_add_minus(char *str)
{
    char *res = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 1;
    int j = 0;

    res[0] = '-';
    while (str[j]) {
        res[i] = str[j];
        i++;
        j++;
    }
    res[i] = '\0';
    return (res);
}

int my_strlen_nosign(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            count++;
        }
        i++;
    }
    return (count);
}

char *my_nosign(char const *str1)
{
    char *res = malloc(sizeof(char) * (my_strlen_nosign(str1) + 1));
    int i = 0;
    int j = 0;

    while (str1[i]) {
        if (str1[i] <= '9' && str1[i] >= '0') {
            res[j] = str1[i];
            j++;
        }
        i++;
    }
    res[j] = '\0';
    return (res);
}

char *combine_signs(char const *str1, char const *str2, char *str)
{
    if ((str1[0] == '-' && str2[0] != '-' && str[0] != '0') || str1[0] != '-' &&
        (str2[0] == '-' && str[0] != '0'))
        return (my_add_minus(str));
    return (str);
}

char *infin_mult(char *str1, char *str2)
{
    char *s1 = my_nosign(str1);
    char *s2 = my_nosign(str2);
    int len = my_strlen_nosign(s2) - 1;
    int j = my_strlen_nosign(s1) + my_strlen_nosign(s2) + 2;
    int val = j - 1;
    char holder = '0';
    char *res = malloc(sizeof(char) * (my_strlen(s2) + my_strlen(s1) + 1));
    char *final = "0";
    res[j] = '\0';
    j--;
    for (int count = 0; len >= 0; len--, count++) {
        j = val;
        for (int i = my_strlen_nosign(s1) - 1; i >= 0; i--, j--) {
            res[j] = (s1[i] - 48) * (s2[len] - 48) + holder;
            holder = adjust_holder(res, holder, j);
        }
        holder = fill_multab(res, holder, j);
        final = infin_add(final, my_add_zeros(res, count));
    }
    final = combine_signs(str1, str2, final);
    return (final);
}