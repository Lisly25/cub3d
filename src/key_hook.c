/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:40:41 by fshields          #+#    #+#             */
/*   Updated: 2024/05/09 09:46:49 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	double	old_dir_X;
	double	old_plane_X;
	double	new_pos_X;
	double	new_pos_Y;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->window);
		return ;
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(data->window, data->wall);
		mlx_delete_image(data->window, data->ceiling);
		mlx_delete_image(data->window, data->floor);
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
		mlx_delete_image(data->window, data->ceiling);
		mlx_delete_image(data->window, data->floor);
		old_dir_X = data->dir_X;
		data->dir_X = data->dir_X * cos(ROT_SPEED) -  data->dir_Y * sin(ROT_SPEED);
		data->dir_Y = old_dir_X * sin(ROT_SPEED) + data->dir_Y * cos(ROT_SPEED);
		old_plane_X = data->plane_X;
		data->plane_X = data->plane_X * cos(ROT_SPEED) - data->plane_Y * sin(ROT_SPEED);
		data->plane_Y = old_plane_X * sin(ROT_SPEED) + data->plane_Y * cos(ROT_SPEED);
		draw_walls(data->map->text, data);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		new_pos_X = data->pos_X + (data->dir_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y + (data->dir_Y * MOVE_SPEED);
		if (data->map->text[(int) new_pos_Y][(int) new_pos_X] != '1')
		{
			mlx_delete_image(data->window, data->wall);
			mlx_delete_image(data->window, data->ceiling);
			mlx_delete_image(data->window, data->floor);
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data->map->text, data);
		}
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		new_pos_X = data->pos_X - (data->dir_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y - (data->dir_Y * MOVE_SPEED);
		if (data->map->text[(int) new_pos_Y][(int) new_pos_X] != '1')
		{
			mlx_delete_image(data->window, data->wall);
			mlx_delete_image(data->window, data->ceiling);
			mlx_delete_image(data->window, data->floor);
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data->map->text, data);
		}
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		new_pos_X = data->pos_X + (data->plane_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y + (data->plane_Y * MOVE_SPEED);
		if (data->map->text[(int) new_pos_Y][(int) new_pos_X] != '1')
		{
			mlx_delete_image(data->window, data->wall);
			mlx_delete_image(data->window, data->ceiling);
			mlx_delete_image(data->window, data->floor);
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data->map->text, data);
		}
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		new_pos_X = data->pos_X - (data->plane_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y - (data->plane_Y * MOVE_SPEED);
		if (data->map->text[(int) new_pos_Y][(int) new_pos_X] != '1')
		{
			mlx_delete_image(data->window, data->wall);
			mlx_delete_image(data->window, data->ceiling);
			mlx_delete_image(data->window, data->floor);
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data->map->text, data);
		}
	}
}
