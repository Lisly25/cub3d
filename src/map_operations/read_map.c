/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:13:25 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/16 10:36:40 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	open_map(char *filename)
{
	char	*file_extension;
	size_t	len;
	int		map_fd;

	len = ft_strlen(filename);
	if (len < 5)
		msg_and_exit("Invalid filename");
	file_extension = filename + (len - 4);
	if (ft_strncmp(file_extension, ".cub", 4) != 0)
		msg_and_exit("Invalid map - must have .cub extension");
	if (ft_strncmp((filename + (len - 5)), "/.cub", 5) == 0)
		msg_and_exit("Invalid map - must have .cub extension");
	map_fd = open(filename, O_DIRECTORY);
	if (map_fd != -1)
	{
		close(map_fd);
		msg_and_exit("Invalid map - file is a directory");
	}
	map_fd = open(filename, O_RDONLY);
	if (map_fd == -1)
		msg_and_exit("File could not be opened");
	return (map_fd);
}

bool	check_map_dimensions(t_vector *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (map->used_nodes >= 65)
		return (error_msg("Map too large - too many lines"));
	while (j < map->used_nodes)
	{
		while (map->text[j][i] != '\0')
		{
			i++;
			if (i == 65)
				return (error_msg("Map too large - line(s) too long"));
		}
		i = 0;
		j++;
	}
	return (true);
}

t_vector	*read_map(char **argv)
{
	int			map_fd;
	t_vector	*map;
	char		*map_line;

	map_fd = open_map(argv[1]);
	if (map_fd < 0)
		msg_and_exit("failed to open map");
	map = vector_new(1);
	if (map == NULL)
		msg_and_exit("Malloc failure");
	while (1)
	{
		map_line = get_next_line(map_fd);
		if (map_line == NULL)
			break ;
		if (vector_add_back(map, map_line) == MALLOC_ERROR)
		{
			free_vector(map);
			msg_and_exit("Malloc failure");
		}
	}
	close(map_fd);
	return (map);
}
