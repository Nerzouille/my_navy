##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard	sources/*.c)
PATHLIB	=	.
NAME	=	my_navy

all:	libcomp	build

libcomp:
	$(MAKE)	-C	./lib/my

build:
	gcc $(SRC) -o $(NAME) -L$(PATHLIB) -lmy -Iinclude/ -lm -fPIE -g3

clean:
	make -C lib/my clean

fclean:	clean
	rm	-fr	$(NAME)

re:	fclean	all
