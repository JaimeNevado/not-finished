SRCS	= get_next_line.c get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJSB)

re: fclean all

bonus: $(OBJSB) $(OBJS)
	ar -rc $(NAME) $(OBJSB) $(OBJS)

.PHONY: clean fclean re all bonus
