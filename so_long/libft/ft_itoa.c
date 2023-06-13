/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:38:05 by zh                #+#    #+#             */
/*   Updated: 2023/03/19 13:31:08 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reverse_str(char *s, size_t start, size_t end)
{
	char	temp;

	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}

char	*ft_itoa(int n)
{
	char			digits[20];
	long int		num;
	size_t			i;

	ft_memset(digits, 0, 20);
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	if (num < 0)
	{
		num *= -1;
		digits[i++] = '-';
	}
	while (num)
	{
		digits[i++] = (num % 10) + '0';
		num /= 10;
	}
	ft_reverse_str(digits, !!(*digits == '-'), i - 1);
	return (ft_strdup(digits));
}
