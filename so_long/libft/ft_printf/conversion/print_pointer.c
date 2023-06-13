/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:04:17 by zeyad             #+#    #+#             */
/*   Updated: 2022/12/31 12:13:01 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

int	print_pointer(struct s_placeholder ph, void *ptr)
{
	ph.flags |= PS_HASH_FLAG;
	return (print_hexa(ph, 0, (unsigned long)ptr));
}
