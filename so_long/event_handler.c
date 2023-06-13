/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:48:40 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/18 19:12:11 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "X11/keysym.h"
#include "X11/X.h"

void	hook_handlers(t_vars *vars)
{
	mlx_do_key_autorepeatoff(vars->mlx);
	mlx_hook(vars->win_ptr, KeyPress, KeyPressMask, keydown_handler, vars);
	mlx_hook(vars->win_ptr, DestroyNotify, 0, mlx_loop_end, vars->mlx);
}

int	keydown_handler(int keycode, t_vars *vars)
{
	if (keycode == XK_w || keycode == XK_W)
		vars->player->dir = DIR_UP;
	else if (keycode == XK_d || keycode == XK_D)
		vars->player->dir = DIR_RIGHT;
	else if (keycode == XK_s || keycode == XK_S)
		vars->player->dir = DIR_DOWN;
	else if (keycode == XK_a || keycode == XK_A)
		vars->player->dir = DIR_LEFT;
	else if (keycode == XK_Escape)
		mlx_loop_end(vars->mlx);
	return (1);
}
