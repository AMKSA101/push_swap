NAME = push_swap

NAME_BONUS = checker

CCF = cc -g -Wall -Wextra -Werror

SRCS =	check_args.c		\
		push_swap.c			\
		ft_split.c			\
		rotate.c			\
		push.c				\
		swap.c				\
		sort_algo.c			\
		lst_funcs.c			\
		rev_rotate.c		\
		other_utils.c		\
		pux_swap_utils.c	\
		sort_algo_utils.c

BONUS_SRCS =	checker.c			\
				ft_check_space.c	\
				swap.c				\
				push.c				\
				rotate.c			\
				ft_split.c			\
				check_args.c		\
				rev_rotate.c		\
				lst_funcs.c			\
				other_utils.c		\
				sort_algo.c			\
				sort_algo_utils.c	\
				get_next_line.c		\
				pux_swap_utils.c	\
				get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CCF) -o $@ $^

$(NAME_BONUS): $(BONUS_OBJS)
	$(CCF) -o $@ $^

%.o: %.c
	@$(CCF) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
