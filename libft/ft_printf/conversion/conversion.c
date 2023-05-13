/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:01:56 by zeyad             #+#    #+#             */
/*   Updated: 2022/12/27 16:21:44 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

int	convert_placeholder(struct s_placeholder ph, va_list args)
{
	if (ph.specifier == 'c')
		return (print_char(ph, va_arg(args, int)));
	if (ph.specifier == 's')
		return (print_str(ph, va_arg(args, char *)));
	if (ph.specifier == 'x')
		return (print_hexa(ph, 0, va_arg(args, unsigned int)));
	if (ph.specifier == 'X')
		return (print_hexa(ph, 1, va_arg(args, unsigned int)));
	if (ph.specifier == 'p')
		return (print_pointer(ph, va_arg(args, void *)));
	if (ph.specifier == 'u')
		return (print_unsigned(ph, va_arg(args, unsigned int)));
	if (ph.specifier == 'd' || ph.specifier == 'i')
		return (print_decimal(ph, va_arg(args, int)));
	if (ph.specifier == '%')
		return (print_percent(ph));
	return (0);
}
