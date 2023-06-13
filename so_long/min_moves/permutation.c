/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:11:28 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/19 13:38:00 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int permute(int *arr, int l, int r)
// {
// 	int	i;
// 	int	temp;

// 	if (l == r)
// 	{
// 	}
// 	i = l - 1;
// 	while (++i <= r)
// 	{
// 		temp = arr[l];
// 		arr[l] = arr[i];
// 		arr[i] = temp;
// 		permute(arr, l + 1, r);
// 		temp = arr[l];
// 		arr[l] = arr[i];
// 		arr[i] = temp;
// 	}
// 	return (1);
// }

int	next_permutation(int *start, int *end)
{
	int	*i;
	int	*j;
	int	*k;

	if (start == end || start + 1 == end)
		return (0);
	i = end - 1;
	while (1)
	{
		j = i--;
		if (*i < *j)
		{
			k = end;
			while (!(*i < *--k))
				;
			ft_swap(i, k, sizeof(*i));
			ft_reverse(j, end, sizeof(*j));
			return (1);
		}
		if (i == start)
		{
			ft_reverse(start, end, sizeof (*start));
			return (0);
		}
	}
}
