/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:09:52 by zh                #+#    #+#             */
/*   Updated: 2022/12/15 10:59:24 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = 0;
	while (*s)
	{
		if (*s == (char)c)
			ptr = s;
		s++;
	}
	if (!c)
		return ((char *)s);
	return ((char *)ptr);
}
