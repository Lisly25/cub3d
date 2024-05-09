/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:33:03 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/09 12:22:13 by fshields         ###   ########.fr       */
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
	data->assets->north = mlx_load_png(data->assets->north_file);
	if (data->assets->north == NULL)
		return (false);
	return (true);
}

bool	init_wall_images(t_data *data)
{
	data->wall = mlx_texture_to_image(data->window, data->assets->north);//we can't just call this "wall" later on
	if (data->wall == NULL)
		return (false);
	return (true);
}
