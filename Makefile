##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Make nice stuff
##

SRC			=	read_file dict_sort dict_find_occurrences	\
				image_write_compressed_block image_compress	\
				image_write_uncompressed_block	\
				image_write_xs_compressed_block

SRC_TEST	=	test_read_file test_find_occurrences \
				test_image_compression

OBJ_TEST	=	$(SRC_TEST:%=%.t.o) $(SRC:%=%.o)

LIBMY		=	lib/libmy.a

TEST		=	unit_tests

all:
	make -C antman
	make -C giantman

tests_run:	clean_cov $(TEST)
	./$(TEST)

%.o:	sources/%.c
	gcc -Wall -Wextra --coverage -c -o $@ $< -Iinclude

%.t.o:	tests/%.c
	gcc -Wall -Wextra -c -o $@ $< -Iinclude

$(TEST):	$(LIBMY) $(OBJ_TEST)
	gcc -o $(TEST) $(OBJ_TEST) -Llib -lmy -lcriterion --coverage

$(LIBMY):
	make -C lib/my

clean_cov:
	find . \( -name "#*#" -or -name "*~" \
	-or -name "*.gcno" -or -name "*.gcda"  \) -delete

clean:	clean_cov
	make -C antman clean
	make -C giantman clean
	rm -f $(OBJ_TEST)

fclean:	clean_cov
	make -C antman fclean
	make -C giantman fclean
	rm -f $(TEST) $(OBJ_TEST)

re:	fclean all

.PHONY: all tests_run clean_cov clean fclean re
