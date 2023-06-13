/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:51:15 by zh                #+#    #+#             */
/*   Updated: 2022/12/23 16:25:44 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_flags(const char *format, int *flags)
{
	int	i;

	*flags = 0;
	i = 0;
	while (*format)
	{
		if (*format == '-')
			*flags |= PS_MINUS_FLAG;
		else if (*format == '0')
			*flags |= PS_ZERO_FLAG;
		else if (*format == '#')
			*flags |= PS_HASH_FLAG;
		else if (*format == ' ')
			*flags |= PS_SPACE_FLAG;
		else if (*format == '+')
			*flags |= PS_PLUS_FLAG;
		else
			break ;
		format++;
		i++;
	}
	return (i);
}
