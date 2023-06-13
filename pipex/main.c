/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:14:22 by zeyad             #+#    #+#             */
/*   Updated: 2023/02/04 14:02:35 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argc < 3)
	{
		write(2, "invalid number of args\n", 23);
		exit(1);
	}
	get_env(env);
	execute_statement(argc, argv);
}
