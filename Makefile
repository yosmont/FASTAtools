##
## EPITECH PROJECT, 2018
## yet another Makefile
## File description:
## not a copy of a exemple Makefile... not at all
##

NAME	=	FASTAtools

SRC	=	src/main.c	\
		src/get_fasta.c	\
		src/print.c	\
		src/print_two.c	\
		src/lib.c	\
		src/gnl_redux.c	\
		src/free.c	\
		src/opt_four.c	\
		src/opt_five.c	\
		src/opt_six.c	\
		src/opt_seven.c	\
		src/matric.c

CFLAGS	+=	-Wall -Wextra -Iinclude/

DFLAG	+=	-g

OBJ	=	$(SRC:.c=.o)

all:		$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)
	@echo "┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┌┬┐┌─┐┬┬  ┬┌┐┌┌─┐   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  │  │ ││││├─┘││  │││││ ┬   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  └─┘└─┘┴ ┴┴  ┴┴─┘┴┘└┘└─┘┘   ┴ ┴ ┴┴ ┴o"

clean:
	rm -f $(OBJ)
	@echo "┌─┐┌┐┌┌┬┐  ┌─┐┬  ┌─┐┌─┐┌┐┌   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  │  │  ├┤ ├─┤│││   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  └─┘┴─┘└─┘┴ ┴┘└┘┘   ┴ ┴ ┴┴ ┴o"

fclean:		clean
	rm -f $(NAME)
	@echo "┌─┐┌┐┌┌┬┐  ┌─┐┌─┐┬  ┌─┐┌─┐┌┐┌   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  ├┤ │  │  ├┤ ├─┤│││   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  └  └─┘┴─┘└─┘┴ ┴┘└┘┘   ┴ ┴ ┴┴ ┴o"

re:		fclean all
	@echo "┌─┐┌┐┌┌┬┐  ┬─┐┌─┐   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││  ├┬┘├┤    └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘  ┴└─└─┘┘   ┴ ┴ ┴┴ ┴o"

bonus:
	cd bonus; make; make clean
	cp bonus/FASTA_bonus FASTA_bonus
	@echo "┌─┐┌┐┌┌┬┐ ┌─┐┌─┐┌┬┐┌─┐┬┬  ┬┌┐┌┌─┐  ┌┐ ┌─┐┌┐┌┬ ┬┌─┐   ┬ ┬┌─┐┌┬┐┬"
	@echo "├┤ │││ ││ │  │ ││││├─┘││  │││││ ┬  ├┴┐│ │││││ │└─┐   └┬┘├─┤││││"
	@echo "└─┘┘└┘─┴┘ └─┘└─┘┴ ┴┴  ┴┴─┘┴┘└┘└─┘  └─┘└─┘┘└┘└─┘└─┘┘   ┴ ┴ ┴┴ ┴o"

.PHONY: 	all clean fclean re bonus
