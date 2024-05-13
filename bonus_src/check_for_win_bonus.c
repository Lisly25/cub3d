/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:39:03 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/13 16:49:08 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_for_win(t_data *data)
{
	t_vector	*map;
	int			new_x;
	int			new_y;

	map = data->map;
	new_x = (int)data->pos_x;
	new_y = (int)data->pos_y;
	if (map->text[new_y][new_x] == 'P')
	{
		ft_printf("YOU WIN!");
		mlx_close_window(data->window);
	}
}
