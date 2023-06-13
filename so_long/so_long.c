/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:02:53 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/18 18:01:45 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_pixel_put(t_image *img, int x, int y, int color)
{
	char			*dst;
	unsigned int	*dest_color;
	unsigned char	a;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + y * (img->line_size) + x * (img->bpp >> 3);
	dest_color = (unsigned int *)dst;
	a = 255 - get_t(color);
	*dest_color = create_trgb(0,
			(a * get_r(color) + (255 - a) * get_r(*dest_color)) >> 8,
			(a * get_g(color) + (255 - a) * get_g(*dest_color)) >> 8,
			(a * get_b(color) + (255 - a) * get_b(*dest_color)) >> 8);
}

void	gameover(t_vars *vars)
{
	if (vars->player->picked_up == vars->map->collectable_count
		&& vars->player->posy == vars->map->endy
		&& vars->player->posx == vars->map->endx)
	{
		ft_printf("You have won!\n");
		mlx_loop_end(vars->mlx);
	}
	else if (vars->player->moves_left == 0)
	{
		ft_printf("you have lost!\n");
		mlx_loop_end(vars->mlx);
	}
}
