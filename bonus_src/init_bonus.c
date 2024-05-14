/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:58:44 by fshields          #+#    #+#             */
/*   Updated: 2024/05/13 15:11:39 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

uint32_t	get_colour(int rgb[3])
{
	uint32_t	colour;
	uint32_t	a;

	a = 255;
	colour = (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | a);
	return (colour);
}

static void	set_exit_position(t_data *data, t_vector *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < map->used_nodes)
	{
		while (map->text[y][x] != '\0')
		{
			if (map->text[y][x] == 'P')
			{
				data->exit_x = (double) x;
				data->exit_y = (double) y;
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
	assets->north = init_texture(assets->north_file, "north");
	if (assets->north == NULL)
	{
		printf("Here?\n");
		return (false);
	}
	assets->south = init_texture(assets->south_file, "south");
	if (assets->south == NULL)
		return (false);
	assets->west = init_texture(assets->west_file, "west");
	if (assets->west == NULL)
		return (false);
	assets->east = init_texture(assets->east_file, "east");
	if (assets->east == NULL)
		return (false);
	assets->door = init_texture(assets->door_file, "door");
	if (assets->door == NULL)
		return (false);
	assets->portal = init_texture(assets->portal_file, "exit");
	if (assets->portal == NULL)
		return (false);
	return (true);
}

t_data	*init_data(t_vector *map, t_assets *assets)
{
	t_data	*data;
	t_ray	*ray_data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		ft_exit("Malloc failure", data, assets, map);
	data->window = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", false);
	if (!(data->window))
		ft_exit("Failed to init window", data, assets, map);
	data->map = map;
	data->plane_x = PLANE_X;
	data->plane_y = PLANE_Y;
	set_start_position(data, map);
	set_exit_position(data, map);
	data->assets = assets;
	if (init_wall_textures(data) == false)
		ft_exit(NULL, data, assets, map);
	if (init_image(data) == false)
		ft_exit("Failed to create image", data, assets, map);
	ray_data = (t_ray *)malloc(sizeof(t_ray));
	if (ray_data == NULL)
		ft_exit("Malloc failure", data, assets, map);
	data->ray = ray_data;
	return (data);
}
