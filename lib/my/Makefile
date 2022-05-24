##
## EPITECH PROJECT, 2021
## libmy
## File description:
## Build libmy
##

SRC	=	$(wildcard sources/*.c)

OBJ	=	$(SRC:sources/%.c=%.o)

HEADER	=	include/my.h

H_DEST	=	../../include/my.h

NAME	=	libmy.a

LIB	=	../libmy.a

all:	$(NAME) $(H_DEST) $(LIB)

%.o:	sources/%.c
	gcc -Wall -Wextra -Wno-unused-parameter -c -o $@ $< -Iinclude

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

$(H_DEST):	$(HEADER)
	mkdir -p ../../include
	cp $(HEADER) $(H_DEST)

$(LIB):		$(NAME)
	cp $(NAME) $(LIB)

re: fclean all

clean:
	rm -f $(OBJ)
	find . \( -name "#*#" -or -name "*~" \
	-or -name "*.gcno" -or -name "*.gcda"  \) -delete

fclean:	clean
	rm -f $(NAME) $(LIB) $(H_DEST)
