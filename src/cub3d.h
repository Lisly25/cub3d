/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:55:49 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/06 14:26:10 by fshields         ###   ########.fr       */
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
# define ROT_SPEED 0.2

//throw this away later
# define POSITION_X 9
# define POSITION_Y 9
# define DIRECTION_X -1
# define DIRECTION_Y 0

typedef struct s_data
{
	mlx_t			*window;
	mlx_image_t		*wall;
	t_vector		*map;
	double			dir_X;
	double			dir_Y;
	double			plane_X;
	double			plane_Y;
	double			pos_X;
	double			pos_Y;
}	t_data;

typedef struct s_assets
{
	char	*west_file;
	char	*east_file;
	char	*north_file;
	char	*south_file;
	int		floor[3];
	int		ceiling[3];
	char	start_orientation;
}	t_assets;

//error.c
void		msg_and_exit(char *msg);
void		map_validation_error(char *msg, t_vector *map, t_assets *assets);
void		free_assets_struct(t_assets *assets);
bool		error_msg(char *msg);

//key_hook
void		key_hook(mlx_key_data_t keydata, void *param);

//map_operations/read_map.c
t_vector	*read_map(int argc, char **argv);

//map_operations/get_assets.c
char		*trim_identifier(char *config_line, unsigned int id_length);
t_assets	*get_assets(t_vector *map);

//map_operations/validate_format.c
void		validate_texture_info_format(t_vector *map);

//map_operations/get_color_config.c
int			copy_rgb_values(char *color_info, t_assets *assets, char *id);

//map_operations/clean_up_map.c
bool		clean_up_and_validate_map(t_vector *map);

//map_operations/validate_map_shape.c
bool		validate_map_shape(t_vector *map);

//init.c
mlx_t		*init_window();
t_data		*init_data(mlx_t *window, t_vector *map);

//find_walls
double		get_ray_length(double ray_direction_x, double ray_direction_y, int *step_x, int *step_y, double position_x, double position_y, char **map);
double		adjust_ray_direction(int mode, int x, t_data *data);

//wall_height.c
void		draw_walls(char **map, t_data *data);

#endif