CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = Colleen
SRC = Colleen.c
OBJ = $(SRC:.c=.o)
TXT = $(NAME).txt

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

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
	@echo "$(RED)Cleaning $(TXT)...$(NC)"
	@rm -f $(TXT)

re: fclean all

test_quine: $(NAME)
	@echo "Running $(NAME) and comparing output...\n"
	@./$(NAME) > $(TXT) && \
	if diff -q $(SRC) $(TXT) >/dev/null; then \
		echo "$(GREEN)Valid Quine: $(NAME).c and $(TXT) are identical.$(NC)"; \
	else \
		echo "$(RED)Not a valid Quine: $(NAME).c and $(TXT) differ.$(NC)"; \
	fi

.PHONY: all clean fclean re test_quine
