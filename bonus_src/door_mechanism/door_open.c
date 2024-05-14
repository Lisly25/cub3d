/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:24:31 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/14 12:17:07 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	save_targeted_x_and_y(t_data *data)
{
	data->targeted_x = data->ray->tile_x;
	data->targeted_y = data->ray->tile_y;
}

// void	open_door(t_data *data)
// {
	
// }
