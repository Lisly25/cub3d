/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:55:49 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/06 12:52:47 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/include/MLX42/MLX42.h"
# include "vector.h"
# include "fcntl.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>

# define MALLOC_ERROR 1 
# define SCREEN_WIDTH 1300
# define SCREEN_HEIGHT 900
# define PLANE_X 0
# define PLANE_Y 0.66

//throw this away later
# define POSITION_X 1
# define POSITION_Y 1
# define DIRECTION_X 0.5
# define DIRECTION_Y 0.5

//error.c
void		msg_and_exit(char *msg);

//read_map.c
t_vector	*read_map(int argc, char **argv);

//init.c
mlx_t		*init_window();

//find_walls
double		get_ray_length(double ray_direction_x, double ray_direction_y, int *step_x, int *step_y, double position_x, double position_y, int map_x, int map_y, char **map);
double		adjust_ray_direction(int mode, int x);

//wall_height.c
void		draw_walls(char **map, mlx_t *window);

#endif