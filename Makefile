##
## Thibault PROJECT, 2021
## Makefile
## File description:
## Makefile
##



SRC     =	probleme-01/ex01.c		\

SRC1	=	probleme-02/ex02.c		\

SRC2	=	probleme-03/ex03.c		\
		probleme-03/deplacement.c	\

OBJ     =	$(SRC:.c=.o)

OBJ1	=	$(SRC1:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

NAME    =	ex01

NAME1	=	ex02

NAME2	=	ex03

all:    $(NAME)

$(NAME):	$(OBJ) $(OBJ1) $(OBJ2)
	gcc -o $(NAME) $(OBJ)
	gcc -o $(NAME1) $(OBJ1)
	gcc -o $(NAME2) $(OBJ2)
clean:
	rm -f $(OBJ) *~
	rm -f $(OBJ1) *~
	rm -f $(OBJ2) *~

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME1)
	rm -f $(NAME2)

re:     fclean all

.PHONY: all clean fclean re
