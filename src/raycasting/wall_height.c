/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:28:49 by fshields          #+#    #+#             */
/*   Updated: 2024/05/09 16:01:49 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_line_height(t_data *data)
{
	t_ray	*ray;

	ray = data->ray;
	if (!ray->perp_wall_dist)
		ray->line_height = SCREEN_HEIGHT;
	ray->line_height = ((int) SCREEN_HEIGHT / ray->perp_wall_dist);
}

static void draw_wall_section(int x, t_data *data)
{
	int		draw_start;
	int		draw_end;
	int		step_x;
	int		step_y;
	t_ray	*ray;

	ray = data->ray;
	ray->ray_direction_x = adjust_ray_direction(1, x, data);
	ray->ray_direction_y = adjust_ray_direction(2, x, data);
	get_ray_length(&step_x, &step_y, data);
	get_line_height(data);
	draw_start = -(ray->line_height) / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = ray->line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	draw_ceiling(x, draw_start, data);
	draw_textured_wall_section(draw_start, draw_end, x, data, ray->side);
	// while (draw_start <= draw_end)
	// {
	// 	mlx_put_pixel(data->img, x, draw_start, 0x43ff64d9);
	// 	draw_start++;
	// }
	draw_floor(x, draw_end, data);
}

void	draw_walls(t_data *data)
{
	int				screen_x;

	screen_x = 0;
	while (screen_x < SCREEN_WIDTH)
	{
		draw_wall_section(screen_x, data);
		screen_x++;
	}
}
