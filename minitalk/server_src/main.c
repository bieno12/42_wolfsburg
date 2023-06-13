/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:49:37 by zeyad             #+#    #+#             */
/*   Updated: 2023/01/31 16:01:30 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	assign_handler();
	ft_printf("pid: %10d\n", getpid());
	while (1)
	{
		pause();
	}
}