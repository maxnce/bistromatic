/*
** EPITECH PROJECT, 2020
** decode_op
** File description:
** decode_op
*/

int decode_op(char *str, char *coded, char *normal)
{
    int i = 0;
    int j = 0;

    while (coded[i]) {
        while (str[j]) {
            coded[i] == str[j] ? str[j] == normal[i] : 0;
            j++;
        }
        i++;
        j = 0;
    }
    return (0);
}
