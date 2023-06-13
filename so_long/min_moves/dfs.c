/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:36:03 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/20 15:43:46 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void draw_trace(int **visited)
// {
// 	draw_map(vars, vars->map);

// 	for(unsigned int i = 0; i < vars->map->height; i++)
// 	{
// 		for(unsigned int j = 0; j < vars->map->width; j++)
// 		{
// 			if(visited[i][j])
// 				fill_rect(vars->buffer, j * TILE_SIZE + TILE_SIZE /2 - 25,
// 						i * TILE_SIZE+ TILE_SIZE /2 - 25, 50, 50, 0x00ff00ff);
// 		}
// 	}
// 	mlx_put_image_to_window(vars->mlx, vars->win_ptr, vars->buffer->img, 0, 0);
// 	usleep(100000);
// }

static int	is_valid(t_map *mp, int x, int y, int **visited)
{
	return (x >= 0 && y >= 0 && x < (int)mp->width && y < (int)mp->height
		&& mp->buffer[y][x] != MAP_WALL
		&& !visited[y][x]);
}

int	dfs(t_map *mp, t_city curr, t_city dest, int **visited)
{
	int					min_dest;
	int					d;
	t_city				new_curr;
	static const int	dx[] = {-1, 1, 0, 0};
	static const int	dy[] = {0, 0, -1, 1};

	if (curr.x == dest.x && curr.y == dest.y)
		return (0);
	min_dest = 0x7fffffff - 1;
	visited[curr.y][curr.x] = 1;
	d = -1;
	while (++d < 4)
	{
		new_curr.x = curr.x + dx[d];
		new_curr.y = curr.y + dy[d];
		if (is_valid(mp, new_curr.x, new_curr.y, visited))
			min_dest = ft_min(min_dest, dfs(mp, new_curr, dest, visited) + 1);
	}
	visited[curr.y][curr.x] = 0;
	return (min_dest);
}
