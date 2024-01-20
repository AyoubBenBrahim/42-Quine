CC		= clang
CFLAGS	= -Wall -Wextra -Werror

NAME	= Sully
SRC		= $(NAME).c
OBJ		= $(SRC:.c=.o)
SUB_DIR = _$(NAME)

GREEN	= \033[0;32m
RED		= \033[0;31m
NC		= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)creating subdir /$(SUB_DIR)...$(NC)"
	@mkdir $(SUB_DIR)
	@cp $(NAME) $(SUB_DIR)

%.o: %.c
	@echo "$(GREEN)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@rm -f $(NAME)
	@echo "$(RED)Removing $(SUB_DIR) ...$(NC)"
	@rm -rf $(SUB_DIR)

re: fclean all

run_quine: $(NAME)
	@echo "$(GREEN)Runing the binnary ./$(NAME) into the sub_dir.."
	@cd $(SUB_DIR) && ./$(NAME)
	@echo "Finished running the binary...\n"
	@echo "Now Run ur Tests....$(NC)"

list_dir: $(NAME)
	@echo "Runing the cmd$(GREEN) 'ls -al | grep Sully | wc -l'$(NC)"
	@cd $(SUB_DIR) && ls -al | grep Sully | wc -l

test_quine: $(NAME)
	@echo "$(GREEN)Testing the Quine...$(NC)\n"
	@echo "diff Sully.c Sully_0.c"
	@diff $(NAME).c $(SUB_DIR)/Sully_0.c; \
	echo "\n--------------------------\n"; \
	cd $(SUB_DIR) && i=5; \
	while [ $$i -ge 1 ]; do \
		if [ $$i -lt 5 ]; then \
			echo "\n--------------------------\n"; \
		fi; \
		echo "diff $(NAME)_$$i.c $(NAME)_$$(($$i - 1)).c"; \
		diff $(NAME)_$$i.c $(NAME)_$$(($$i - 1)).c 2>/dev/null; \
		i=$$(($$i - 1)); \
	done

.PHONY: all clean fclean re test_quine
