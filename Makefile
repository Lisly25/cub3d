NAME		=	cub3d
GLFW_DIR	=	/Users/$(USER)/.brew/opt/glfw/lib
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	src/main.c \
				src/error.c \
				src/clean_up_textures.c \
				src/init.c \
				src/init_utils.c \
				src/key_hook.c \
				src/key_hook_utils_1.c \
				src/key_hook_utils_2.c \
				src/raycasting/find_walls.c \
				src/raycasting/find_walls_utils.c \
				src/raycasting/wall_height.c \
				src/raycasting/draw_floor_and_ceiling.c \
				src/raycasting/draw_textured_wall.c \
				src/vector_expand.c \
				src/vector_decrease.c \
				src/vector_copy.c \
				src/map_operations/read_map.c \
				src/map_operations/get_assets.c \
				src/map_operations/get_color_config.c \
				src/map_operations/validate_format.c \
				src/map_operations/clean_up_map.c \
				src/map_operations/validate_map_shape.c \
				src/map_operations/path_validation.c 
				
OBJS		=	$(SRCS:.c=.o)
HEADER		=	src/cub3d.h
LIBFT_DIR	=	libft
LIBFT_H		=	$(LIBFT_DIR)/libft.h
LIBFT		=	$(LIBFT_DIR)/libft.a
MLX			=	mlx/build/libmlx42.a
MLX_HEADER	=	mlx/include/MLX42/MLX42.h
FSAN		=	-g -fsanitize=address -static-libsan

all:			makelibft $(NAME)

makelibft:
					@make -C ./$(LIBFT_DIR)

$(MLX):
					@cd mlx && cmake -B build && cmake --build build -j4

$(NAME):		$(OBJS) $(LIBFT) $(HEADER) $(LIBFT_H) $(MLX)
					@$(CC) $(OBJS) $(MLX) $(LIBFT) -ldl -pthread -lm -L$(GLFW_DIR) -lglfw -I $(MLX_HEADER) -o $(NAME)
					@echo "⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂"
					@echo "⚂  compiled !  ⚂"
					@echo "⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂"

%.o:			%.c
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@rm -f $(OBJS)
          
san:			$(OBJS) $(LIBFT) $(HEADER) $(LIBFT_H) $(MLX)
					@$(CC) $(FSAN) $(OBJS) $(MLX) $(LIBFT) -ldl -pthread -lm -L$(GLFW_DIR) -lglfw -I $(MLX_HEADER) -o san

fclean:			clean
					@rm -f $(NAME)
					@rm -rf mlx/build

re:				fclean all

tidymake:	
					@make clean
					@make all
					@make clean

.PHONY:			all makelibft clean fclean re tidymake san