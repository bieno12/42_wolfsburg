/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:53:41 by zh                #+#    #+#             */
/*   Updated: 2022/12/16 15:52:42 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*ptr;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = malloc(l1 + l2 + 1);
	if (!ptr)
		return (0);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1, l1);
	ft_memcpy(ptr + l1, s2, l2);
	ptr[l1 + l2] = '\0';
	return (ptr);
}
