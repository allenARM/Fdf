INCLUDES = -I ./includes
INCLUDES2 = -I ./minilibx_macos

LIBFT = libft/libft.a
LIB_FDF = lib_fdf.a

SRCS = ./srcs/*

OBJ = ./obj

EXEC = fdf

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

all: $(EXEC)

# -fsanitize=address -fsanitize=undefined
$(EXEC):
	@echo "$(GREEN)Making objects files for $(GREEN_EXTRA)$(LIB_FDF)$(RESET)"
	@gcc -Wall -Wextra -Werror $(SRCS) $(INCLUDES) -c -g
	@echo "$(GREEN)Compiling $(GREEN_EXTRA)$(LIB_FDF)$(RESET)"
	@ar rc $(LIB_FDF) *.o
	@ranlib $(LIB_FDF)
	@if [ ! -d "./obj" ]; then mkdir -p $(OBJ); fi
	@echo "$(GREEN)Moving objects files for $(GREEN_EXTRA)$(LIB_FDF)$(GREEN) to $(OBJ)$(RESET)"
	@mv *.o $(OBJ)
	@make -C libft
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@gcc -Wall -Wextra -Werror $(LIB_FDF) $(LIBFT) $(INCLUDES) $(INCLUDES2) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -g -o $(EXEC)
	@echo "$(BLUE_EXTRA)$(EXEC)$(BLUE): Complete$(RESET)"

clean:
	@if [ -d "./obj" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(LIB_FDF)$(RESET)"; \
	/bin/rm -rf $(OBJ); \
	fi
	@make -C libft clean
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(LIB_FDF)" ]; then \
	echo "$(RED)Deleting $(RED_EXTRA)$(LIB_FDF)$(RESET)"; \
	/bin/rm -f $(LIB_FDF); \
	fi

	@if [ -a "$(EXEC)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -f $(EXEC); \
	fi

	@make -C libft fclean
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

re: fclean all
