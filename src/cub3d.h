/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:55:49 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/01 09:47:22 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/include/MLX42/MLX42.h"
# include "vector.h"
# include "fcntl.h"

# define MALLOC_ERROR 1 

typedef struct s_assets
{
	char	*west_file;
	char	*east_file;
	char	*north_file;
	char	*south_file;
	int		floor[3];
	int		ceiling[3];
}	t_assets;

//error.c
void		msg_and_exit(char *msg);
void		map_validation_error(char *msg, t_vector *map, t_assets *assets);

//read_map.c
t_vector	*read_map(int argc, char **argv);

//get_assets.c
t_assets	*get_assets(t_vector *map);

#endif