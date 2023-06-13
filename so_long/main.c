/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:13:11 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/20 15:46:24 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		update(t_vars *vars);

void	init(t_vars *vars, char **argv);

void	clean_up(t_vars *vars);

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		ft_putstr_fd("invalid number of args\n", 2);
		exit(2);
	}
	init(&vars, argv);
	mlx_loop(vars.mlx);
	clean_up(&vars);
}

int	update(t_vars *vars)
{
	update_player(vars, vars->player);
	draw_map(vars, vars->map);
	render_player(vars, vars->player);
	mlx_put_image_to_window(vars->mlx, vars->win_ptr, vars->buffer->img, 0, 0);
	gameover(vars);
	return (1);
}

void	init(t_vars *vars, char **argv)
{
	vars->mlx = mlx_init();
	vars->map = read_map(vars, argv[1]);
	vars->win_width = vars->map->width * TILE_SIZE;
	vars->win_height = vars->map->height * TILE_SIZE;
	ft_printf("map read successfully!\n");
	vars->win_ptr = mlx_new_window(vars->mlx, vars->win_width,
			vars->win_height, "So Long");
	vars->buffer = new_image(vars, vars->win_width, vars->win_height);
	vars->player = new_player(vars, vars->map->startx, vars->map->starty);
	vars->player->moves_left = get_min_moves(vars, vars->map);
	if (vars->player->moves_left >= 0x7fffffff - 1)
	{
		ft_putstr_fd("Error\nmap is unsolvable\n", 2);
		exit(2);
	}
	ft_printf("min moves: %d\n", vars->player->moves_left);
	mlx_loop_hook(vars->mlx, update, vars);
	hook_handlers(vars);
}

void	clean_up(t_vars *vars)
{
	mlx_do_key_autorepeaton(vars->mlx);
	destroy_player(vars, vars->player);
	destroy_image(vars, vars->buffer);
	destroy_map(vars, vars->map);
	mlx_destroy_window(vars->mlx, vars->win_ptr);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}
