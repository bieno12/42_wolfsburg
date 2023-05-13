/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:24:36 by zh                #+#    #+#             */
/*   Updated: 2022/12/16 15:46:08 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;

	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	if (dest > src)
		while (n--)
			dest_char[n] = src_char[n];
	else
		while (n--)
			*dest_char++ = *src_char++;
	return (dest);
}
