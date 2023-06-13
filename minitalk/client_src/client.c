/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:50:19 by zeyad             #+#    #+#             */
/*   Updated: 2023/01/31 15:57:56 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_ackflag;

void	send_message(int pid, char *message)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = ft_strlen(message);
	while (i < len)
	{
		j = 0;
		while (j < 8)
		{
			g_ackflag = 1;
			if (message[i] & (1 << (7 - j)))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_ackflag)
				;
			j++;
		}
		i++;
	}
}

void	assign_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_ack;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
}

void	handle_ack(int sig)
{
	g_ackflag = 0;
}
