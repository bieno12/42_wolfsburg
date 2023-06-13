/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:19:59 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/19 13:36:46 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_reverse(void *start, void *end, int size)
{
	end -= size;
	while (start < end)
	{
		ft_swap(start, end, size);
		start += size;
		end -= size;
	}
	return (1);
}
