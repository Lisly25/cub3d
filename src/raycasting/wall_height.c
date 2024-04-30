/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:28:49 by fshields          #+#    #+#             */
/*   Updated: 2024/04/30 14:17:11 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_line_height(double perp_wall_dist)
{
	return ((int) SCREEN_HEIGHT / perp_wall_dist);
}

static void draw_wall_section(char **map, mlx_t *window, int x, mlx_image_t *line)
{
	int		draw_start;
	int		draw_end;
	double 	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		line_height;
	double	ray_direction_x;
	double	ray_direction_y;
	
	ray_direction_x = adjust_ray_direction(1, x);
	ray_direction_y = adjust_ray_direction(2, x);
	perp_wall_dist = get_ray_length(ray_direction_x, ray_direction_y, &step_x, &step_y, POSITION_X, POSITION_Y, POSITION_X, POSITION_Y, map);
	line_height = get_line_height(perp_wall_dist);
	draw_start = -(line_height) / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end =  line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	while (draw_start <= draw_end)
	{
		mlx_put_pixel(line, x, draw_start, 0x00FF0000);
		draw_start++;
	}
}

void	draw_walls(char **map, mlx_t *window)
{
	int			screen_x;
	mlx_image_t	*wall_pixel;
	
	wall_pixel = mlx_new_image(window, 1, 1);
	if (wall_pixel == NULL)
		msg_and_exit("Failed to create image");//also, free the map
	while (screen_x < SCREEN_WIDTH)
	{
		draw_wall_section(map, window, screen_x, wall_pixel);
		screen_x++;
	}	
}
