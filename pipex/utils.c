/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 13:18:00 by zeyad             #+#    #+#             */
/*   Updated: 2023/02/04 14:06:27 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pipex.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	command_was_not_found(int status, const char *command)
{
	if (status)
	{
		write(2, PROMPT, ft_strlen(PROMPT));
		write(2, command, ft_strlen(command));
		write(2, ": command was not found.\n", 25);
		exit(1);
	}
}

int	close_pipe(int fd[2])
{
	int	error;

	error = ft_min(close(fd[0]), close(fd[1]));
	return (error);
}

char	**get_env(char **ptr)
{
	static char	**env;

	if (ptr)
		env = ptr;
	return (env);
}

void	chk(int error, const char *message)
{
	char	*prompt;

	prompt = ft_concat(2, "Pipex: ", message);
	if (error < 0)
	{
		perror(prompt);
		exit(1);
	}
	free(prompt);
}
