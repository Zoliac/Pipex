NAME = libftprintf.a

srcs = mainft.c formats.c utils.c advutils.c

OBJS = $(srcs:.c=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

CC=cc -Wall -Werror -Wextra

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
