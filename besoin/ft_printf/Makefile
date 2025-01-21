NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src/ft_printf.c
OBJ = $(SRC:.c=.o)
INCLUDE = -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

tester:
	${CC} ${CFLAGS} ${SRC} test.c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all