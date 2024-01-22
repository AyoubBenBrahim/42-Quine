CC = gcc
NASM = nasm
CFLAGS = -Wall -Wextra -Werror

NAME = Colleen
SRC = Colleen.s
OBJ = $(SRC:.s=.o)
TXT = $(NAME).txt

NC = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)[✔] $@ Linking...$(NC)"

%.o: %.s
	@$(NASM) -f macho64 -o $@ $<
	@echo "$(YELLOW)[✔] $@ Assembling...$(NC)"

clean:
	@rm -f $(OBJ) $(NAME)
	@echo "$(RED)[✔] Cleaned...$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[✔] Fcleaned...$(NC)"
	@echo "$(RED)Cleaning $(TXT)...$(NC)"
	@rm -f $(TXT)

re: fclean all

test_quine: $(NAME)
	@echo "Running $(NAME) and comparing output...\n"
	@./$(NAME) > $(TXT) && \
	if diff -q $(SRC) $(TXT) >/dev/null; then \
		echo "$(GREEN)Valid Quine: $(SRC) and $(TXT) are identical.$(NC)"; \
	else \
		echo "$(RED)Not a valid Quine: $(SRC) and $(TXT) differ.$(NC)"; \
	fi

.PHONY: all clean fclean re
