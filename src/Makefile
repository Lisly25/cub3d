NAME		=	minishell
GLFW_DIR	=	/Users/fshields/.brew/opt/glfw/lib
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	main.c \
				error.c \
				vector.c \
				init.c \
				map_operations/read_map.c \
				raycasting/find_walls.c \
				raycasting/wall_height.c
				
OBJS		=	$(SRCS:.c=.o)
HEADER		=	cub3d.h
LIBFT_DIR	=	libft
LIBFT_H		=	$(LIBFT_DIR)/libft.h
LIBFT		=	$(LIBFT_DIR)/libft.a
MLX			=	mlx/build/libmlx42.a
MLX_HEADER	=	mlx/include/MLX42/MLX42.h
# FSAN		=	-g -fsanitize=address -static-libsan

all:			makelibft $(NAME)

makelibft:
					@make -C ./$(LIBFT_DIR)

$(MLX):
				@cd mlx && cmake -B build && cmake --build build -j4

$(NAME):		$(OBJS) $(LIBFT) $(HEADER) $(LIBFT_H)
					@$(CC) $(OBJS) $(MLX) $(LIBFT) -ldl -pthread -lm -L$(GLFW_DIR) -lglfw -I $(MLX_HEADER) -o $(NAME)
					@echo "⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂"
					@echo "⚂  compiled !  ⚂"
					@echo "⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂⚂"

%.o:			%.c
					@$(CC) $(CFLAGS) -c $< -o $@

# san:		
# 					@$(CC) $(CFLAGS) $(FSAN) $(SRCS) $(LIBFT)  -o san

clean:
					@rm -f $(OBJS)
					@rm -rf mlx/build
					make fclean -C ./libft

fclean:			clean
					@rm -f $(NAME)


re:				fclean all

tidymake:	
					@make fclean
					@make all
					@make clean

.PHONY:			all makelibft clean fclean re tidymake san