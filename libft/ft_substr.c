/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:10:40 by zh                #+#    #+#             */
/*   Updated: 2022/12/16 15:57:37 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// s: The string from which to create the substring.
// start: The start index of the substring in the
// string ’s’.
// len: The maximum length of the substring.
// The substring.
// NULL if the allocation fails.
// malloc
// Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			s_len;
	char			*new_str;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		len = 0;
		start = s_len;
	}
	if (s_len - start < len)
		len = s_len - start;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (0);
	ft_memcpy(new_str, s + start, len);
	new_str[len] = '\0';
	return (new_str);
}
