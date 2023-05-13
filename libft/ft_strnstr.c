/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:58:03 by zh                #+#    #+#             */
/*   Updated: 2022/12/16 15:55:29 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < n && haystack[i] != '\0')
	{
		if (i + len > n)
			break ;
		if (ft_strncmp(haystack + i, needle, len) == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
