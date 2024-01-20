CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= Grace
SRC		= Grace.c
OBJ		= $(SRC:.c=.o)
KID		= Grace_kid.c

GREEN	= \033[0;32m
RED		= \033[0;31m
NC		= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	@echo "$(GREEN)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@rm -f $(NAME)
	@echo "$(RED)Cleaning $(KID)...$(NC)"
	@rm -f $(KID)

re: fclean all

test_quine: $(NAME)
	@echo "Running $(NAME) and comparing output...\n"
	@./$(NAME) && \
	if diff -q $(SRC) $(KID) >/dev/null; then \
		echo "$(GREEN)Valid Quine: $(SRC) and $(KID) are identical.$(NC)"; \
	else \
		echo "$(RED)Not a valid Quine: $(SRC) and $(KID) differ.$(NC)"; \
	fi

.PHONY: all clean fclean re test_quine
