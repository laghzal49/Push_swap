NAME = push_swap

SRC = push_swap.c \
      sort_algo/algo1.c \
      sort_algo/simple_sort.c \
      utils/helper_1.c \
      utils/error_check.c \
      moves/push.c \
      moves/swap.c \
      moves/rotate.c \
      moves/reverse_rotate.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -Ilibft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re