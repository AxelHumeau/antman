##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Make nice stuff
##

SRC		=	read_file buffering antman_main			\
			dict_compress dict_find_occurrences dict_sort	\
			image_compress 					\
			image_write_uncompressed_block	\
			image_write_compressed_block	\
			image_write_xs_compressed_block	\

OBJ		=	$(SRC:%=%.o)

LIBMY	=	../lib/libmy.a

EXEC	=	antman

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
