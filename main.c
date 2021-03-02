/*
** EPITECH PROJECT, 2020
** main.evalxpr
** File description:
** main
*/
#include "include/bistromatic.h"
#include <stdlib.h>
#include <unistd.h>

char *eval_expr(char const *str);

char *verif_sign_bistro(char *str);

static void check_syntax(char const *ops, char const *b, char const *str)
{
    int test;
    for (int i = 0; ops[i]; i++) {
        for (int j = 0; b[j]; j++) {
            if (ops[i] == b[j]) {
                my_putstr(SYNTAX_ERROR_MSG);
                exit(EXIT_OPS);
            }
        }
    }
    test = verify_op_str(str, ops, b);
    if (test == 84) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_ops(char const *ops)
{
    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    for (int i = 0; ops[i]; i++) {
        for (int j = 0; ops[j]; j++) {
            if (i == j)
                j++;
            if (ops[i] == ops[j]) {
                my_putstr(SYNTAX_ERROR_MSG);
                exit(EXIT_OPS);
            }
        }
    }
}

static void check_base(char const *b)
{
    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    for (int i = 0; b[i]; i++) {
        for (int j = 0; b[j]; j++) {
            if (i == j)
                j++;
            if (b[i] == b[j]) {
                my_putstr(SYNTAX_ERROR_MSG);
                exit(EXIT_BASE);
            }
        }
    }
}

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(size + 1);
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

int main(int ac, char **av)
{
    char *expr;
    int size;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (require_help());
    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base operators size_read\n");
        return (EXIT_USAGE);
    }
    check_base(av[1]);
    check_ops(av[2]);
    size = my_getnbr(av[3]);
    expr = get_expr(size);
    decode_op(expr, av[2], "()+-*/%");
    check_syntax(av[2], av[1], expr);
    my_putstr(verif_sign_bistro(eval_expr(expr)));
    return (0);
}
