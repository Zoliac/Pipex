NAME=libft.a

FT= is/ft_isalnum is/ft_isalpha is/ft_isascii is/ft_isdigit is/ft_isprint is/ft_isspace \
      mem/ft_bzero mem/ft_calloc mem/ft_memchr mem/ft_memcmp mem/ft_memcpy mem/ft_memmove mem/ft_memset \
      fd/ft_putchar_fd fd/ft_putendl_fd fd/ft_putnbr_fd fd/ft_putstr_fd \
      str/ft_itoa str/ft_split str/ft_strchr str/ft_strdup str/ft_striteri str/ft_strjoin str/ft_strlcat \
      str/ft_strlcpy str/ft_strlen str/ft_strmapi str/ft_strncmp str/ft_strnstr str/ft_strrchr str/ft_strtrim \
      str/ft_substr \
      ft_tolower \
      ft_toupper \
      gnl/get_next_line \
      printf/advutils printf/mainft printf/utils printf/formats \

SOURCES = $(addprefix src/, $(addsuffix , $(FT)))
OBJS = $(addprefix obj/, $(addsuffix .o, $(FT)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude
AR = ar

all: $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) -rcs $@ $^

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
