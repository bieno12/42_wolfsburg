/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:17:27 by zeyad             #+#    #+#             */
/*   Updated: 2023/02/04 14:02:21 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft/libft.h"
# include "unistd.h"
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# define WHICH_FILPATH "/usr/bin/which"	
# define PROMPT "Pipex: "
# define BUF_SIZE 42

char	**get_env(char **ptr);

void	chk(int error, const char *message);

int		close_pipe(int fd[2]);

char	*get_commandpath(char	*file);

int		execute_command(const char *command, int stdin_fd);

void	execute_statement(int argc, char **argv);

#endif
