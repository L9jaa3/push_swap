CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS = ./mandatory/ft_split.c \
		./mandatory/linked_list_fts.c \
		./mandatory/main.c \
		./mandatory/utils.c \
		./mandatory/parcing.c \
		./mandatory/actions_of_a.c \
		./mandatory/actions_of_b.c \
		./mandatory/sort_under_5num.c \
		./mandatory/push_swap.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o  $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 