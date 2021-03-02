/*
** EPITECH PROJECT, 2020
** Bistromatic
** File description:
** header for bistromatic
*/

#ifndef BISTROMATIC_H_
#define BISTROMATIC_H_

#define OP_OPEN_PARENT_IDX 0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX 2
#define OP_SUB_IDX 3
#define OP_NEG_IDX 3
#define OP_MULT_IDX 4
#define OP_DIV_IDX 5
#define OP_MOD_IDX 6

#define EXIT_USAGE 84
#define EXIT_BASE 84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC 84
#define EXIT_READ 84
#define EXIT_OPS 84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG "error"

/*char *eval_expr(char const *base, char const *ops,
  char const *expr, unsigned int size);*/

/*lib C Pool*/
int my_putstr(char const *str);
int my_putstr_error(char const *str);
int my_getnbr(char const *str);
int my_isnum(char const chara);
void my_putchar(char c);
void my_putchar_error(char c);
char *my_alloc_char(int length, char char_needed);
char *verif_sign_bistro(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);

/*operation*/
char *my_add(char *s1, char *s2);
char *my_sub(char *s1, char *s2);
char *my_mul(char *s1, char *s2);
char *my_div(char *s1, char *s2);
char *my_mod(char *s1, char *s2);
int my_usage(int nbr_1, int nbr_2);
char *do_op(char *str);

/*struct operator
{
    char operator;
    char *(*f)(char *, char *);
};
extern const struct operator OPERATORS_FUNCS[];*/

/*extern const struct operator OPERATORS_FUNCS[] = {{'+', &my_add}, \
    {'-', &my_sub}, {'/', &my_div}, {'*', &my_mul}, {'%', &my_mod}};
*/
/*const struct operator OPERATORS_FUNCS[] = {{'+', &my_add}, {'-', &my_sub}, \
    {'/', &my_div}, {'*', &my_mul}, {'%', &my_mod}};*/

/*infin_add*/
char *infin_add(char *s1, char *s2);
int my_testnbr(char *dest, char const *src, int i_dest, int i_src);
int debug_tab(char *s1, char *s2);
char get_sign(char const *str);
int my_numstrlen(char const *str);
int fill_tabs(char const *s1, char *dest1, char const *s2, char *dest2);
int create_numtabs(char const *s1, char *dest1, char const *s2, char *dest2);
char *test_display(char *res, char *s1, char *s2, char retenue);
char *get_substract(char *tab1, char *tab2, char sign1, char sign2);
char *get_add(char *tab1, char *tab2, char sign1, char sign2);
void display_complex(char const *str);
int display_simple(char const *str);
char test_sign(char *tab1, char *tab2, char sign1, char sign2);
char *get_op(char *tab1, char *tab2, char sign1, char sign2);
char *my_slice_str(char *src, int n);

/*infin_sub*/
char *myneg(char *str);
char *infin_sub(char *s1, char *s2);

/*infin_mult*/
char *my_add_minus(char *str);
int my_strlen_nosign(char *str);
char *my_nosign(char const *str1);
char *combine_signs(char const *str1, char const *str2, char *str);
char *infin_mult(char *str1, char *str2);
char fill_multab(char *str, char holder, int index);
char adjust_holder(char *str, char holder, int index);
char *my_add_zeros(char *str, int nb);

/*infin_div*/
char *infin_div(char *s1, char *s2);

/*infin_mod*/
char *infin_mod(char *s1, char *s2);

/*bases and different sign of calculus*/
int decode_op(char *str, char *coded, char *normal);

/*error gestion*/
int require_help(void);
int my_unknown_sign(char const *str, char *ops, char *b);
int verify_op_str(char const *str, char *ops, char *b);

#endif
