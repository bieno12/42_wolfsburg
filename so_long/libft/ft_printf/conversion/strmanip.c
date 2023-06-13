/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmanip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:13:09 by zeyad             #+#    #+#             */
/*   Updated: 2022/12/27 16:21:18 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

int	width_justify(struct s_placeholder ph, char *str)
{
	int	size;

	size = ft_strlen(str);
	if (ph.flags & PS_MINUS_FLAG)
	{
		ft_putstr_fd(str, STDOUT);
		ft_putcharn_fd(' ', ft_max(0, ph.width - size), STDOUT);
	}
	else
	{
		ft_putcharn_fd(' ', ft_max(0, ph.width - size), STDOUT);
		ft_putstr_fd(str, STDOUT);
	}
	return (size + ft_max(0, ph.width - size));
}
