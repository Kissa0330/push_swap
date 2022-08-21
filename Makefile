NAME = push_swap.a
FILES = operations/operations_reverse_rotate.c operations/operations_rotate.c operations/operations_swap_push.c utils/operations_utils.c utils/push_swap_utils.c utils/sort_utils.c push_swap.c
OBJS = ${FILES:.c=.o}

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): ${OBJS}
	ar rcs $(NAME) $(OBJS)

.c.o :
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
