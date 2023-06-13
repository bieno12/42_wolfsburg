/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:59:12 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/19 15:29:11 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*new_player(t_vars *vars, int x, int y)
{
	t_player	*p;

	p = malloc(sizeof(*p));
	p->dir = 0;
	p->posx = x;
	p->posy = y;
	p->sprite = load_image(vars, "assets/sprites/player.xpm");
	p->size = p->sprite->width;
	p->picked_up = 0;
	return (p);
}

void	destroy_player(t_vars *vars, t_player *player)
{
	destroy_image(vars, player->sprite);
	free(player);
}

static int	update_movement(t_vars *vars, t_player *player)
{
	int	offx;
	int	offy;

	offx = 0;
	offy = 0;
	if (player->dir == DIR_UP
		&& vars->map->buffer[player->posy - 1][player->posx] != MAP_WALL)
		offy = -1;
	else if (player->dir == DIR_RIGHT
		&& vars->map->buffer[player->posy][player->posx + 1] != MAP_WALL)
		offx = 1;
	else if (player->dir == DIR_DOWN
		&& vars->map->buffer[player->posy + 1][player->posx] != MAP_WALL)
		offy = 1;
	else if (player->dir == DIR_LEFT
		&& vars->map->buffer[player->posy][player->posx - 1] != MAP_WALL)
		offx = -1;
	player->posx += offx;
	player->posy += offy;
	return (offx || offy);
}

void	update_player(t_vars *vars, t_player *player)
{
	if (update_movement(vars, player))
	{
		player->moves_left--;
		ft_printf("moves left : %d\n", player->moves_left);
	}
	if (vars->map->buffer[player->posy][player->posx] == MAP_COLLECTABLE)
	{
		player->picked_up++;
		vars->map->buffer[player->posy][player->posx] = MAP_EMPTY;
	}
	player->dir = 0;
}

void	render_player(t_vars *vars, t_player *player)
{
	unsigned int	x;
	unsigned int	y;

	x = player->posx * TILE_SIZE + TILE_SIZE / 2 - player->size / 2;
	y = player->posy * TILE_SIZE + TILE_SIZE / 2 - player->size / 2;
	draw_image(vars->buffer, player->sprite, x, y);
}
