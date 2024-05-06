/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:28:49 by fshields          #+#    #+#             */
/*   Updated: 2024/05/06 15:10:11 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_line_height(double perp_wall_dist)
{
	if (!perp_wall_dist)
		return (SCREEN_HEIGHT);
	return ((int) SCREEN_HEIGHT / perp_wall_dist);
}

static void draw_wall_section(char **map, int x, mlx_image_t *line, mlx_t *window)
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
		if (mlx_image_to_window(window, line, x, draw_start) == -1)
			msg_and_exit("Image to window error");
		draw_start += 10;
	}
}

void	draw_walls(char **map, mlx_t *window)
{
	int			screen_x;
	mlx_image_t		*wall;
	mlx_texture_t	*wall_texture;
	
	screen_x = 0;
	wall_texture = mlx_load_png("./textures/backdrop.png");
	if (wall_texture == NULL)
		msg_and_exit("Texture load failure");
	wall = mlx_texture_to_image(window, wall_texture);
	if (wall == NULL)
	if (mlx_resize_image(wall, 10, 10) == false)
		msg_and_exit("resize error");
	while (screen_x < SCREEN_WIDTH)
	{
		draw_wall_section(map, screen_x, wall, window);
		screen_x += 10;
	}	
}
