/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:46:21 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/06 11:34:09 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*trim_identifier(char *config_line, unsigned int id_len)
{
	char	*temp;
	char	*trimmed;
	size_t	len;

	len = ft_strlen(config_line);
	temp = ft_substr(config_line, id_len, (ft_strlen(config_line) - id_len));
	free(config_line);
	if (temp == NULL)
		return (NULL);
	trimmed = ft_strtrim(temp, " \n");
	free(temp);
	if (trimmed == NULL)
		return (NULL);
	return (trimmed);
}

static char	*extract_config(char *id, t_assets *assets, t_vector *map)
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
			trimmed_info = trim_identifier(texture_info, 3);
			if (trimmed_info == NULL)
				map_validation_error("Malloc failure", map, assets);
			return (trimmed_info);
		}
		i++;
	}
	map_validation_error("Missing config information", map, assets);
	return (NULL);
}

static void	extract_rgb(char *id, t_assets *assets, t_vector *map)
{
	size_t	i;
	char	*color_info;
	char	*trimmed_info;

	i = 0;
	while (i < map->used_nodes)
	{
		if (ft_strncmp(id, map->text[i], 2) == 0)
		{
			if (ft_strlen(map->text[i]) < 7)
				break ;
			color_info = extract_array(map, i);
			if (color_info == NULL)
				map_validation_error("Malloc failure", map, assets);
			trimmed_info = trim_identifier(color_info, 2);
			if (trimmed_info == NULL)
				map_validation_error("Malloc failure", map, assets);
			if (copy_rgb_values(color_info, assets, id) == -1)//this should differentiate between bad values and malloc fails
				map_validation_error("Invalid color config", map, assets);
			return ;
		}
		i++;
	}
	map_validation_error("Missing config information", map, assets);
}

void	get_texture_info(t_vector *map, t_assets *assets)
{
	assets->north_file = extract_config("NO ", assets, map);
	ft_printf("North file path: %s\n", assets->north_file);
	assets->south_file = extract_config("SO ", assets, map);
	assets->east_file = extract_config("EA ", assets, map);
	assets->west_file = extract_config("WE ", assets, map);
	extract_rgb("F ", assets, map);
	ft_printf("Floor colour is: %d,%d,%d\n", assets->floor[0], assets->floor[1], assets->floor[2]);
	extract_rgb("C ", assets, map);
	if (clean_up_and_validate_map(map) == false)
	{
		free_assets_struct(assets);
		free_vector(map);
		exit(1);
	}
}

t_assets	*get_assets(t_vector *map)
{
	t_assets	*assets;

	validate_texture_info_format(map);
	//ft_printf("First texture info validity check passed!\n");
	assets = (t_assets *)malloc(sizeof(t_assets));
	if (assets == NULL)
		map_validation_error("Malloc failure", map, NULL);
	get_texture_info(map, assets);
	return (assets);
}
