/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:00:40 by fshields          #+#    #+#             */
/*   Updated: 2024/05/13 12:22:59 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	display_minimap(t_data *data)
{
	mlx_image_t	*wall;
	mlx_image_t	*open;
	mlx_image_t	*player;
	t_vector	*map;
	size_t		x;
	size_t		y;

	map = data->map;
	wall = mlx_new_image(data->window, MM_SQUARE, MM_SQUARE);
	if (!wall)
		msg_and_exit("image creation error");
	ft_memset(wall->pixels, 175, wall->width * wall->height * sizeof(int32_t));
	open = mlx_new_image(data->window, MM_SQUARE, MM_SQUARE);
	if (!open)
		msg_and_exit("image creation error");
	ft_memset(open->pixels, 200, open->width * open->height * sizeof(int32_t));
	player = mlx_new_image(data->window, MM_SQUARE, MM_SQUARE);
	if (!player)
		msg_and_exit("image creation error");
	ft_memset(player->pixels, 255, player->width * player->height * sizeof(int32_t));
	x = 0;
	y = 0;
	while (y < map->used_nodes)
	{
		while (map->text[y][x] != '\0')
		{
			if (map->text[y][x] == '1')
				mlx_image_to_window(data->window, wall, (MM_OFFSET + x * MM_SQUARE), (MM_OFFSET + y * MM_SQUARE));
			else if (map->text[y][x] != ' ' && map->text[y][x] != '\n')
				mlx_image_to_window(data->window, open, (MM_OFFSET + x * MM_SQUARE), (MM_OFFSET + y * MM_SQUARE));
			x ++;
		}
		y ++;
		x = 0;
	}
	mlx_image_to_window(data->window, player, ((int) data->pos_x * MM_SQUARE) + MM_OFFSET, ((int) data->pos_y * MM_SQUARE) + MM_OFFSET);
	data->mm_wall = wall;
	data->mm_open = open;
	data->mm_player = player;
}

void	clear_minimap(t_data *data)
{
	mlx_delete_image(data->window, data->mm_open);
	mlx_delete_image(data->window, data->mm_player);
	mlx_delete_image(data->window, data->mm_wall);
}
