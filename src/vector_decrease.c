/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_decrease.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:59:22 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/01 10:47:09 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//this is just for testing - delete before submission
void	print_vector_content(t_vector *vector)
{
	size_t	i;

	i = 0;
	if (vector == NULL)
		return ;
	ft_printf("Vector->used_nodes = %i\n", vector->used_nodes);
	ft_printf("Vector->max_nodes = %i\n", vector->max_nodes);
	ft_printf("Vector content:\n");
	while (i < vector->used_nodes)
	{
		ft_printf("%s", vector->text[i]);
		i++;
	}
}

static void	rearrange_vector(t_vector *vector, size_t index, char **new_text)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < index)
	{
		new_text[i] = vector->text[i];
		i++;
	}
	j = i + 1;
	while (j < vector->used_nodes)
	{
		new_text[i] = vector->text[j];
		i++;
		j++;
	}
	free(vector->text);
	vector->text = new_text;
	vector->used_nodes = vector->used_nodes - 1;
	vector->max_nodes = vector->max_nodes - 1;
}

char	*extract_array(t_vector *vector, size_t array_index)
{
	char	**new_text;
	char	*extracted_array;

	if (array_index >= vector->used_nodes)
		return (NULL);
	new_text = (char **)malloc(sizeof(char *) * (vector->max_nodes - 1));
	if (new_text == NULL)
		return (NULL);
	extracted_array = vector->text[array_index];
	rearrange_vector(vector, array_index, new_text);
	return (extracted_array);
}
