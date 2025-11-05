# === Colors ===
RED     	= \033[0;31m
GREEN   	= \033[0;32m
YELLOW  	= \033[0;33m
BLUE    	= \033[0;34m
MAGENTA 	= \033[0;35m
CYAN    	= \033[0;36m
RESET   	= \033[0m
BOLD		= \033[1m
UNDERLINE 	= \033[4;32m
GREEN_BG 	= \033[42m

NAME = cub3D

# Paths
LIB_DIR = libs
LIBFT_DIR = $(LIB_DIR)/libft
MINILIBX_DIR = $(LIB_DIR)/minilibx-linux
SRC_DIR = src
OBJ_DIR = obj
HEADERS_DIR = include
LIBFT_HEADERS_DIR = $(LIBFT_DIR)/include

# Links
MINILIBX_URL = https://cdn.intra.42.fr/document/document/36820/minilibx-linux.tgz

# Compiler
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -I$(HEADERS_DIR) -I$(SRC_DIR) -I$(LIBFT_DIR) -I$(LIBFT_HEADERS_DIR) -I$(MINILIBX_DIR)

# Linker/Loader flags
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm

# Sources
SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/filename_parsing.c \
		$(SRC_DIR)/path_parsing.c \
		$(SRC_DIR)/program_utils.c \
		$(SRC_DIR)/map.c \
 		$(SRC_DIR)/map_utils.c \
		$(SRC_DIR)/map_parsing.c \
		$(SRC_DIR)/cleaning.c \
		$(SRC_DIR)/window.c \
		$(SRC_DIR)/hooks.c \
		$(SRC_DIR)/player_parsing.c \
		$(SRC_DIR)/player_utils.c
# 		$(SRC_DIR)/textures.c \
# 		$(SRC_DIR)/program_utils.c \

LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_CLEAN_ENABLED ?= 1

# Commands (da includere minilibx)
all: $(NAME)
	@echo "$(GREEN)---- Building of $(NAME) ----$(RESET)";

# to do includere minilibx
$(NAME):  $(MINILIBX) $(OBJS) $(LIBFT)
	@echo "$(CYAN)---- Linking target $@ ---- $(RESET)using $^"
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

$(LIBFT):
	@echo "$(YELLOW)---- Compiling $< $(RESET) ----> $@"
	$(MAKE) -C $(LIBFT_DIR) --quiet

$(MINILIBX): | $(MINILIBX_DIR)
	@echo "$(YELLOW)---- Compiling $< $(RESET) ----> $@"
	@$(MAKE) -C $(MINILIBX_DIR) --quiet

$(MINILIBX_DIR):
	@echo "$(YELLOW)---- minilibx-linux directory not found, downloading and extracting$(RESET)"
	@curl -L $(MINILIBX_URL) | tar xz -C $(LIB_DIR)
	@echo "---- removing minilibx-linux.tgz"
	@rm -f $(LIB_DIR)/minilibx-linux.tgz

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)---- Compiling $< $(RESET) ----> $@"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@echo "$(MAGENTA)---- Create folder $@ $(RESET)"
	mkdir -p $(OBJ_DIR)

# Remove only temporary files
clean:
	@echo "$(RED)---- Removing .o files in $(NAME)----$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)---- cleaning minilibx ----$(RESET)"
	@$(MAKE) clean -C $(MINILIBX_DIR)
ifeq ($(LIBFT_CLEAN_ENABLED),1)
	@echo "$(RED)---- cleaning libft =---$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR) --silent
endif

# Remove temporary files and executables
fclean: clean 
	@if [ -n "$(NAME)" ] && [ -e "$(NAME)" ]; then \
		echo "$(RED)---- Removing executable $(NAME)...$(RESET)"; \
		rm -f $(NAME); \
	fi
	@echo "$(RED)---- fcleaning libft ----$(RESET)"
	@$(MAKE) --no-print-directory LIBFT_CLEAN_ENABLED=0 clean
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent
	@echo "$(RED)---- cleaning minilibx ----$(RESET)"
	@rm -rf $(MINILIBX_DIR)

re: fclean all
 
.PHONY: all clean fclean re