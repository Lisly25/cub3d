/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:58:44 by fshields          #+#    #+#             */
/*   Updated: 2024/05/08 10:30:22 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_t	*init_window()
{
	mlx_t	*window;
	
	window = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d", false);
	if (!window)
		msg_and_exit("mlx init failure"); // map still needs freeing
	return (window);
}

static bool	init_floor_and_ceiling_img(t_data *data)
{
	data->ceiling = mlx_new_image(data->window, RENDER_SCALE, RENDER_SCALE);
	if (data->ceiling == false)
		return (false);
	data->floor = mlx_new_image(data->window, RENDER_SCALE, RENDER_SCALE);
	if (data->floor == false)
		return (false);
	return (true);
}

t_data	*init_data(mlx_t *window, t_vector *map, t_assets *assets)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		free_all_n_exit("Malloc failure", data, assets, map);
	data->window = window;
	data->map = map;
	data->plane_X = PLANE_X;
	data->plane_Y = PLANE_Y;
	set_start_position(data, map);
	if (init_floor_and_ceiling_img(data) == false)
		free_all_n_exit("Malloc failure", data, assets, map);
	return (data);
}
