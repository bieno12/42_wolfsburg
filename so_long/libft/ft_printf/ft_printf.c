/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:31:20 by zh                #+#    #+#             */
/*   Updated: 2022/12/29 22:34:06 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parser/parser.h"
#include "conversion/conversion.h"

static int	print_conversion(struct s_placeholder ph, va_list args)
{
	int		written;

	written = convert_placeholder(ph, args);
	return (written);
}

static int	handle_conversion(const char **format, int *written, va_list args)
{
	struct s_placeholder	ph;
	int						n;

	(*format)++;
	n = parse_placeholder(*format, &ph);
	if (n <= 0)
		*written = -1;
	else
	{
		(*format) += n - 1;
		n = print_conversion(ph, args);
		if ((*written) >= 0)
				(*written) += n;
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list					args;
	int						written;

	written = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			handle_conversion(&format, &written, args);
		}
		else
		{
			ft_putchar_fd(*format, STDOUT);
			written++;
		}
		format++;
	}
	va_end(args);
	return (written);
}
