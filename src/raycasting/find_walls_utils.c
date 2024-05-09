/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:11:31 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/09 15:46:41 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_if_valid_pos(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j] != NULL)
		j++;
	if (j < y)
		return (false);
	while (map[y][i] != '\0')
		i++;
	if (i < x)
		return (false);
	return (true);
}
