CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -I includes/ -no-pie -g3

RESET       = \033[0m
GREEN       = \033[32m
RED         = \033[31m
YELLOW      = \033[33m
CYAN        = \033[36m
MAGENTA     = \033[35m

SRC_DIR     = src/
OBJ_DIR     = obj/

SRC         = $(wildcard $(SRC_DIR)*.c)
OBJ         = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

LIBDIR      = src/libft
LIBFT       = $(LIBDIR)/libft.a

NAME        = pipex

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBDIR)

$(NAME): $(OBJ) | $(LIBFT)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN) Compiling finished : $(NAME)$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(MAGENTA) Compiling $<$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	#@$(MAKE) -C $(LIBDIR) clean
	make clean -C $(LIBDIR)
	@echo "$(YELLOW) Removing object files.$(RESET)."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean
	@echo "$(RED) Removing the program $(NAME) and object files$(RESET)."

re: fclean all

.PHONY: all clean fclean re