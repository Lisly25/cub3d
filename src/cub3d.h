/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:55:49 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/09 12:21:08 by fshields         ###   ########.fr       */
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
# define MOVE_SPEED 0.35
# define RENDER_SCALE 10
// # define PI 3.14159265359

typedef struct s_assets
{
	char			*west_file;
	char			*east_file;
	char			*north_file;
	char			*south_file;
	mlx_texture_t	*north;
	int				floor[3];
	int				ceiling[3];
	char			start_orientation;
}	t_assets;

typedef struct s_data
{
	mlx_t			*window;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*ceiling;
	t_vector		*map;
	double			dir_X;
	double			dir_Y;
	double			plane_X;
	double			plane_Y;
	double			pos_X;
	double			pos_Y;
	t_assets		*assets;
}	t_data;

//error.c
void		msg_and_exit(char *msg);
void		map_validation_error(char *msg, t_vector *map, t_assets *assets);
void		free_assets_struct(t_assets *assets);
bool		error_msg(char *msg);
void		free_all_n_exit(char *msg, t_data *data, t_assets *assts, t_vector *map);

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
bool		check_neighbours_for_char(t_vector *map, char c, size_t x, size_t y);

//map_operations/path_validation.c
int			check_if_all_map_is_accessible(t_vector *map);

//init.c
mlx_t		*init_window();
t_data		*init_data(mlx_t *window, t_vector *map, t_assets *assets);
bool		init_floor_and_ceiling_img(t_data *data);

//init_utils.c
void		set_start_position(t_data *data, t_vector *map);
bool		init_wall_textures(t_data *data);
bool		init_wall_images(t_data *data);

//find_walls
double		get_ray_length(double ray_direction_x, double ray_direction_y, int *step_x, int *step_y, double position_x, double position_y, char **map);
double		adjust_ray_direction(int mode, int x, t_data *data);

//find_walls_utils
bool	check_if_valid_pos(char **map, int x, int y);

//wall_height.c
void		draw_walls(char **map, t_data *data);

//raycasting/draw_floor_and_ceiling.c
void		draw_ceiling(int x, int wall_start, t_data *data);
void		draw_floor(int x, int wall_end, t_data *data);

#endif