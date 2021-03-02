/*
** EPITECH PROJECT, 2020
** infin_add
** File description:
** op
*/
#include "../../include/bistromatic.h"
#include <stdlib.h>

char *verify_str(char const *str)
{
    char *dest;
    char *dest2;
    int len = my_strlen(str);
    int i = 0;
    int j = len - 1;
    int k = 0;

    str[0] == '+' ? len-- : 0;
    for (; str[k] == '0' || str[k] == '-' || str[k] == '+'; k++, i++)
        len--;
    dest = malloc(sizeof(char) * (len + 1));
    dest[len] = '\0';
    str[0] == '-' ? dest[0] = '-' : 0;
    for (; j >= i; j--)
        dest[j - i] = str[j];
    if (str[0] == '-') {
        dest2 = my_add_minus(dest);
        return (dest2);
    }
    return (dest);
}

char *test_display(char *res, char *s1, char *s2, char retenue)
{
    res[1] = retenue;
    if (res[2] < s1[0] + s2[0] - 48) {
        display_complex(res);
    } else {
        display_simple(res);
    }
}

char *get_substract(char *tab1, char *tab2, char sign1, char sign2)
{
    char retenue = '0';
    int length = my_strlen(tab1);
    char res[length + 3];
    int i = length + 3;
    int index = length - 1;
    char *final;

    res[i] = '\0';
    i--;
    for (; i >= 2; i--, index--) {
        res[i] = tab1[index] - tab2[index] + 48 - retenue + 48;
        if ((tab1[index] - tab2[index] + 48 - retenue + 48) <= 47) {
            res[i] += 10;
            retenue = '1';
        } else
            retenue = '0';
    }
    res[1] = '0';
    res[0] = test_sign(tab1, tab2, sign1, sign2);
    final = verify_str(res);
    return (final);
}

char *get_add(char *tab1, char *tab2, char sign1, char sign2)
{
    char retenue = '0';
    char res[my_strlen(tab1) + 3];
    int index = my_strlen(tab1) - 1;
    int i = index + 3;
    char *final;

    res[i] = '\0';
    i--;
    for (; i > 1; i--, index--) {
        res[i] = tab1[index] + tab2[index] - 48 + (retenue - 48);
        if ((tab1[index] + tab2[index] - 48 + retenue - 48) >= 58) {
            res[i] -= 10;
            retenue = '1';
        } else
            retenue = '0';
    }
    res[0] = test_sign(tab1, tab2, sign1, sign2);
    res[1] = retenue;
    final = verify_str(res);
    return (final);
}
