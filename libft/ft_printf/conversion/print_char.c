/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:47:37 by zeyad             #+#    #+#             */
/*   Updated: 2022/12/27 12:06:46 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

int	print_char(struct s_placeholder ph, int c)
{
	int	written;

	if (ph.flags & PS_MINUS_FLAG)
	{
		ft_putchar_fd(c, STDOUT);
		ft_putcharn_fd(' ', ft_max(0, ph.width - 1), STDOUT);
	}
	else
	{
		ft_putcharn_fd(' ', ft_max(0, ph.width - 1), STDOUT);
		ft_putchar_fd(c, STDOUT);
	}
	written = ft_max(0, ph.width - 1) + 1;
	return (written);
}
