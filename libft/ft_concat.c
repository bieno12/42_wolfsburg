/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:23:45 by zeyad             #+#    #+#             */
/*   Updated: 2022/12/27 13:53:12 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#define MAX_BUFFERS 10
//takes n strings and concatinate them into one str

static char	*add_bufs(char *dest, char **bufs, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < n)
	{
		while (*bufs[j])
		{
			dest[i++] = (*bufs[j]);
			(bufs[j])++;
		}
		j++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_concat(int n, ...)
{
	char	*bufs[MAX_BUFFERS];
	va_list	args;
	char	*result;
	int		size;
	int		i;

	va_start(args, n);
	i = 0;
	size = 0;
	while (i < n)
	{
		bufs[i] = va_arg(args, char *);
		size += ft_strlen(bufs[i]);
		i++;
	}
	result = add_bufs(malloc(size + 1), bufs, n);
	result[size] = 0;
	return (result);
}
