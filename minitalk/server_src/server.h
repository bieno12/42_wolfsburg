/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:00:46 by zeyad             #+#    #+#             */
/*   Updated: 2023/01/31 16:00:50 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "../libft/libft.h"
# include <stdlib.h>
# include "signal.h"
# include "unistd.h"

void	assign_handler(void);

void	handle_signal(int sig, siginfo_t *info, void *context);

void	send_ack(int pid, int sig);
#endif
