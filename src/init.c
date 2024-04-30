/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:58:44 by fshields          #+#    #+#             */
/*   Updated: 2024/04/30 11:20:53 by fshields         ###   ########.fr       */
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