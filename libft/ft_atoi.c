/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zh <zshahin@student.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:37:30 by zh                #+#    #+#             */
/*   Updated: 2022/12/15 14:48:50 by zh               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c);

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == ' '))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
		res = res * 10 + (*nptr++ - '0');
	return ((int)(sign * res));
}
