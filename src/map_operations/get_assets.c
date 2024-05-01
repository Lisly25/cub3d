/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:46:21 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/01 09:52:56 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_texture_info(t_vector *map, t_assets *assets)
{
	extract_texture_path("NO", assets, map);
	extract_texture_path("SO", assets, map);
	extract_texture_path("EA", assets, map);
	extract_texture_path("WE", assets, map);
	extract_rgb("F", assets, map);
	extract_rgb("C", assets, map);
}

t_assets	*get_assets(t_vector *map)
{
	t_assets	*assets;

	assets = (t_assets *)malloc(sizeof(t_assets));
	if (assets == NULL)
		map_validation_error("Malloc failure", map, NULL);
	get_texture_info(map, assets);
}
