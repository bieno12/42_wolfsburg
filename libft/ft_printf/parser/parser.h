/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:39:08 by zh                #+#    #+#             */
/*   Updated: 2022/12/25 17:47:10 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../ft_printf.h"

# include "parser_consts.h"

int	parse_placeholder(const char *format, struct s_placeholder *ph);

int	parse_flags(const char *format, int *flags);

int	parse_precision(const char *format, int *precision);

int	parse_width(const char *format, int *width);

int	arse_length(const char *format, int *length);

int	parse_specifier(const char *format, int *specifier);

#endif