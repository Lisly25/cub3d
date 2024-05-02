NAME		=	cub3d
GLFW_DIR	=	/Users/$(USER)/.brew/opt/glfw/lib
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	src/main.c \
				src/error.c \
				src/vector_expand.c \
				src/vector_decrease.c \
				src/map_operations/read_map.c \
				src/map_operations/get_assets.c \
				src/map_operations/get_color_config.c \
				src/map_operations/validate_format.c
				
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

san:			$(OBJS) $(LIBFT) $(HEADER) $(LIBFT_H) $(MLX)
					@$(CC) $(FSAN) $(OBJS) $(MLX) $(LIBFT) -ldl -pthread -lm -L$(GLFW_DIR) -lglfw -I $(MLX_HEADER) -o san

clean:
					@rm -f $(OBJS)
					make fclean -C ./libft

fclean:			clean
					@rm -f $(NAME)
					@rm -rf mlx/build


re:				fclean all

tidymake:	
					@make fclean
					@make all
					@make clean

.PHONY:			all makelibft clean fclean re tidymake