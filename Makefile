INCLUDES = -I ./includes
MINILIBX_INCLUDES = -I ./minilibx_macos

LIBFT = libft/libft.a

SRCS =	./srcs/assign_to_zero.c \
		./srcs/exit_fn.c \
		./srcs/fdf.c \
		./srcs/find_len.c \
		./srcs/line_drawing.c \
		./srcs/list_append.c \
		./srcs/list_size.c \
		./srcs/make_modified.c \
		./srcs/move_to_int.c \
		./srcs/read_file.c \
		./srcs/save_data_in_stock.c

OBJ = $(SRCS:.c=.o)

EXEC = fdf

RESET = \033[0m
RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;36m
RED_EXTRA = \033[1;31m
GREEN_EXTRA = \033[1;32m
BLUE_EXTRA = \033[1;36m

%.o:%.c
	@echo "$(GREEN) - Creating $(GREEN_EXTRA)$<...$(RESET)"
	@gcc -Wall -Wextra -Werror -c $< -o $@ $(INCLUDES)

all: $(EXEC)

$(EXEC): $(OBJ)
	@echo "$(GREEN)Making objects files for $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@make -C libft
	@echo "$(GREEN)Compiling executable $(GREEN_EXTRA)$(EXEC)$(RESET)"
	@gcc -Wall -Wextra -Werror $(OBJ) $(LIBFT) $(INCLUDES) $(MINILIBX_INCLUDES) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -fsanitize=address -fsanitize=undefined -g -o $(EXEC)
	@echo "$(BLUE_EXTRA)$(EXEC)$(BLUE): Complete$(RESET)"

clean:
	@if [ -a "srcs/fdf.o" ]; then \
	echo "$(RED)Deleting objects for $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -rf $(OBJ); \
	fi
	@make -C libft clean
	@echo "$(BLUE_EXTRA)clean$(BLUE): Complete$(RESET)"

fclean: clean
	@if [ -a "$(EXEC)" ]; then \
	echo "$(RED)Deleting executable $(RED_EXTRA)$(EXEC)$(RESET)"; \
	/bin/rm -f $(EXEC); \
	fi
	@make -C libft fclean
	@echo "$(BLUE_EXTRA)fclean$(BLUE): Complete$(RESET)"

re: fclean all
