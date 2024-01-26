CC = gcc
NASM = nasm
CFLAGS = -Wall -Wextra -Werror

NAME = Grace
SRC = Grace.s
OBJ = $(SRC:.s=.o)
TXT = $(NAME).txt
KID = Grace_kid.s 

NC	= \033[0m
RED = \033[31m
GREEN	= \033[32m
YELLOW	= \033[33m

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
	@echo "$(RED)Cleaning $(KID)...$(NC)"
	@rm -f $(KID)

test_quine: $(NAME)
	@echo "comparing output..."
	@if diff -q $(SRC) $(KID)  >/dev/null; then \
		echo "\033[32mValid Quine: $(SRC) and $(KID)  are identical.\033[0m"; \
	else \
		echo "\033[31mNot a valid Quine: $(SRC) and $(KID)  differ.\033[0m"; \
	fi



re: fclean all

.PHONY: all clean fclean re
