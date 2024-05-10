/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:15:28 by fshields          #+#    #+#             */
/*   Updated: 2024/05/10 15:27:40 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	d_key(t_data *data)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->pos_X + (data->plane_X * MOVE_SPEED);
	new_pos_y = data->pos_Y + (data->plane_Y * MOVE_SPEED);
	if (wall_collision(data, new_pos_x, new_pos_y))
		return ;
	data->pos_Y = new_pos_y;
	data->pos_X = new_pos_x;
	draw_walls(data);
}

void	a_key(t_data *data)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = data->pos_X - (data->plane_X * MOVE_SPEED);
	new_pos_y = data->pos_Y - (data->plane_Y * MOVE_SPEED);
	if (wall_collision(data, new_pos_x, new_pos_y))
		return ;
	data->pos_Y = new_pos_y;
	data->pos_X = new_pos_x;
	draw_walls(data);
}

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

bool	wall_collision(t_data *data, double new_pos_X, double new_pos_Y)
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
