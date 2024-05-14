/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skorbai <skorbai@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:24:31 by skorbai           #+#    #+#             */
/*   Updated: 2024/05/14 16:17:02 by skorbai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static useconds_t	get_current_sec(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec);
}

void	ft_sleep(useconds_t duration)
{
	useconds_t		start_time;
	useconds_t		elapsed_time_goal;
	useconds_t		elapsed_time;

	start_time = get_current_sec();
	elapsed_time_goal = (start_time + duration);
	elapsed_time = 0;
	while (elapsed_time < elapsed_time_goal)
	{
		usleep(500);
		elapsed_time = get_current_sec();
	}
}

static void	flicker_door(t_data *data, char mode, int anim_x, int anim_y)
{
	data->map->text[anim_y][anim_x] = mode;
	draw_walls(data);
	ft_sleep(1);
}

void	play_opening_animation(t_data *data)
{
	int	anim_x;
	int	anim_y;
	int	i;

	anim_x = data->targeted_x;
	anim_y = data->targeted_y;
	i = 0;
	if (data->map->text[data->targeted_y][data->targeted_x] != 'D')
		return ;
	while (i < 3)
	{
		flicker_door(data, 'd', anim_x, anim_y);
		flicker_door(data, 'D', anim_x, anim_y);
		i++;
	}
	flicker_door(data, '0', anim_x, anim_y);
	// data->map->text[anim_y][anim_x] = 'd';
	// draw_walls(data);
	// ft_sleep(1);
	// data->map->text[anim_y][anim_x] = 'D';
	// draw_walls(data);
	// ft_sleep(1);
	// data->map->text[anim_y][anim_x] = 'd';
	// draw_walls(data);
	// ft_sleep(1);
	// data->map->text[anim_y][anim_x] = 'D';
	// draw_walls(data);
	// ft_sleep(1);
	// data->map->text[anim_y][anim_x] = '0';
	// draw_walls(data);
	// ft_sleep(1);
}

void	save_targeted_x_and_y(t_data *data)
{
	data->targeted_x = data->ray->tile_x;
	data->targeted_y = data->ray->tile_y;
}

// void	open_door(t_data *data)
// {
// 	struct timeval	current;

// 	if (data->map->text[data->targeted_y][data->targeted_x] != 'D')
// 		return ;
// 	gettimeofday(&current, NULL);
// 	data->last_opening = current.tv_sec;
// 	//play_opening_animation(data);
// }
