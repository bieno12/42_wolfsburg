/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:21:19 by zeyad             #+#    #+#             */
/*   Updated: 2022/12/27 16:21:27 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

int	print_percent(struct s_placeholder ph)
{
	ft_putchar_fd('%', STDOUT);
	return (ph.specifier == '%');
}
