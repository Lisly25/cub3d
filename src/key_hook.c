/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:40:41 by fshields          #+#    #+#             */
/*   Updated: 2024/05/10 14:00:19 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_diags(t_data *data, double new_x, double new_y)
{
	int			diag_x;
	int			diag_y;
	t_vector	*map;
	
	if ((int) data->pos_X == (int) new_x || (int) data->pos_Y == (int) new_y)
		return (true);
	map = data->map;
	diag_x = (int) data->pos_X + (data->dir_X > 0) - (data->dir_X < 0);
	diag_y = (int) data->pos_Y + (data->dir_Y > 0) - (data->dir_Y < 0);
	if (map->text[diag_y][(int) data->pos_X] == '1')
		return (false);
	if (map->text[(int) data->pos_Y][diag_x] == '1')
		return (false);
	return (true);
}

static bool	wall_collision(t_data *data, double new_pos_X, double new_pos_Y)
{
	t_vector	*map;
	double		adjusted_x;
	double		adjusted_y;

	map = data->map;
	if (data->dir_X > 0)
		adjusted_x = new_pos_X + PLAYER_SIZE;
	else if (data->dir_X < 0)
		adjusted_x = new_pos_X - PLAYER_SIZE;
	else
		adjusted_x = new_pos_X;
	if (data->dir_Y > 0)
		adjusted_y = new_pos_Y + PLAYER_SIZE;
	else if (data->dir_Y < 0)
		adjusted_y = new_pos_Y - PLAYER_SIZE;
	else
		adjusted_y = new_pos_Y;
	if (map->text[(int) new_pos_Y][(int) new_pos_X] == '1')
		return (true);
	if (map->text[(int) adjusted_y][(int) adjusted_x] == '1')
		return (true);
	if (!check_diags(data, adjusted_x, adjusted_y))
		return (true);
	return (false);
}

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
		old_dir_X = data->dir_X;
		data->dir_X = data->dir_X * cos(-ROT_SPEED) -  data->dir_Y * sin(-ROT_SPEED);
		data->dir_Y = old_dir_X * sin(-ROT_SPEED) + data->dir_Y * cos(-ROT_SPEED);
		old_plane_X = data->plane_X;
		data->plane_X = data->plane_X * cos(-ROT_SPEED) - data->plane_Y * sin(-ROT_SPEED);
		data->plane_Y = old_plane_X * sin(-ROT_SPEED) + data->plane_Y * cos(-ROT_SPEED);
		draw_walls(data);
	}
	if (mlx_is_key_down(data->window, MLX_KEY_RIGHT))
	{
		old_dir_X = data->dir_X;
		data->dir_X = data->dir_X * cos(ROT_SPEED) -  data->dir_Y * sin(ROT_SPEED);
		data->dir_Y = old_dir_X * sin(ROT_SPEED) + data->dir_Y * cos(ROT_SPEED);
		old_plane_X = data->plane_X;
		data->plane_X = data->plane_X * cos(ROT_SPEED) - data->plane_Y * sin(ROT_SPEED);
		data->plane_Y = old_plane_X * sin(ROT_SPEED) + data->plane_Y * cos(ROT_SPEED);
		draw_walls(data);
	}
	if (mlx_is_key_down(data->window, MLX_KEY_W))
	{
		new_pos_X = data->pos_X + (data->dir_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y + (data->dir_Y * MOVE_SPEED);
		if (!wall_collision(data, new_pos_X, new_pos_Y))
		{
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data);
		}
	}
	if (mlx_is_key_down(data->window, MLX_KEY_S))
	{
		new_pos_X = data->pos_X - (data->dir_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y - (data->dir_Y * MOVE_SPEED);
		if (!wall_collision(data, new_pos_X, new_pos_Y))
		{
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data);
		}
	}
	if (mlx_is_key_down(data->window, MLX_KEY_D))
	{
		new_pos_X = data->pos_X + (data->plane_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y + (data->plane_Y * MOVE_SPEED);
		if (!wall_collision(data, new_pos_X, new_pos_Y))
		{
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data);
		}
	}
	if (mlx_is_key_down(data->window, MLX_KEY_A))
	{
		new_pos_X = data->pos_X - (data->plane_X * MOVE_SPEED);
		new_pos_Y = data->pos_Y - (data->plane_Y * MOVE_SPEED);
		if (!wall_collision(data, new_pos_X, new_pos_Y))
		{
			data->pos_Y = new_pos_Y;
			data->pos_X = new_pos_X;
			draw_walls(data);
		}
	}
}
