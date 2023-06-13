/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:55:46 by zeyad             #+#    #+#             */
/*   Updated: 2023/01/31 15:56:27 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include "../libft/libft.h"
# include <stdlib.h>
# include "signal.h"
# include "unistd.h"

void	assign_handler(void);

void	handle_ack(int sig);

void	send_message(int pid, char *message);
#endif