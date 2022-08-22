NAME = push_swap
LIBNAME = lib_push_swap.a
OPT = operations/operations_reverse_rotate.c operations/operations_rotate.c operations/operations_swap_push.c
UTIL = utils/operations_utils.c utils/push_swap_utils.c utils/sort_utils.c
SRCS = $(OPT) $(UTIL) push_swap.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Werror -Wextra

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): ${OBJS}
	ar rcs $(LIBNAME) $(OBJS)
	gcc $(CFLAGS) -o $(NAME) -L. -l_push_swap main.c

.c.o :
	gcc $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBNAME)
	rm -f $(NAME)

re: fclean all
