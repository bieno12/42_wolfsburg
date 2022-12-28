/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:54:19 by zh                #+#    #+#             */
/*   Updated: 2022/12/25 17:46:38 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_specifier(const char *format, int *specifier)
{
	const char	*specifiers;

	specifiers = "cspdiuxX%";
	*specifier = 0;
	while (*specifiers)
	{
		if (*specifiers == *format)
		{
			*specifier = *specifiers;
			break ;
		}
		specifiers++;
	}
	return (*specifier != 0);
}
