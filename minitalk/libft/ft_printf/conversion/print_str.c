/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:09:19 by zeyad             #+#    #+#             */
/*   Updated: 2022/12/27 16:23:48 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"
//null case
//precision cap
//width justification
int	print_str(struct s_placeholder ph,	char *str)
{
	int		written;
	char	*output;

	if (!str)
		str = "(null)";
	output = ft_strdup(str);
	if (ph.precision >= 0)
		output[ft_min(ft_strlen(str), ph.precision)] = 0;
	written = width_justify(ph, output);
	free(output);
	return (written);
}
