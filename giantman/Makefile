##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Make nice stuff
##

SRC		=	read_file buffering giantman_main	\
			dict_decompress image_decompress

OBJ		=	$(SRC:%=%.o)

LIBMY	=	../lib/libmy.a

EXEC	=	giantman

all:	$(EXEC)

%.o:	../sources/%.c
	gcc -Wall -Wextra -c -O1 -o $@ $< -Iinclude -I../include

$(EXEC):	$(LIBMY) $(OBJ)
	gcc -o $(EXEC) $(OBJ) -L../lib -lmy

$(LIBMY):
	make -C ../lib/my

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re:	fclean all

.PHONY: all tests_run clean fclean re
