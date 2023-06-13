/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyad <zeyad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:14:05 by zeyad             #+#    #+#             */
/*   Updated: 2023/03/19 15:30:32 by zeyad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"
# include <stdlib.h>

//vars contains all variable used across the program
//to avoid usage of global variables
typedef struct s_vars
{
	void			*mlx;
	void			*win_ptr;
	unsigned int	win_width;
	unsigned int	win_height;
	struct s_image	*buffer;
	struct s_player	*player;
	struct s_map	*map;
}				t_vars;

//t_image struct and create and destroy
typedef struct s_image
{
	void	*img;
	void	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
}				t_image;

t_image		*new_image(t_vars *vars, int width, int height);
void		destroy_image(t_vars *vars, t_image *image);
t_image		*load_image(t_vars *vars, char *filename);
void		draw_image(t_image *buffer, t_image *image,
				unsigned int x, unsigned int y);

//color.c functions
int			create_trgb(unsigned char t, unsigned char r, unsigned char g,
				unsigned char b);
int			get_t(int color);
int			get_r(int color);
int			get_g(int color);
int			get_b(int color);

//put pixel to image, takes care of alpha blending
void		my_pixel_put(t_image *img, int x, int y, int color);
void		gameover(t_vars *vars);

//event_handler.c functions
void		hook_handlers(t_vars *vars);
int			keydown_handler(int keycode, t_vars *vars);
int			keyreleased_handler(int keycode, t_vars *vars);
int			mousepressed_handler(int button, int x, int y, t_vars *vars);

//player stuff
//defines which direction the player is moving
# define DIR_IDLE 0
# define DIR_UP 1
# define DIR_RIGHT 2
# define DIR_DOWN 4
# define DIR_LEFT 8

typedef struct s_player
{
	unsigned int	posx;
	unsigned int	posy;
	t_image			*sprite;
	int				size;
	int				dir;
	int				moves_left;
	unsigned int	picked_up;
}				t_player;

t_player	*new_player(t_vars *vars, int x, int y);
void		destroy_player(t_vars *vars, t_player *player);
void		update_player(t_vars *vars, t_player *player);
void		render_player(t_vars *vars, t_player *player);

//map stuff
# define MAP_WALL '1'
# define MAP_EMPTY '0'
# define MAP_START 'P'
# define MAP_END 'E'
# define MAP_COLLECTABLE 'C'
# define MAP_MAX_ROWS 100
# define TILE_SIZE 128

typedef struct s_map
{
	char				**buffer;
	unsigned int		width;
	unsigned int		height;
	unsigned int		startx;
	unsigned int		starty;
	unsigned int		endx;
	unsigned int		endy;
	unsigned int		collectable_count;
	t_image				*tile_sprites[5];
}				t_map;
t_map		*read_map(t_vars *vars, const char *filename);
void		destroy_map(t_vars *vars, t_map *mp);
void		draw_map(t_vars *vars, t_map *mp);
int			get_min_moves(t_vars *vrs, t_map *mp);

//min_moves related stuff

typedef struct s_city
{
	int	x;
	int	y;
}				t_city;

#endif
