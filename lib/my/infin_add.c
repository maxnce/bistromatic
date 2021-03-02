/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** infin_add functions
*/
#include "../../include/bistromatic.h"

char get_sign(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            count++;
    }
    if (count%2 == 1) {
        return ('-');
    } else {
        return ('+');
    }
}

int my_numstrlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '-' && str[i] != '+' && (str[i] <= 47 || str[i] >= 58))
            return (count);
        if (str[i] >= 48 && str[i] <= 57)
            count++;
    }
    return (count);
}

int fill_tabs(char const *s1, char *dest1, char const *s2, char *dest2)
{
    int i1 = 0;
    int i2 = 0;
    int index1 = 0;
    int index2 = 0;
    while (dest1[i1] == '0')
        i1++;
    while (dest2[i2] == '0')
        i2++;
    while (s1[index1] != '\0') {
        i1 = my_testnbr(dest1, s1, i1, index1);
        index1++;
    }
    while (s2[index2] != '\0') {
        i2 = my_testnbr(dest2, s2, i2, index2);
        index2++;
    }
    dest2[i2] = '\0';
    dest1[i1] = '\0';
    return (0);
}

int create_numtabs(char const *s1, char *dest1, char const *s2, char *dest2)
{
    int length1 = my_numstrlen(s1);
    int length2 = my_numstrlen(s2);
    int i = 0;
    int lengthmax = length2;

    if (length1 >= length2)
        lengthmax = length1;
    dest1[lengthmax] = '\0';
    dest2[lengthmax] = '\0';
    debug_tab(dest1, dest2);
    if (length1 >= length2) {
        for (; i < length1 - length2; i++)
            dest2[i] = '0';
    } else
        for (; i < length2 - length1; i++)
            dest1[i] = '0';
    fill_tabs(s1, dest1, s2, dest2);
    return (0);
}

char *infin_add(char *s1, char *s2)
{
    char sign1 = get_sign(s1);
    char sign2 = get_sign(s2);
    int length1 = my_numstrlen(s1);
    int length2 = my_numstrlen(s2);
    int lengthmax = length2;
    char *result;

    if (length1 >= length2)
        lengthmax = length1;
    char tab1[lengthmax + 1];
    char tab2[lengthmax + 1];
    create_numtabs(s1, tab1, s2, tab2);
    result = get_op(tab1, tab2, sign1, sign2);
    if (result[0] == '\0')
        return ("0");
    return (result);
}
