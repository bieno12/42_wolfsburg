/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:37:43 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/19 17:19:44 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_city	*assign_city(t_city *city, int x, int y)
{
	city->x = x;
	city->y = y;
	return (city);
}

t_city	*new_city(int x, int y)
{
	return (assign_city(malloc(sizeof (t_city)), x, y));
}

int	**create_array(int width, int height)
{
	int	**arr;
	int	i;

	arr = malloc(height * sizeof(int *));
	i = -1;
	while (++i < height)
	{
		arr[i] = malloc(width * sizeof (int));
		ft_memset(arr[i], 0, width * sizeof(int));
	}
	return (arr);
}
