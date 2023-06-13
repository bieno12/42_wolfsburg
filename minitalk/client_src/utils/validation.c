/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:36:01 by zeyad             #+#    #+#             */
/*   Updated: 2023/01/31 15:59:05 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

int	validate_args(int argn, char **argv)
{
	if (argn != 3)
	{
		ft_printf("invalid number of arguments\n");
		return (1);
	}
	if (!is_valid_int(argv[1]))
	{
		ft_printf("invalid process id\n");
		return (1);
	}
	return (0);
}

int	is_valid_int(char *str)
{
	int	len;
	int	i;

	if (*str && (str[0] == '-' || str[0] == '+'))
		str++;
	len = ft_strlen(str);
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (len == i);
}
