/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:18:00 by zeyad             #+#    #+#             */
/*   Updated: 2023/02/04 14:16:42 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_args(char **args);

//takes in file to act as input. returns fd for output file
int	execute_command(const char *command, int stdin_fd)
{
	char	**args;
	char	*command_path;
	int		p[2];
	int		pid;

	chk(pipe(p), "Pipe Error");
	args = ft_split(command, ' ');
	command_path = get_commandpath(args[0]);
	pid = fork();
	chk(pid, "Fork Error");
	if (pid == 0)
	{
		chk(dup2(stdin_fd, STDIN_FILENO), "Input Redirect Error");
		chk(dup2(p[1], STDOUT_FILENO), "Output Redirect Error");
		close_pipe(p);
		chk(execve(command_path, args, get_env(NULL)), command);
	}
	waitpid(pid, NULL, 0);
	free(command_path);
	free_args(args);
	close(p[1]);
	return (p[0]);
}

static int	here_doc(char *limiter)
{
	int		fd[2];
	char	*str;

	chk(pipe(fd), "Pipe Error");
	str = get_next_line(0);
	while (str)
	{
		if (!ft_strncmp(limiter, str,
				ft_min(ft_strlen(limiter), ft_strlen(str))))
		{
			free(str);
			break ;
		}
		write(fd[1], str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
	}
	close(fd[1]);
	return (fd[0]);
}

static int	get_input_fd(char **argv, int *hd_flag)
{
	int	fd;

	if (!ft_strncmp(argv[1], "here_doc", ft_min(ft_strlen(argv[1]), 8)))
	{
		fd = here_doc(argv[2]);
		*hd_flag = 1;
	}
	else
	{
		*hd_flag = 0;
		fd = open(argv[1], O_RDONLY);
		chk(fd, argv[1]);
	}
	return (fd);
}

void	execute_statement(int argc, char **argv)
{
	int		fd;
	int		temp;
	int		i;
	int		hd_flag;
	char	*buf[BUF_SIZE];

	fd = get_input_fd(argv, &hd_flag);
	i = 2 + hd_flag;
	while (i < argc - 1)
	{
		temp = execute_command(argv[i++], fd);
		close(fd);
		fd = temp;
	}
	temp = open(argv[argc - 1], O_WRONLY | O_CREAT
			| (O_APPEND * hd_flag) | O_TRUNC, 0666);
	chk(temp, argv[argc - 1]);
	i = read(fd, buf, BUF_SIZE);
	while (i > 0)
	{
		write(temp, buf, i);
		i = read(fd, buf, BUF_SIZE);
	}
	close(fd);
	close(temp);
}
