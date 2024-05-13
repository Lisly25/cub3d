/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_textures_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:17:40 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/13 10:38:54 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	clean_up_textures(t_assets *assets)
{
	mlx_delete_texture(assets->north);
	mlx_delete_texture(assets->east);
	mlx_delete_texture(assets->south);
	mlx_delete_texture(assets->west);
}
