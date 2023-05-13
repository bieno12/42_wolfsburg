/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:51:48 by zh                #+#    #+#             */
/*   Updated: 2022/12/25 17:45:42 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_width(const char *format, int *width)
{
	int	i;

	*width = 0;
	i = 0;
	if (ft_isdigit(*format))
		*width = ft_atoi(format);
	else
		*width = 0;
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}
