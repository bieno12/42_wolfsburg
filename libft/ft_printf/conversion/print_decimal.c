/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:26:37 by zeyad             #+#    #+#             */
/*   Updated: 2022/12/27 16:23:33 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

static char	*create_nzeros(struct s_placeholder ph, int l_suffix, int l_utoa);

static char	*create_suffix(struct s_placeholder ph, long num);

//rule for number = suffix + n_zeros + utoa;
//	lengh of n_zeros are calculated
//		if zero_flag: n_zeros = max(0, width - len(suffix) - len(utoa))
//		if precision: n_zeros = max(0, precision - len(utoa))  
//rule for suffix
//	suffix = "[\s|+|-]?"
int	print_decimal(struct s_placeholder ph, long num)
{
	char	*utoa;
	char	*suffix;
	char	*zeros;
	char	*output;
	int		written;

	if (num < 0)
		utoa = ft_utoa_radix(num * -1, "0123456789");
	else
		utoa = ft_utoa_radix(num, "0123456789");
	suffix = create_suffix(ph, num);
	zeros = create_nzeros(ph, ft_strlen(suffix), ft_strlen(utoa));
	output = ft_concat(3, suffix, zeros, utoa);
	written = width_justify(ph, output);
	free(suffix);
	free(zeros);
	free(utoa);
	free(output);
	return (written);
}

static char	*create_suffix(struct s_placeholder ph, long num)
{
	int		size;
	char	suffix[4];

	size = 0;
	if (num < 0)
		suffix[size++] = '-';
	if ((ph.flags & PS_PLUS_FLAG) && num >= 0)
		suffix[size++] = '+';
	else if ((ph.flags & PS_SPACE_FLAG) && num >= 0)
		suffix[size++] = ' ';
	suffix[size] = 0;
	return (ft_strdup(suffix));
}

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
