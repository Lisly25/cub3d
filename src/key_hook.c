/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:40:41 by fshields          #+#    #+#             */
/*   Updated: 2024/05/09 09:53:43 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	delete_old_images(t_data *data)
{
	mlx_delete_image(data->window, data->wall);
	mlx_delete_image(data->window, data->ceiling);
	mlx_delete_image(data->window, data->floor);
}

/*void	display_data(t_data *data)
{
	printf("------\ndir_X: %f\ndir_Y: %f\nplane_X: %f\nplane_Y: %f\npos_X: %f\npos_Y: %f\n", data->dir_X, data->dir_Y, data->plane_X, data->plane_Y, data->pos_X, data->pos_Y);
}*/

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
	if (mlx_is_key_down(data->window, MLX_KEY_LEFT))
	{
		delete_old_images(data);
		old_dir_X = data->dir_X;
		data->dir_X = data->dir_X * cos(-ROT_SPEED) -  data->dir_Y * sin(-ROT_SPEED);
		data->dir_Y = old_dir_X * sin(-ROT_SPEED) + data->dir_Y * cos(-ROT_SPEED);
		old_plane_X = data->plane_X;
		data->plane_X = data->plane_X * cos(-ROT_SPEED) - data->plane_Y * sin(-ROT_SPEED);
		data->plane_Y = old_plane_X * sin(-ROT_SPEED) + data->plane_Y * cos(-ROT_SPEED);
		draw_walls(data->map->text, data);
	}
	if (mlx_is_key_down(data->window, MLX_KEY_RIGHT))
	{
		delete_old_images(data);
		old_dir_X = data->dir_X;
		data->dir_X = data->dir_X * cos(ROT_SPEED) -  data->dir_Y * sin(ROT_SPEED);
		data->dir_Y = old_dir_X * sin(ROT_SPEED) + data->dir_Y * cos(ROT_SPEED);
		old_plane_X = data->plane_X;
		data->plane_X = data->plane_X * cos(ROT_SPEED) - data->plane_Y * sin(ROT_SPEED);
		data->plane_Y = old_plane_X * sin(ROT_SPEED) + data->plane_Y * cos(ROT_SPEED);
		draw_walls(data->map->text, data);
	}
	if (mlx_is_key_down(data->window, MLX_KEY_W))
	{
		new_pos_X = data->pos_X + (data->dir_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y + (data->dir_Y * MOVE_SPEED);
		if (data->map->text[(int) new_pos_Y][(int) new_pos_X] != '1')
		{
			delete_old_images(data);
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data->map->text, data);
		}
	}
	if (mlx_is_key_down(data->window, MLX_KEY_S))
	{
		new_pos_X = data->pos_X - (data->dir_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y - (data->dir_Y * MOVE_SPEED);
		if (data->map->text[(int) new_pos_Y][(int) new_pos_X] != '1')
		{
			delete_old_images(data);
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data->map->text, data);
		}
	}
	if (mlx_is_key_down(data->window, MLX_KEY_D))
	{
		new_pos_X = data->pos_X + (data->plane_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y + (data->plane_Y * MOVE_SPEED);
		if (data->map->text[(int) new_pos_Y][(int) new_pos_X] != '1')
		{
			delete_old_images(data);
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data->map->text, data);
		}
	}
	if (mlx_is_key_down(data->window, MLX_KEY_A))
	{
		new_pos_X = data->pos_X - (data->plane_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y - (data->plane_Y * MOVE_SPEED);
		if (data->map->text[(int) new_pos_Y][(int) new_pos_X] != '1')
		{
			delete_old_images(data);
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data->map->text, data);
		}
	}
}
