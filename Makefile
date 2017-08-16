.PHONY: all, $(NAME), test, clean, fclean, re

NAME= fdf

CC= cc

GRAPHICS_FLAGS+= -framework OpenGL -framework AppKit

SRC_PATH= src/
INC_PATH= includes/
OBJ_PATH= obj/
LIBFT_PATH= includes/libft/
MLX_PATH= includes/minilibx/

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_MLX = $(addprefix -I, $(MLX_PATH))
INC_LFT = $(addprefix -I, $(addprefix $(LIBFT_PATH), $(INC_PATH)))

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME = main.c wf_2d_plot.c wf_draw_line.c wf_key_functions.c\
		   wf_getplots1.c wf_getplots2.c  wf_start_and_end.c\
		   wf_rgb.c wf_bresenham_init.c wf_image_handler.c\
		   wf_legend.c wf_expose_handler.c

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\n"
	@printf "\033[1m\x1b[36mMaking 42 library...\x1b[0m\n"
	@make -C $(LIBFT_PATH)
	@printf "\033[1m\x1b[36mMaking MLX library...\x1b[0m\n"
	@make -C $(MLX_PATH)
	@printf "\033[1m\x1b[36mBuilding FDF executable...\x1b[0m\n"
	@$(CC) -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx $(GRAPHICS_FLAGS)
	@printf "\033[1m\x1b[32mReady!\x1b[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(INC) $(INC_MLX) $(INC_LFT) -o $@ -c $< 
	@printf "\033[1m\x1b[33m********\x1b[0m"

test: $(OBJ)
	@printf "\033[1m\x1b[33mRefreshing executable...\n"
	@$(CC) -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx $(GRAPHICS_FLAGS)
	@printf "\033[1m\x1b[32mReady!\x1b[0m\n"

clean:
	@printf "\033[1m\x1b[31mRemoving object files...\x1b[0m\n"
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)
	@printf "\033[1m\x1b[36mObject files removed.\x1b[0m\n"

fclean: clean
	@printf "\033[1m\x1b[31mReverting to zero state...\x1b[0m\n"
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@printf "\033[1m\x1b[36mClean.\x1b[0m\n"
	
re: fclean all
