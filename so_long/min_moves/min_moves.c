/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:30:19 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/20 15:43:23 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#define MAX_CITIES 20

int		fill_cities(t_map *mp, t_city *cities);

int		*calculate_distances(t_map *mp, t_city *cities, int n_cities);

int		dfs(t_map *mp, t_city curr, t_city dest, int **visited);

int		calc_min_moves(int n_cities, int *distances);

t_city	*assign_city(t_city *city, int x, int y);

int		**create_array(int width, int height);

int		next_permutation(int *start, int *end);

int	get_min_moves(t_vars *vars, t_map *mp)
{
	t_city	cities[MAX_CITIES + 1];
	int		*distances;
	int		min_moves;
	int		n_cities;

	(void) vars;
	n_cities = fill_cities(mp, cities);
	distances = calculate_distances(mp, cities, n_cities);
	min_moves = calc_min_moves(n_cities, distances);
	(void) distances;
	free(distances);
	return (min_moves);
}

//null terminating the cities array wouldn't result in any problem
//as a map cannot have a city at 0, 0
int	fill_cities(t_map *mp, t_city *cities)
{
	int					i;
	unsigned int		x;
	unsigned int		y;
	t_city				city;

	i = 1;
	y = -1;
	assign_city(&city, mp->startx, mp->starty);
	cities[0] = city;
	while (++y < mp->height)
	{
		x = -1;
		while (++x < mp->width)
		{
			if (mp->buffer[y][x] == MAP_COLLECTABLE)
			{
				city.x = x;
				city.y = y;
				cities[i++] = city;
			}
		}
	}
	assign_city(&city, mp->endx, mp->endy);
	cities[i++] = city;
	return (i);
}

//to reference distance[1][2] = distance[1 * n_cities + 2]
int	*calculate_distances(t_map *mp, t_city *cities, int n_cities)
{
	int	*distances;
	int	i;
	int	j;
	int	**visited;

	visited = create_array(mp->width, mp->height);
	distances = malloc(n_cities * n_cities * sizeof(t_city));
	i = -1;
	while (++i < n_cities)
	{
		j = i - 1;
		while (++j < n_cities)
		{
			distances[i * n_cities + j]
				= dfs(mp, cities[i], cities[j], visited);
			distances[j * n_cities + i] = distances[i * n_cities + j];
		}
	}
	i = -1;
	while (++i < (int)mp->height)
		free(visited[i]);
	free(visited);
	return (distances);
}

static int	calc_moves(int n_cities, int *indicies, int *distances)
{
	long int	sum;
	int			i;

	sum = 0;
	i = -1;
	while (++i < n_cities - 1)
	{
		sum += distances[n_cities * (indicies[i]) + indicies[i + 1]];
	}
	if (sum > 0x7fffffff - 1)
		sum = 0x7fffffff - 1;
	return ((int)sum);
}

int	calc_min_moves(int n_cities, int *distances)
{
	int	*indicies;
	int	i;
	int	min_sum;

	indicies = malloc(n_cities * sizeof (int));
	i = -1;
	while (++i < n_cities)
		indicies[i] = i;
	min_sum = 0x7fffffff - 1;
	while (1)
	{
		min_sum = ft_min(min_sum, calc_moves(n_cities, indicies, distances));
		if (!next_permutation(indicies + 1, indicies + n_cities - 1))
			break ;
	}
	free(indicies);
	return (min_sum);
}
