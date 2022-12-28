/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:01:05 by zh                #+#    #+#             */
/*   Updated: 2022/12/16 16:23:29 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	len;
	size_t	left;
	size_t	right;

	left = 0;
	right = ft_strlen(s1);
	while ((s1[left]) && (ft_strchr(set, s1[left])))
		left++;
	while (right && left < right - 1 && ft_strchr(set, s1[right - 1]))
		right--;
	len = right - left;
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1 + left, len);
	ptr[len] = '\0';
	return (ptr);
}
