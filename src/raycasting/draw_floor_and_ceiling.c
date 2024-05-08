/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:08:02 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/08 13:23:11 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ceiling(int x, int wall_start, t_data *data)
{
	int	y;

	y = 0;
	while (y < wall_start)
	{
		if (mlx_image_to_window(data->window, data->ceiling, x, \
		y) == -1)
			msg_and_exit("Malloc error - this is not sufficient error handling, but we'll get back to it");
		y += RENDER_SCALE;
	}
}

void	draw_floor(int x, int wall_end, t_data *data)
{
	while (wall_end < (SCREEN_HEIGHT - 1))
	{
		if (mlx_image_to_window(data->window, data->floor, x, \
		wall_end) == -1)
			msg_and_exit("Malloc error - this is not sufficient error handling, but we'll get back to it");
		wall_end += RENDER_SCALE;
	}
}
