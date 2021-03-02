/*
** EPITECH PROJECT, 2020
** debug_tab
** File description:
** fills a tab with spaces
*/

int my_testnbr(char *dest, char const *src, int i_dest, int i_src)
{
    if (src[i_src] <= '9' && src[i_src] >= '0') {
        dest[i_dest] = src[i_src];
        i_dest++;
    }
    return (i_dest);
}

int debug_tab(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        s1[i] = 'D';
        s2[i] = 'D';
        i++;
    }
    return (0);
}
