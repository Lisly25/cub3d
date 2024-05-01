/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:46:21 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/01 12:41:00 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*trim_identifier(char *config_line)
{
	char	*temp;
	char	*trimmed;
	size_t	len;

	len = ft_strlen(config_line);
	temp = ft_substr(config_line, 3, (ft_strlen(config_line) - 3));
	free(config_line);
	if (temp == NULL)
		return (NULL);
	trimmed = ft_strtrim(temp, " \n");
	free(temp);
	if (trimmed == NULL)
		return (NULL);
	return (trimmed);
}

static char	*extract_texture_path(char *id, t_assets *assets, t_vector *map)
{
	size_t	i;
	char	*texture_info;
	char	*trimmed_info;

	i = 0;
	while (i < map->used_nodes)
	{
		if (ft_strncmp(id, map->text[i], 3) == 0)
		{
			if (ft_strlen(map->text[i]) < 4)
				break ;
			texture_info = extract_array(map, i);
			if (texture_info == NULL)
				map_validation_error("Malloc failure", map, assets);
			trimmed_info = trim_identifier(texture_info);
			if (trimmed_info == NULL)
				map_validation_error("Malloc failure", map, assets);
			return (trimmed_info);
		}
		i++;
	}
	map_validation_error("Missing config information", map, assets);
	return (NULL);
}

void	get_texture_info(t_vector *map, t_assets *assets)
{
	assets->north_file = extract_texture_path("NO ", assets, map);
	ft_printf("North file path: %s\n", assets->north_file);
	assets->south_file = extract_texture_path("SO ", assets, map);
	assets->east_file = extract_texture_path("EA ", assets, map);
	assets->west_file = extract_texture_path("WE ", assets, map);
	//extract_rgb("F", assets, map);
	//extract_rgb("C", assets, map);
}

t_assets	*get_assets(t_vector *map)
{
	t_assets	*assets;

	validate_texture_info_format(map);
	ft_printf("First texture info validity check passed!\n");
	assets = (t_assets *)malloc(sizeof(t_assets));
	if (assets == NULL)
		map_validation_error("Malloc failure", map, NULL);
	get_texture_info(map, assets);
	return (assets);
}
