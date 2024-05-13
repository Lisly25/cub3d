/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_config_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:09:04 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/13 10:37:46 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	free_2d_array(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	if (arr != NULL)
		free(arr);
}

static size_t	get_array_size(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

static bool	validate_values(char **strs, int *nums, t_assets *assets, char *id)
{
	size_t	i;
	int		*asset;

	i = 0;
	if (id[0] == 'F')
		asset = assets->floor;
	else
		asset = assets->ceiling;
	while (i < 3)
	{
		if (ft_strlen(strs[i]) > 3)
			return (error_msg("Invalid RGB values"));
		if (nums[i] < 0 || nums[i] > 255)
			return (error_msg("Invalid RGB values"));
		asset[i] = nums[i];
		i++;
	}
	return (true);
}

bool	copy_rgb_values(char *trimmed_info, t_assets *assets, char *id)
{
	char	**num_strs;
	size_t	i;
	int		nums[3];
	int		return_value;

	return_value = -1;
	num_strs = ft_split(trimmed_info, ',');
	free(trimmed_info);
	if (num_strs == NULL)
		return (error_msg("Malloc failure"));
	if (get_array_size(num_strs) != 3)
	{
		free_2d_array(num_strs);
		return (error_msg("Malloc failure"));
	}
	i = 0;
	while (num_strs[i] != NULL)
	{
		nums[i] = ft_atoi(num_strs[i]);
		i++;
	}
	if (validate_values(num_strs, nums, assets, id) == true)
		return_value = true;
	free_2d_array(num_strs);
	return (return_value);
}
