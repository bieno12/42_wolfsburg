/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:35:36 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/18 19:13:44 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*new_image(t_vars *vars, int width, int height)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img = mlx_new_image(vars->mlx, width, height);
	image->width = width;
	image->height = height;
	image->addr = mlx_get_data_addr(image->img, &(image->bpp),
			&(image->line_size), &(image->endian));
	return (image);
}

void	destroy_image(t_vars *vars, t_image *image)
{
	mlx_destroy_image(vars->mlx, image->img);
	free(image);
}

t_image	*load_image(t_vars *vars, char *filename)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	image->img = mlx_xpm_file_to_image(vars->mlx, filename,
			&(image->width), &(image->height));
	image->addr = mlx_get_data_addr(image->img, &(image->bpp),
			&(image->line_size), &(image->endian));
	return (image);
}

void	draw_image(t_image *buffer, t_image *image,
		unsigned int x, unsigned int y)
{
	int	px;
	int	py;
	int	color;

	py = -1;
	while (++py < image->height)
	{
		px = -1;
		while (++px < image->width)
		{
			color = *((int *)(image->addr
						+ py * image->line_size + px * image->bpp / 8));
			my_pixel_put(buffer, px + x, py + y, color);
		}
	}
}
