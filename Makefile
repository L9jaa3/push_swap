
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_B = checker


SRCS = ./mandatory/ft_split.c \
       ./mandatory/linked_list_fts.c \
       ./mandatory/main.c \
       ./mandatory/utils.c \
       ./mandatory/parcing.c \
       ./mandatory/actions_of_a.c \
       ./mandatory/actions_of_b.c \
       ./mandatory/sort_under_5num.c \
       ./mandatory/push_swap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all bonus
