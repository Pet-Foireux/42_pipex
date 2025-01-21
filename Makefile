CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
LIBFT_DIR = besoin/libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = besoin/ft_printf/src
FT_PRINTF_INC = besoin/ft_printf/includes
FT_PRINTF_SRC = $(FT_PRINTF_DIR)/ft_printf.c \

OBJ = $(SRC:.c=.o) $(FT_PRINTF_SRC:.c=.o)

SRC = main.c besoin.c
INC = -I$(LIBFT_DIR) -I$(FT_PRINTF_INC)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re