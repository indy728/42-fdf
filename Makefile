.PHONY: all, $(NAME), clean, fclean, re

NAME= mlx

CC= gcc
CC_FLAGS+= -Wall -Werror -Wextra

SRC_PATH= src/
INC_PATH= includes/
OBJ_PATH= obj/
LIBFT_PATH= includes/libft/
MLX_PATH= includes/minilibx/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME = main.c

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH) $(MLX_PATH)
	$(CC) -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	make -C $(LIBFT_PATH) $(MLX_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) $(MLX_PATH) fclean
	rm -f $(NAME)
	
re: fclean all
