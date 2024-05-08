/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:29:36 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/07 16:54:48 by skorbai          ###   ########.fr       */
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

bool	check_neighbours_for_char(t_vector *map, char c, size_t x, size_t y)
{
	if ((y < map->used_nodes - 1) && (map->text[y + 1][x] == c))
		return (true);
	if ((x < (ft_strlen(map->text[y]) - 1)) && (map->text[y][x + 1] == c))
		return (true);
	if ((y != 0) && (map->text[y - 1][x] == c))
		return (true);
	if ((x != 0) && (map->text[y][x - 1] == c))
		return (true);
	return (false);
}

static bool	validate_if_walled(t_vector *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < map->used_nodes)
	{
		while (map->text[y][x] != '\0')
		{
			if (map->text[y][x] == '0')
			{
				if (check_neighbours_for_char(map, ' ', x, y) == true)
					return (false);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (true);
}

static bool	ask_whether_to_continue(void)
{
	char	*input;
	int		result;

	ft_printf("Map has inaccessible rooms. Continue anyway? (Y/N)\n");
	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
			return (error_msg("Malloc failure/no answer"));
		if ((ft_strlen(input) == 2) && (input[0] == 'Y' || input[0] == 'N'))
			break ;
		else
			ft_printf("Not a valid answer");
		free(input);
	}
	if (input[0] == 'Y')
		result = true;
	else
		result = false;
	free(input);
	return (result);
}

bool	validate_map_shape(t_vector *map)
{
	int	map_accessibility_result;

	if (validate_start_orientation(map) == false)
		return (false);
	if (validate_if_walled(map) == false)
		return (error_msg("Map must be surrounded by walls"));
	map_accessibility_result = check_if_all_map_is_accessible(map);
	if (map_accessibility_result == 2)
		return (false);
	else if (map_accessibility_result == false)
	{
		if (ask_whether_to_continue() == false)
			return (false);
	}
	return (true);
}
