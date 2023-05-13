/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:28:43 by zeyad             #+#    #+#             */
/*   Updated: 2022/12/31 12:34:49 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

static char	*create_suffix(struct s_placeholder ph, int up, unsigned long n);

static char	*create_nzeros(struct s_placeholder ph, int l_suffix, int l_utoa);

//either upper or lower
//rule for hexa number = suffix + n_zeros + utoa;
//	lengh of n_zeros are calculated
//		if zero_flag: n_zeros = max(0, width - len(suffix) - len(utoa))
//		if precision: n_zeros = max(0, precision - len(utoa))  
//rule for suffix
//	suffix = "[\s|\+]?[(0x)|(0X)]?"
int	print_hexa(struct s_placeholder ph, int upper, unsigned long num)
{
	char	*utoa;
	char	*suffix;
	char	*zeros;
	char	*output;
	int		written;

	if (!upper)
		utoa = ft_utoa_radix(num, "0123456789abcdef");
	else
		utoa = ft_utoa_radix(num, "0123456789ABCDEF");
	suffix = create_suffix(ph, upper, num);
	zeros = create_nzeros(ph, ft_strlen(suffix), ft_strlen(utoa));
	output = ft_concat(3, suffix, zeros, utoa);
	written = width_justify(ph, output);
	free(suffix);
	free(zeros);
	free(utoa);
	free(output);
	return (written);
}

//space and plus can't be together
//	suffix = "[\s|\+]?[(0x)|(0X)]?"
static char	*create_suffix(struct s_placeholder ph, int upper, unsigned long n)
{
	int		size;
	char	suffix[4];

	if (!n && (ph.specifier != 'p'))
		return (ft_strdup(""));
	size = 0;
	if (ph.flags & PS_PLUS_FLAG)
		suffix[size++] = '+';
	else if (ph.flags & PS_SPACE_FLAG)
		suffix[size++] = ' ';
	if (ph.flags & PS_HASH_FLAG)
	{
		suffix[size++] = '0';
		if (upper)
			suffix[size++] = 'X';
		else
			suffix[size++] = 'x';
	}
	suffix[size] = 0;
	return (ft_strdup(suffix));
}

//if zero_flag: n_zeros = max(0, width - len(suffix) - len(utoa))
//if precision: n_zeros = max(0, precision - len(utoa))  
static char	*create_nzeros(struct s_placeholder ph, int l_suffix, int l_utoa)
{
	int		n;
	char	*zeros;

	if (ph.flags & PS_ZERO_FLAG)
		n = ft_max(0, ph.width - l_suffix - l_utoa);
	else
		n = ft_max(0, ph.precision - l_utoa);
	zeros = malloc(n + 1);
	ft_memset(zeros, '0', n);
	zeros[n] = 0;
	return (zeros);
}
