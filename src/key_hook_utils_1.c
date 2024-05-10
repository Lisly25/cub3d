/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:09:26 by fshields          #+#    #+#             */
/*   Updated: 2024/05/10 15:30:05 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left_key(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_X;
	data->dir_X = data->dir_X * cos(-ROT_SPEED) - data->dir_Y * sin(-ROT_SPEED);
	data->dir_Y = old_dir_x * sin(-ROT_SPEED) + data->dir_Y * cos(-ROT_SPEED);
	old_plane_x = data->plane_X;
	data->plane_X = data->plane_X * cos(-ROT_SPEED) - \
		data->plane_Y * sin(-ROT_SPEED);
	data->plane_Y = old_plane_x * sin(-ROT_SPEED) + \
		data->plane_Y * cos(-ROT_SPEED);
	draw_walls(data);
}

void	right_key(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_X;
	data->dir_X = data->dir_X * cos(ROT_SPEED) - data->dir_Y * sin(ROT_SPEED);
	data->dir_Y = old_dir_x * sin(ROT_SPEED) + data->dir_Y * cos(ROT_SPEED);
	old_plane_x = data->plane_X;
	data->plane_X = data->plane_X * cos(ROT_SPEED) - \
		data->plane_Y * sin(ROT_SPEED);
	data->plane_Y = old_plane_x * sin(ROT_SPEED) + \
		data->plane_Y * cos(ROT_SPEED);
	draw_walls(data);
}

void	w_key(t_data *data)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->pos_X + (data->dir_X * MOVE_SPEED);
	new_pos_y = data->pos_Y + (data->dir_Y * MOVE_SPEED);
	if (wall_collision(data, new_pos_x, new_pos_y))
		return ;
	data->pos_Y = new_pos_y;
	data->pos_X = new_pos_x;
	draw_walls(data);
}

void	s_key(t_data *data)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->pos_X - (data->dir_X * MOVE_SPEED);
	new_pos_y = data->pos_Y - (data->dir_Y * MOVE_SPEED);
	if (wall_collision(data, new_pos_x, new_pos_y))
		return ;
	data->pos_Y = new_pos_y;
	data->pos_X = new_pos_x;
	draw_walls(data);
}
