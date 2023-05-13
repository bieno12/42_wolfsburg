/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:49:42 by zh                #+#    #+#             */
/*   Updated: 2022/12/16 16:22:24 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*new_str;

	size = ft_strlen(s);
	new_str = (char *)malloc(size + 1);
	if (!new_str)
		return (0);
	ft_memcpy(new_str, s, size + 1);
	return (new_str);
}
