/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** copy a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (dest == 0 || src == 0)
        return (0);
    for (; src[i] != '\0'; i += 1)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
