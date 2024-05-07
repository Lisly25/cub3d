/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:58:44 by fshields          #+#    #+#             */
/*   Updated: 2024/05/07 09:51:23 by skorbai          ###   ########.fr       */
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

t_data	*init_data(mlx_t *window, t_vector *map)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->window = window;
	data->map = map;
	data->plane_X = PLANE_X;
	data->plane_Y = PLANE_Y;
	set_start_position(data, map);
	return (data);
}
