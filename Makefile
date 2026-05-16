NAME = push_swap

SRCS = main.c ft_strlcpy.c ft_strlen.c \
       op_push.c op_rotate.c op_reverse.c op_swap.c print.c \
       disorder.c stack_utils.c ft_lstnew.c ft_lstlast.c \
	   ft_lstadd_back.c ft_atol.c simple_1.c utils.c init.c\
	   medium.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
