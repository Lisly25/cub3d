/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textured_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:43:02 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/10 11:31:40 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static double	get_wall_x(int side, t_data *data, t_ray *ray)
{
	double	wall_x;

	if (side == 0)
		wall_x = data->pos_Y + ray->perp_wall_dist * ray->ray_direction_y;
	else
		wall_x = data->pos_X + ray->perp_wall_dist * ray->ray_direction_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

static int	get_texture_x(int side, t_data *data)
{
	int		texture_x;
	double	wall_x;
	t_ray	*ray;

	ray = data->ray;
	wall_x = get_wall_x(side, data, ray);
	texture_x = (int)(wall_x * ((double) TEXTURE_WIDTH));
	if (side == 0 && (ray->ray_direction_x > 0))
		texture_x = TEXTURE_WIDTH - texture_x - 1;
	if (side == 1 && (ray->ray_direction_y < 0))
		texture_x = TEXTURE_WIDTH - texture_x - 1;
	return (texture_x);
}

uint32_t	get_element_by_coordinate(int x, int y, uint32_t *arr)
{
	uint32_t	colour;
	int			index;

	if (y == 0)
		index = x;
	else
		index = (y * TEXTURE_WIDTH) + x;
	colour =  arr[index];
	return (colour);
}

void	draw_textured_wall_section(int draw_start, int draw_end, int x, t_data *data, int side)
{
	double			step;
	double			texture_position;
	int				texture_y;
	int				texture_x;
	uint32_t		color;
	int				y;
	t_ray			*ray;
	t_assets		*assets;
	mlx_texture_t	*texture;

	ray = data->ray;
	assets = data->assets;
	texture = assets->north;
	step = 1.0 * TEXTURE_HEIGHT / ray->line_height;
	texture_x = get_texture_x(side, data);
	texture_position = (draw_start - SCREEN_HEIGHT / 2 + ray->line_height / 2) * step;
	y = draw_start;
	while (y < draw_end)
	{
		texture_y = (int)texture_position & (TEXTURE_HEIGHT - 1);
		texture_position += step;
		color = get_element_by_coordinate(texture_x, texture_y, (uint32_t *)texture->pixels);
		mlx_put_pixel(data->img, x, y, color);
		y++;
	}
}
