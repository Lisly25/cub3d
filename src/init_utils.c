/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:33:03 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/10 14:55:19 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_start_orientation(t_data *data, char c)
{
	if (c == 'S')
	{
		data->dir_X = 0;
		data->dir_Y = 1;
		data->plane_X = -PLANE_Y;
		data->plane_Y = 0;
	}
	else if (c == 'N')
	{
		data->dir_X = 0;
		data->dir_Y = -1;
		data->plane_X = PLANE_Y;
		data->plane_Y = 0;
	}
	else if (c == 'E')
	{
		data->dir_X = 1.0;
		data->dir_Y = 0.0;
	}
	else if (c == 'W')
	{
		data->dir_X = -1.0;
		data->dir_Y = 0.0;
		data->plane_Y *= -1;
	}
}

void	set_start_position(t_data *data, t_vector *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < map->used_nodes)
	{
		while (map->text[y][x] != '\0')
		{
			if (ft_strchr("NSEW", map->text[y][x]) != NULL)
			{
				data->pos_X = (double) x;
				data->pos_Y = (double) y;
				set_start_orientation(data, map->text[y][x]);
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
	return ;
}

bool	init_wall_textures(t_data *data)
{
	t_assets	*assets;

	assets = data->assets;
	assets->north = mlx_load_png(assets->north_file);
	assets->south = mlx_load_png(assets->south_file);
	assets->east = mlx_load_png(assets->east_file);
	assets->west = mlx_load_png(assets->west_file);
	if (assets->north == NULL)
		return (false);
	return (true);
}

bool	init_image(t_data *data)
{
	data->img = mlx_new_image(data->window, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (data->img == NULL)
		return (false);
	if (mlx_image_to_window(data->window, data->img, 0, 0) == -1)
		return (false);
	return (true);
}
