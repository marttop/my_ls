##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	my_ls

CC	=	gcc

SRC	=	src/main.c \
		src/flag_parsor.c \
		src/filepath_parsor.c \
		src/my_ls.c \
		src/flag_check.c \
		src/print_flags.c \
		src/sorting_nodes.c \
		src/nodes.c \
		utils/error.c \
		utils/my_strlen.c \
		utils/my_strcat.c \
		utils/my_strdup.c \
		utils/my_ptrlen.c \
		utils/my_putstr.c \
		utils/my_put_nbr.c \
		utils/my_strcmp.c \

SRC_TEST	=	tests/test_all.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-I./include -g3 -O0
FFLAGS = -L/usr/local/lib -lcriterion --coverage
FFLAGS += -fprofile-arcs -ftest-coverage

all	:	$(NAME)

tests_run :
	$(CC) -o test_run -O0 $(CFLAGS) $(FFLAGS) $(SRC_TEST)
	./test_run
coverage :
	/home/mszuts/.local/bin/gcovr --branch --exclude tests/
$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f *gcda *gcno test_run

re	:	fclean all
