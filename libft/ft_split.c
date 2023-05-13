/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:22:22 by zh                #+#    #+#             */
/*   Updated: 2022/12/16 15:50:30 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
			flag = 1;
		else
		{
			count += flag;
			flag = 0;
		}
		s++;
	}
	count += flag;
	return (count);
}
//allocate mem

char	**ft_split(char const *s, char c)
{
	size_t	length;
	size_t	i;
	char	**words;

	words = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		length = 0;
		while (s[length] && s[length] != c)
			length++;
		words[i] = ft_substr(s, 0, length);
		if (!words[i++])
			return (0);
		s += length;
	}
	words[i] = 0;
	return (words);
}
