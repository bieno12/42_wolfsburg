/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:46:11 by zh                #+#    #+#             */
/*   Updated: 2022/12/16 15:53:13 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	j = 0;
	i = 0;
	while (i < size && dst[i])
		i++;
	len = i;
	while (size && (i < size - 1) && (src[j] != '\0'))
		dst[i++] = src[j++];
	if (i > len)
		dst[i] = '\0';
	while (src[j])
		j++;
	return (len + j);
}
