/*
** EPITECH PROJECT, 2020
** infin_div
** File description:
** infin_div
*/

#include <stdlib.h>

char *return_div(char *nb, char *div, char *res)
{
    char *nb_ns = my_nosign(nb);
    char *div_ns = my_nosign(div);

    if  (my_strcmp(nb_ns, div_ns) == 0 && nb[0] == div[0])
        return ("1");
    if  (my_strcmp(nb_ns, div_ns) == 0 && nb[0] != div[0])
        return ("-1");
    if (my_strcmp(infin_mult(infin_add(res, "1"), div_ns), nb_ns) == 0)
        res = infin_add(res, "1");
    if (my_strcmp(res, "-1") == 0)
        return ("0");
    if (my_strcmp(res, "0") == 0)
        return ("0");
    if ((nb[0] == '-' && div[0] != '-') || nb[0] != '-' && div[0] == '-')
        return (my_add_minus(res));
    return (res);
}

char *slice_nb(char *dest, char *to_slice, int i)
{
    char *new = malloc(sizeof(char) * (my_strlen(dest) + 2));
    char *solo = malloc(sizeof(char) * 2);
    solo[0] = to_slice[0];
    solo[1] = '\0';
    int j = 0;

    if (i == 0) {
        return (solo);
    }
    free(solo);
    while (dest[j]) {
        new[j] = dest[j];
        j++;
    }
    new[j] = to_slice[i];
    new[j+1] = '\0';
    return (new);
}

char *infin_div(char *nb, char *div)
{
    char *nb_ns = my_nosign(nb);
    char *div_ns = my_nosign(div);
    char *sliced = slice_nb("0", nb_ns, 0);
    char *j = "0";
    char *res = "0";
    char *test = infin_sub(sliced, div_ns);
    char *cond;

    for (int i = 1; nb_ns[i - 1]; i++, j = "0") {
        res = infin_mult(res, "10");
        for (; test[0] == '-' && nb_ns[i]; i++, test = infin_sub(sliced, div))
            sliced = slice_nb(sliced, nb_ns, i);
        cond = infin_sub(sliced, infin_add(infin_mult(j, div_ns), div_ns));
        for (; cond[0] != '0' && cond[0] != '-'; j = infin_add(j, "1"))
            cond = infin_sub(sliced, infin_add(infin_mult(j, div_ns), div_ns));
        j = infin_add(j, "-1");
        res = infin_add(res, j);
        sliced = slice_nb(infin_sub(sliced, infin_mult(j, div_ns)), nb_ns, i);
    }
    return (return_div(nb, div, res));
}