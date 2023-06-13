/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:32:10 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/18 18:59:27 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	assign_startend(t_map *mp, int x, int y, char tile);

char	**read_file(const char *filename)
{
	int		fd;
	int		len;
	char	*result[MAP_MAX_ROWS];
	char	*temp;
	char	**res;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
	len = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		result[len++] = ft_strtrim(temp, "\n");
		free(temp);
		temp = get_next_line(fd);
	}
	res = malloc((sizeof (char *)) * (len + 1));
	ft_memcpy(res, result, len * sizeof(char *));
	res[len] = 0;
	close(fd);
	return (res);
}

int	validate_dimensions(t_map *mp)
{
	unsigned int	i;

	mp->height = 0;
	while (mp->buffer[mp->height])
		mp->height++;
	if (mp->height < 3)
		return (-1);
	mp->width = ft_strlen(mp->buffer[0]);
	if (mp->width < 4)
		return (-1);
	i = 0;
	while (++i < mp->height)
	{
		if (ft_strlen(mp->buffer[i]) != mp->width)
			return (-1);
	}
	return (0);
}

int	validate_borders(t_map *mp)
{
	unsigned int	i;

	i = -1;
	while (++i < mp->width)
		if (mp->buffer[0][i] != MAP_WALL
			|| mp->buffer[mp->height - 1][i] != MAP_WALL)
			return (-1);
	i = -1;
	while (++i < mp->height)
		if (mp->buffer[i][0] != MAP_WALL
			|| mp->buffer[i][mp->width - 1] != MAP_WALL)
			return (-1);
	return (0);
}

int	validate_startend(t_map *mp)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	found_start;
	unsigned int	found_end;

	y = -1;
	found_start = 0;
	found_end = 0;
	while (++y < mp->height)
	{
		x = -1;
		while (++x < mp->width)
		{
			found_start += assign_startend(mp, x, y, MAP_START);
			found_end += assign_startend(mp, x, y, MAP_END);
		}
	}
	return (!(found_end == 1 && found_start == 1) * -1);
}
