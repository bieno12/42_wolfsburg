/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:15:00 by zeyad             #+#    #+#             */
/*   Updated: 2022/12/27 14:01:37 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(unsigned long int num, int base)
{
	int	length;

	if (!num)
		return (1);
	length = 0;
	while (num)
	{
		length++;
		num /= base;
	}
	return (length);
}

char	*ft_utoa_radix(unsigned long int num, char *radix)
{
	int		base;
	int		length;
	char	*numstr;

	base = ft_strlen(radix);
	length = numlen(num, base);
	numstr = malloc(length + 1);
	numstr[length] = 0;
	if (!num)
		numstr[0] = radix[0];
	while (num)
	{
		numstr[(length--) - 1] = radix[num % base];
		num /= base;
	}
	return (numstr);
}
