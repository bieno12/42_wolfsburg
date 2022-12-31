/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:49:34 by zh                #+#    #+#             */
/*   Updated: 2022/12/16 16:23:45 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;

	if (nmemb != (nmemb * size) / size)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
