/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:47:28 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/09 09:44:11 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_vector	*map;
  	t_assets	*assets;
	t_data		*data;
	mlx_t		*window;

	map = read_map(argc, argv);
	assets = get_assets(map);
	window = init_window();
	data = init_data(window, map, assets);
	draw_walls(map->text, data);
	mlx_key_hook(window, &key_hook, data);
	mlx_loop(window);
	mlx_terminate(data->window);
	free_vector(map);
	free_assets_struct(assets);
	free(data);
}
