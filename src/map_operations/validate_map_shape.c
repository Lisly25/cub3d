/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:29:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/02 16:21:46 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	get_and_validate_start_orientation(t_vector *map)
{
	bool	is_start_orientation_found;
	size_t	i;
	size_t	j;

	is_start_orientation_found = false;
	i = 0;
	j = 0;
	while (i < map->used_nodes)
	{
		while (map->text[i][j] != '\0')
		{
			if (ft_strchr("NWSE", map->text[i][j]) != NULL)
			{
				if (is_start_orientation_found == true)
					return (error_msg("More than one start position"));
				is_start_orientation_found = true;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (is_start_orientation_found == false)
		return (error_msg("Missing start position"));
	return (true);
}

bool	validate_map_shape(t_vector *map)
{
	if (get_and_validate_start_orientation(map) == false)
		return (false);
	return (true);
}
