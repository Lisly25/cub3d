/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:29:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/06 11:32:45 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	validate_start_orientation(t_vector *map)
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

/*static void	mark_neighbour(t_vector *map)
{
	
}

static bool	validate_if_walled(t_vector *map)
{
	size_t	i;
	size_t	j;
	size_t	start_pos;

	i = 0;
	j = 0;
	while (map->text[0][i] != '\n')
	{
		
	}
}*/

bool	validate_map_shape(t_vector *map)
{
	if (validate_start_orientation(map) == false)
		return (false);
	//if (validate_if_walled(map) == false)
	//	return (false);
	return (true);
}
