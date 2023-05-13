/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:37:59 by zh                #+#    #+#             */
/*   Updated: 2022/12/31 12:23:12 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	mutual_exclusion(struct s_placeholder *ph)
{
	if ((ph->flags) & PS_PLUS_FLAG)
		(ph->flags) &= ~PS_SPACE_FLAG;
	if (((ph->precision) >= 0) || ((ph->flags) & PS_MINUS_FLAG))
		(ph->flags) &= ~PS_ZERO_FLAG;
}

int	parse_placeholder(const char *format, struct s_placeholder *placeholder)
{
	int	i;

	i = 0;
	i += parse_flags(format + i, &(placeholder->flags));
	i += parse_width(format + i, &(placeholder->width));
	i += parse_precision(format + i, &(placeholder->precision));
	i += parse_specifier(format + i, &(placeholder->specifier));
	mutual_exclusion(placeholder);
	return (i);
}
