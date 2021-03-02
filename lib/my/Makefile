##
## EPITECH PROJECT, 2020
## makefile lib
## File description:
## compile lib
##

SRC	=	debug_tab.c \
		decode_op.c \
		do_op.c \
		infin_add.c \
		infin_div.c \
		infin_mod.c \
		infin_mult.c \
		infin_sub.c \
		mult_functions.c \
		my_add_zeros.c \
		my_alloc_char.c \
		my_getnbr.c \
		my_isnum.c \
		my_putchar.c \
		my_putchar_error.c \
		my_putstr.c \
		my_putstr_error.c \
		my_revstr.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strlen.c \
		operation.c \
		operations.c \
		res_display.c \
		tools_2.c

OBJ	=	 $(SRC:.c=.o)

NAME	=	libmy.a

ALL:	$(NAME)
		cp bistromatic.h ../../include/
		cp $(NAME) ..

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
