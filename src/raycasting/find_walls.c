/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:21:57 by fshields          #+#    #+#             */
/*   Updated: 2024/05/06 12:00:27 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "float.h"//maybe remove this later?

double	adjust_ray_direction(int mode, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double) SCREEN_HEIGHT - 1;
	if (mode == 1)//for ray direction x
		return (DIRECTION_X + PLANE_X * camera_x);
	return (DIRECTION_Y - PLANE_Y * camera_x);
}

//will either be called as get_delta_dist(direction_X + PLANE_X * camera_X)
//or get_delta_dist(direction_Y + PLANE_Y * camera_X)
static double	get_delta_dist(double ray_direction)
{
	if (ray_direction == 0)
		return (DBL_MAX);
	else
	{
		return (fabs(1 / ray_direction));
	}
}

//works either for x or y
static double	get_side_distance(double ray_direction, int *step, double position, int map)
{
	double	side_distance;
	
	if (ray_direction < 0)
	{
		*step = -1;
		side_distance = (position - map) * get_delta_dist(ray_direction);
	}
	else
	{
		*step = 1;
		side_distance = (map + 1.0 - position) * get_delta_dist(ray_direction);
	}
	return (side_distance);
}

static double	adjust_for_camera_plane(double side_distance, double ray_direction)
{
	return (side_distance - get_delta_dist(ray_direction));
}

//returns perpendicular distance to wall
double	get_ray_length(double ray_direction_x, double ray_direction_y, int *step_x, int *step_y, double position_x, double position_y, int map_x, int map_y, char **map)
{
	double	side_distance_x;
	double	side_distance_y;
	bool	hit;
	int		side;
	
	hit = false;
	side = -1;
	side_distance_x = get_side_distance(ray_direction_x, step_x, position_x, map_x);
	side_distance_y = get_side_distance(ray_direction_y, step_y, position_y, map_y);
	while (hit == false)
	{
		if (side_distance_x < side_distance_y)
		{
			side_distance_x += get_delta_dist(ray_direction_x);
			map_x += *step_x;
			side = 0;
		}
		else
		{
			side_distance_y += get_delta_dist(ray_direction_y);
			map_y += *step_y;
			side = 1;
		}
		if (map[map_x][map_y] == '1')
		{
			hit = true;
		}
	}
	if (side == 0)
		return (adjust_for_camera_plane(side_distance_x, ray_direction_x));
	else
		return (adjust_for_camera_plane(side_distance_y, ray_direction_y));
}

