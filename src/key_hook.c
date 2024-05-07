/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:40:41 by fshields          #+#    #+#             */
/*   Updated: 2024/05/07 10:49:22 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	double	old_dir_X;
	double	old_plane_X;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->window);
		return ;
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(data->window, data->wall);
		old_dir_X = data->dir_X;
		data->dir_X = data->dir_X * cos(-ROT_SPEED) -  data->dir_Y * sin(-ROT_SPEED);
		data->dir_Y = old_dir_X * sin(-ROT_SPEED) + data->dir_Y * cos(-ROT_SPEED);
		old_plane_X = data->plane_X;
		data->plane_X = data->plane_X * cos(-ROT_SPEED) - data->plane_Y * sin(-ROT_SPEED);
		data->plane_Y = old_plane_X * sin(-ROT_SPEED) + data->plane_Y * cos(-ROT_SPEED);
		draw_walls(data->map->text, data);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(data->window, data->wall);
		old_dir_X = data->dir_X;
		data->dir_X = data->dir_X * cos(ROT_SPEED) -  data->dir_Y * sin(ROT_SPEED);
		data->dir_Y = old_dir_X * sin(ROT_SPEED) + data->dir_Y * cos(ROT_SPEED);
		old_plane_X = data->plane_X;
		data->plane_X = data->plane_X * cos(ROT_SPEED) - data->plane_Y * sin(ROT_SPEED);
		data->plane_Y = old_plane_X * sin(ROT_SPEED) + data->plane_Y * cos(ROT_SPEED);
		draw_walls(data->map->text, data);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && \
		(data->map->text[(int) data->pos_Y - 1][(int) data->pos_X] != '1'))
	{
		mlx_delete_image(data->window, data->wall);
		data->pos_Y --;
		draw_walls(data->map->text, data);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && \
		(data->map->text[(int) data->pos_Y + 1][(int) data->pos_X] != '1'))
	{
		mlx_delete_image(data->window, data->wall);
		data->pos_Y ++;
		draw_walls(data->map->text, data);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && \
		(data->map->text[(int) data->pos_Y][(int) data->pos_X + 1] != '1'))
	{
		mlx_delete_image(data->window, data->wall);
		data->pos_X ++;
		draw_walls(data->map->text, data);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && \
		(data->map->text[(int) data->pos_Y][(int) data->pos_X - 1] != '1'))
	{
		mlx_delete_image(data->window, data->wall);
		data->pos_X --;
		draw_walls(data->map->text, data);
	}
}
