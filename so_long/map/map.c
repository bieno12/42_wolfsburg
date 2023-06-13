/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:21:42 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/23 17:38:58 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_file(const char *filename);

int		validate_startend(t_map	*mp);

int		validate_dimensions(t_map *mp);

int		validate_borders(t_map *mp);

int		count_collectables(t_map *mp);

int		get_sprite_index(t_map *mp, int x, int y);

void	handle_unknownchar(t_map *mp);

void	load_map_tiles(t_vars *vars, t_map *mp)
{
	mp->tile_sprites[0] = load_image(vars, "./assets/sprites/wall.xpm");
	mp->tile_sprites[1] = load_image(vars, "./assets/sprites/ground.xpm");
	mp->tile_sprites[2] = load_image(vars, "./assets/sprites/collectable.xpm");
	mp->tile_sprites[3] = load_image(vars, "./assets/sprites/end.xpm");
}

t_map	*read_map(t_vars *vars, const char *filename)
{
	t_map	*mp;

	mp = malloc(sizeof (t_map));
	mp->buffer = read_file(filename);
	load_map_tiles(vars, mp);
	if (validate_dimensions(mp))
	{
		ft_putstr_fd("Error\nInvalid dimensions\n", 2);
		exit(2);
	}
	mp->collectable_count = count_collectables(mp);
	if (validate_borders(mp))
	{
		ft_putstr_fd("Error\nInvalid borders\n", 2);
		exit(2);
	}
	if (validate_startend(mp))
	{
		ft_putstr_fd("Error\nInvalid start or end\n", 2);
		exit(2);
	}
	handle_unknownchar(mp);
	return (mp);
}

void	destroy_map(t_vars *vars, t_map *mp)
{
	char	**buf;	

	buf = mp->buffer;
	while (*buf)
		free(*(buf++));
	free(mp->buffer);
	destroy_image(vars, mp->tile_sprites[0]);
	destroy_image(vars, mp->tile_sprites[1]);
	destroy_image(vars, mp->tile_sprites[2]);
	destroy_image(vars, mp->tile_sprites[3]);
	free(mp);
}

void	draw_map(t_vars *vars, t_map *mp)
{
	unsigned int	x;
	unsigned int	y;
	int				index;

	y = -1;
	while (++y < mp->height)
	{
		x = -1;
		while (++x < mp->width)
		{
			index = get_sprite_index(mp, x, y);
			draw_image(vars->buffer, mp->tile_sprites[index],
				x * TILE_SIZE, y * TILE_SIZE);
			if (mp->buffer[y][x] == MAP_COLLECTABLE)
				draw_image(vars->buffer, mp->tile_sprites[2],
					x * TILE_SIZE, y * TILE_SIZE);
		}
	}
}

int	count_collectables(t_map *mp)
{
	unsigned int	i;
	unsigned int	j;
	int				count;

	count = 0;
	i = -1;
	while (++i < mp->height)
	{
		j = -1;
		while (++j < mp->width)
			count += (mp->buffer[i][j] == MAP_COLLECTABLE);
	}
	return (count);
}
