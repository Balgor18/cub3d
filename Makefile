NAME = cub3D

OBJ_DIR		=	objs
INC_DIR		=	includes
SRC_DIR		=	$(shell find srcs -type d)
LIB_DIR		=	-Lminilibx-linux -l
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

# --  Redirection in OBJS  -- #
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

SRCS =	get_next_line.c             	\
		get_next_line_utils.c       	\
		get_next_line_utils2.c      	\
		start_mlx.c                 	\
		main.c                      	\


# --   Compilation flags  -- #
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror

# --    Add DEBUG flags   -- #
DEBUG = $(shell env | grep DEBUG= | tr '=' ' ' | awk '{print $$2}')

ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

.PHONY: all
ifeq ($(DEBUG), 1)
all : $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./cub3D
	norminette srcs | grep Error
else
all : $(NAME)
endif

# **************************************************************************** #

$(NAME): $(OBJS) $(INC_DIR)/cub3D.h
	$(CC) $(CFLAGS) $(OBJS) -I $(INC_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(INC_DIR)/cub3D.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR) :
	mkdir -p $@

# **************************************************************************** #

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
