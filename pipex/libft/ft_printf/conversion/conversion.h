/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:59:53 by zeyad             #+#    #+#             */
/*   Updated: 2022/12/27 16:22:15 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

# include "../ft_printf.h"
# include "../parser/parser_consts.h"

//string manipulation
int	width_justify(struct s_placeholder ph, char *str);

int	convert_placeholder(struct s_placeholder ph, va_list args);

int	print_char(struct s_placeholder ph, int c);

int	print_str(struct s_placeholder ph,	char *str);

int	print_hexa(struct s_placeholder ph, int upper, unsigned long num);

int	print_pointer(struct s_placeholder ph, void *p);

int	print_unsigned(struct s_placeholder ph, unsigned int num);

int	print_decimal(struct s_placeholder ph, long num);

int	print_percent(struct s_placeholder ph);

#endif