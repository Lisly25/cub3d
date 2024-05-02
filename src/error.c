/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:15:33 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/02 13:33:42 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_assets_struct(t_assets *assets)
{
	if (assets->north_file != NULL)
		free(assets->north_file);
	if (assets->south_file != NULL)
		free(assets->south_file);
	if (assets->east_file != NULL)
		free(assets->east_file);
	if (assets->west_file != NULL)
		free(assets->west_file);
	free(assets);
}

void	map_validation_error(char *msg, t_vector *map, t_assets *assets)
{
	if (assets != NULL)
		free_assets_struct(assets);
	if (map != NULL)
		free_vector(map);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	msg_and_exit(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	error_msg(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
}
