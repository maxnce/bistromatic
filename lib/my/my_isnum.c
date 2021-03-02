/*
** EPITECH PROJECT, 2020
** my_str_isnum.c
** File description:
** function that returns 1 if the string passed as parameter
** only contains digits and 0 otherwise
*/

int my_isnum(char const chara)
{
    if ('0' <= chara && chara <= '9')
        return (1);
    return (0);
}
