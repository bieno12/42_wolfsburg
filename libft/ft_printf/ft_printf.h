/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 11:31:24 by zh                #+#    #+#             */
/*   Updated: 2022/12/27 11:47:21 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include "parser/parser_consts.h"

# include <stdarg.h>
# define STDOUT 1

struct s_placeholder
{
	int	flags;
	int	width;
	int	precision;
	int	specifier;
};

#endif
