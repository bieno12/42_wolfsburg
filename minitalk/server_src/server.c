/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:43:15 by zeyad             #+#    #+#             */
/*   Updated: 2023/01/31 18:49:10 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	assign_handler(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int		i;
	static char		c;

	if (sig == SIGUSR1)
	{
		c |= (1 << (7 - i));
	}
	else
	{
		c &= ~(1 << (7 - i));
	}
	i++;
	if (i == 8)
	{
		ft_putchar_fd(c, 1);
		i = 0;
	}	
	send_ack(info->si_pid, SIGUSR1);
}

void	send_ack(int pid, int sig)
{
	kill(pid, sig);
}
