/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:37:30 by fshields          #+#    #+#             */
/*   Updated: 2024/05/14 13:31:32 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	init_staff(t_data *data)
{
	mlx_texture_t	*staff_tex;

	staff_tex = mlx_load_png("./bonus_src/sprites/staff_1.png");
	if (!staff_tex)
		msg_and_exit("texture load error");
	data->staff = mlx_texture_to_image(data->window, staff_tex);
	mlx_delete_texture(staff_tex);
	if (!data->staff)
		msg_and_exit("image load error");
	if (mlx_resize_image(data->staff, 200, 300) == false)
		msg_and_exit("image resize error");
	if (mlx_image_to_window(data->window, data->staff, 750, 650) == -1)
		msg_and_exit("mlx image to window error");
}
