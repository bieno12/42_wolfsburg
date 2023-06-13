/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:55:40 by zeyad             #+#    #+#             */
/*   Updated: 2023/01/31 15:58:17 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "utils/validation.h"

int	main(int argn, char **argv)
{
	assign_handler();
	if (validate_args(argn, argv))
		exit(1);
	send_message(ft_atoi(argv[1]), argv[2]);
}
