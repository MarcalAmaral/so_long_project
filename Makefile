# tool macros
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

# path macros
OBJ_PATH = obj
SRC_PATH = src
PATH_MLX = ./lib/MLX42
PATH_MLXLIB = $(PATH_MLX)/build/libmlx42.a -ldl -lm -lpthread -lglfw
PATH_LIBFT = ./lib/libft
PATH_LIBFTLIB = $(PATH_LIBFT)/libft.a

# compile macros
NAME = so_long

FILES = draw_map \
		flood_fill \
		ft_readmap \
		ft_readmap_utils \
		game_init \
		handle_collectables \
		handle_free \
		handle_image \
		handle_input \
		handle_movements \
		main \
		validate_args \
		validate_map \
		validate_map_utils

OBJ = $(addprefix $(OBJ_PATH)/, $(addsuffix .o, $(FILES)))

INCLUDE = -I ./inc -I $(PATH_MLX)/include

$(NAME): $(PATH_LIBFTLIB) $(OBJ) 
	$(CC) -o $@ $(OBJ) $(CFLAGS) $(PATH_MLXLIB) $(PATH_LIBFTLIB)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c* | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(PATH_LIBFTLIB):
	$(MAKE)	-C $(PATH_LIBFT)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

all: $(NAME)

clean:
	@$(MAKE) -C $(PATH_LIBFT) clean
	@rm -fr $(OBJ_PATH)

fclean: clean
	@$(MAKE) -C $(PATH_LIBFT) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re