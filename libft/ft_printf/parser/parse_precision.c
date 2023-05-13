/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:52:19 by zh                #+#    #+#             */
/*   Updated: 2022/12/23 22:41:07 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_precision(const char *format, int *precision)
{
	int	i;

	i = 0;
	*precision = 0;
	if (format[i] == '.')
	{
		i++;
		if (ft_isdigit(format[i]))
			*precision = ft_atoi(format + i);
		while (ft_isdigit(format[i]))
			i++;
	}
	else
		*precision = -1;
	return (i);
}
