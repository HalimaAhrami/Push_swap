
NAME = push_swap

SRCS = input/ft_atoi.c input/ft_split.c input/ft_strdup.c input/ft_strlcpy.c input/is_dup.c input/is_nbr.c operations/push.c operations/reverse_rotate.c operations/rotate.c operations/swap.c sorting/cost.c sorting/push_to_stack_a.c sorting/push_to_stack_b.c sorting/sort_a.c sorting/target.c sorting/utils.c push_swap.c stack/ft_lstadd_back.c stack/ft_lstclear.c stack/ft_lstnew.c stack/ft_lstsize.c 
OBJECT = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) -c  $< -o $@

all: $(NAME)

$(NAME): $(OBJECT)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJECT)

clean:
		@rm -f $(OBJECT) 

fclean: clean
		@rm -f $(NAME)

re: fclean all
.SECONDARY: $(OBJECT)
.PHONY: all  clean fclean re