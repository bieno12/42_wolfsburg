/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:45:29 by zeyad             #+#    #+#             */
/*   Updated: 2023/02/04 12:21:39 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	command_was_not_found(int status, const char *command);

static char	**intialize_args(char *command)
{
	char	**args;

	args = (char **)malloc(3 * sizeof(char *));
	args[0] = "which";
	args[1] = command;
	args[2] = NULL;
	return (args);
}

char	*get_commandpath(char	*command)
{
	int		fd[2];
	char	**args;
	char	*path;
	char	*temp;
	int		id;

	args = intialize_args(command);
	chk(pipe(fd), "Pipe Error");
	id = fork();
	chk(id, "Fork Error");
	if (id == 0)
	{
		chk(dup2(fd[1], STDOUT_FILENO), "Output Redirect Error");
		close_pipe(fd);
		chk(execve(WHICH_FILPATH, args, get_env(NULL)), WHICH_FILPATH);
	}
	chk(waitpid(id, &id, 0), "Wait Error");
	command_was_not_found(id, command);
	temp = get_next_line(fd[0]);
	path = ft_strtrim(temp, "\n");
	free(temp);
	free(args);
	close_pipe(fd);
	return (path);
}
