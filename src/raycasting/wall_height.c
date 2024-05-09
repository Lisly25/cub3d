/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_height.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:28:49 by fshields          #+#    #+#             */
/*   Updated: 2024/05/09 11:48:25 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	get_line_height(double perp_wall_dist)
{
	if (!perp_wall_dist)
		return (SCREEN_HEIGHT);
	return ((int) SCREEN_HEIGHT / perp_wall_dist);
}

static void draw_wall_section(char **map, int x, mlx_image_t *line, t_data *data)
{
	int		draw_start;
	int		draw_end;
	double 	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		line_height;
	double	ray_direction_x;
	double	ray_direction_y;
	
	ray_direction_x = adjust_ray_direction(1, x, data);
	printf("ray_dir_x = %f\n", ray_direction_x);
	ray_direction_y = adjust_ray_direction(2, x, data);
	printf("ray_dir_y = %f\n", ray_direction_y);
	printf("----- x * y: %f\n", ray_direction_x * ray_direction_y);
	perp_wall_dist = get_ray_length(ray_direction_x, ray_direction_y, &step_x, &step_y, data->pos_X, data->pos_Y, map);
	line_height = get_line_height(perp_wall_dist);
	draw_start = -(line_height) / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end =  line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	draw_ceiling(x, draw_start, data);
	while (draw_start <= draw_end)
	{
		if (mlx_image_to_window(data->window, line, x, draw_start) == -1)
			msg_and_exit("Image to window error");
		draw_start += RENDER_SCALE;
	}
	draw_floor(x, draw_end, data);
}

void	draw_walls(char **map, t_data *data)
{
	int				screen_x;

	screen_x = 0;
	if (init_wall_images(data) == false)
		msg_and_exit("image creation error");
	if (init_floor_and_ceiling_img(data) == false)
		msg_and_exit("Failed to create image");
	if (mlx_resize_image(data->wall, RENDER_SCALE, RENDER_SCALE) == false)
		msg_and_exit("resize error");
	while (screen_x < SCREEN_WIDTH)
	{
		draw_wall_section(map, screen_x, data->wall, data);
		screen_x += RENDER_SCALE;
	}
}
