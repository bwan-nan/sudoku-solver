NAME = solver

SRC = ./srcs/*.c

HEADER = ./includes/validity.h \
	./includes/includes.h

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC)

clean:
	/bin/rm -f $(NAME)

re: clean all
