/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_more_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:18:50 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/23 17:41:01 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_sprite_index(t_map *mp, int x, int y)
{
	if (mp->buffer[y][x] == MAP_WALL)
		return (0);
	else if (mp->buffer[y][x] == MAP_EMPTY)
		return (1);
	else if (mp->buffer[y][x] == MAP_START)
		return (1);
	else if (mp->buffer[y][x] == MAP_END)
		return (3);
	else if (mp->buffer[y][x] == MAP_COLLECTABLE)
		return (1);
	return (-1);
}

int	assign_startend(t_map *mp, int x, int y, char tile)
{
	if (tile == MAP_START && mp->buffer[y][x] == tile)
	{
		mp->startx = x;
		mp->starty = y;
		return (1);
	}
	if (tile == MAP_END && mp->buffer[y][x] == tile)
	{
		mp->endx = x;
		mp->endy = y;
		return (1);
	}
	return (0);
}

void	handle_unknownchar(t_map *mp)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < mp->height)
	{
		x = 0;
		while (x < mp->width)
		{
			if (get_sprite_index(mp, x, y) < 0)
			{
				ft_putstr_fd("Error\nUnkown Character\n", 2);
				exit(2);
			}
			x++;
		}
		y++;
	}
}
