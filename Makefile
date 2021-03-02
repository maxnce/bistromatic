##
## EPITECH PROJECT, 2020
## makefile
## File description:
## gcc etc...
##

CFLAGS = -Wall -Wextra -g3 -I./include

SRC	=	evalxpr.c

MAIN	=	main.c

TEST	=	Tests/evalexpr_main.c

TEST_NAME	=	test_evalexpr

OBJ 	=	$(SRC:.c=.o) $(MAIN:.c=.o)

NAME	=	calc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my
		gcc -o $(NAME) $(SRC) $(MAIN) $(CFLAGS) -L./lib -lmy

clean:
	rm -f $(NAME)
	rm -f *.o

fclean: clean
	make fclean -C ./lib/my

re: fclean all

test_run:
	gcc -o $(TEST_NAME) $(SRC) $(TEST) $(CFLAGS) -L./lib -lmy -lcriterion
	./$(TEST_NAME)
