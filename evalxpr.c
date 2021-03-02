/*
** EPITECH PROJECT, 2020
** evalxpr
** File description:
** manage priority of calculus
*/
#include "include/bistromatic.h"
#include <stdlib.h>

char *verif_sign_bistro(char *str)
{
    char *new;
    int len = my_strlen(str);
    int i = 0;
    int j = 1;

    if (str[0] == '-' && str[1] == '-') {
        new = malloc(sizeof(char) * (len));
        for (; str[j]; i++, j++){
            new[i] = str[j];
        }
        free(str);
        return (new);
    }
    return (str);
}

char *operation(char *str, int i)
{
    char *result_operation = my_alloc_char(my_strlen(str), 0);
    char *temp = my_alloc_char(my_strlen(str), 0);
    int j;


    result_operation = my_alloc_char(my_strlen(str), 0);
    temp = my_alloc_char(my_strlen(str), 0);
    for (; my_isnum(str[i - 1]) == 1 || (str[i - 1] == '-' &&
    my_isnum(str[i - 2]) == 0) || (str[i - 1] == '-' && i == 1); i -= 1);
    j = i;
    j += (str[j] == '-');
    for (; my_isnum(str[j]) == 1; j += 1);
    j += 1;
    j += (str[j] == '-');
    for (; my_isnum(str[j]) == 1; j += 1);
    result_operation = do_op(str + i);
    temp = my_strcat(my_slice_str(str, i), result_operation);
    str = my_strcat(temp, str + j);
    return (str);
}

char *concat(char *str, int i, int first_parenthesis)
{
    int j;

    for (j = (i + 1); my_isnum(str[j]) == 1; j += 1);
    if (str[j - 1] == ')') {
        str = my_strcat(my_slice_str(str, i), str + i + 1);
        i = first_parenthesis;
        str = my_strcat(my_slice_str(str, i), str + i + 1);
        return (str);
    }
    for (j = 0; str[j] != '\0'; j += 1);
    if (str[j] == '\0')
        return (str);
    return (0);
}

char *parenthesis(char *str, int i)
{
    int first_parenthesis = i;

    for (; str[i] != ')' && str[i] != '\0'; i += 1)
        if (str[i] == '/' || str[i] == '*' || str[i] == '%') {
            str = operation(str, i);
            i = first_parenthesis;
        }
    i = first_parenthesis;

    for (; str[i] != ')' && str[i] != '\0'; i += 1)
        if ((str[i] == '-' && (my_isnum(str[i - 1]) == 1 && i != 0)) ||
        str[i] == '+') {
            str = operation(str, i);
            i = first_parenthesis;
        }

    return (concat(str, i, first_parenthesis));
}

char *eval_expr(char const *str)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));

    result = my_strcpy(result, str);
    for (int i = 0; result[i] != '\0'; i += 1) {
        if (result[i] == ')') {
            for (; result[i] != '('; i -= 1);
            result = parenthesis(result, i);
            i = 0;
        }
    }
    result = parenthesis(result, 0);
    return (result);
}
