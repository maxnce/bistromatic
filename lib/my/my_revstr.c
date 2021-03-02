/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** write a function that reverses a string.
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char exchanger_ij;

    while (str[j] != '\0') {
        j += 1;
    }
    j -= 1;
    for (; j >= i; j -= 1, i += 1) {
        exchanger_ij = str[i];
        str[i] = str[j];
        str[j] = exchanger_ij;
    }
    return (str);
}
