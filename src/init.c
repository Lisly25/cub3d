/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:58:44 by fshields          #+#    #+#             */
/*   Updated: 2024/05/08 17:19:29 by skorbai          ###   ########.fr       */
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

static void	*ft_int_memset(void *dest, int rgb[3], size_t len)
{
	uint8_t	*buffer;
	size_t	i;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	buffer = (uint8_t *) dest;
	i = 0;
	while (len > i)
	{
		buffer[i] = r;
		i++;
		buffer[i] = g;
		i++;
		buffer[i] = b;
		i++;
		buffer[i] = 255;
		i++;
	}
	return (buffer);
}

static void	set_img_to_color(mlx_image_t *img, int rgb[3])
{
	size_t		pixel_count;

	pixel_count = (RENDER_SCALE * RENDER_SCALE * 4);
	img->pixels = ft_int_memset(img->pixels, rgb, pixel_count);
}

/*static void	set_img_to_color(mlx_image_t *img, int rgb[3])
{
	uint32_t	colour;
	int			i;
	
	while (i < (RENDER_SCALE * RENDER_SCALE))
	{
		ft_memmove(img->pixels, rgb)
	}

}*/

static bool	init_floor_and_ceiling_img(t_data *data, t_assets *assets)
{
	data->ceiling = mlx_new_image(data->window, RENDER_SCALE, RENDER_SCALE);
	if (data->ceiling == false)
		return (false);
	data->floor = mlx_new_image(data->window, RENDER_SCALE, RENDER_SCALE);
	if (data->floor == false)
		return (false);
	printf("Ceiling data is: R: %d G: %d B: %d", assets->ceiling[0], assets->ceiling[1], assets->ceiling[2]);
	set_img_to_color(data->ceiling, assets->ceiling);
	set_img_to_color(data->floor, assets->floor);
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
	if (init_floor_and_ceiling_img(data, assets) == false)
		free_all_n_exit("Malloc failure", data, assets, map);
	return (data);
}
