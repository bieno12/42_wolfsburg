/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:27:34 by zh                #+#    #+#             */
/*   Updated: 2022/12/16 15:45:26 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		value;

	value = (unsigned char) c;
	ptr = s;
	while (n--)
	{
		if (*ptr == value)
			return ((void *)ptr);
		else
			ptr++;
	}
	return (0);
}
