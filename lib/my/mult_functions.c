/*
** EPITECH PROJECT, 2020
** mult functions
** File description:
** functions for infin mult
*/

char fill_multab(char *str, char holder, int index)
{
    str[index] = holder;
    index--;
    for (; index >= 0; index--)
        str[index] = '0';
    return ('0');
}

char adjust_holder(char *str, char holder, int index)
{
    holder = '0';
    while (str[index] >= 58) {
        str[index] -= 10;
        holder++;
    }
    return (holder);
}
