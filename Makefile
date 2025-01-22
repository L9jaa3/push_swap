
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


SRCBS = ./bonus/read_resource/get_next_line.c \
        ./bonus/read_resource/get_next_line_utils.c \
        ./bonus/actions/actions_of_a.c \
        ./bonus/actions/actions_of_b.c \
        ./bonus/utils/ft_split.c \
        ./bonus/utils/linked_list_fts.c \
        ./bonus/utils/resources.c \
        ./bonus/main.c \
        ./bonus/parcing.c \
        ./bonus/save.c

OBJBS = $(SRCBS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJBS)
	$(CC) $(CFLAGS) $(OBJBS) -o $(NAME_B)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJS} ${OBJBS}

fclean: clean
	${RM} ${NAME} ${NAME_B}

re: fclean all

.PHONY: clean fclean re all bonus
