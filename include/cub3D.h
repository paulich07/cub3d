/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:28:01 by plichota          #+#    #+#             */
/*   Updated: 2025/11/05 21:54:32 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef TILE
#  define TILE 64
# endif

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdio.h>

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600


typedef struct s_img
{
	char	*addr;
	void	*img;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		*win_img;
	int			map_height;
	int			map_width;
	double		pos_x;
	double		pos_y;
	int			dir_x;
	int			dir_y;
	char		**map;
	int			rgb_floor;
	int			rgb_ceiling;
	int			floor_set;
	int			ceiling_set;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
}	t_window;

// Filename parsing
int		is_valid_filename(char *filename);
int		is_directory(char *filename);
int		is_valid_file(char *filename);

// Parsing
int		parse_rgb(char *line);
char	*extract_path(char *line);
int		parse_paths(t_window *win, char *filename);

// Textures
int		check_texture(char *name, char *path);

// Map (allocation)
int		is_valid_map_size(t_window *win);
int		allocate_map_from_file(t_window *win, int fd);
void	count_map_size(t_window *win, char *filename);
void	check_and_allocate_map(t_window *win, char *filename);

// Map utils (allocation)
void	print_map(t_window *win);
int		is_map_line(char *line);

// Map parsing/validation
void	parse_map(t_window *win);
// int		check_wall(t_window *config);
// int		sign(t_window *config);

// Player parsing
int		find_player(t_window *config);

// Player utils
int		move_player(t_window *win, double x, double y);
int		set_player_position(t_window *win, double y, double x);
int		set_player_direction(t_window *win, char c);

// Window
int		init_win_img(t_window *win);
int		init_window(t_window *win);
int		close_window(t_window *win);

// Program utils
void	exit_program(t_window *win, char *s, int error);

// Ray casting
int		raycasting(t_window *win);

// Engine
int		engine(t_window *win);

// Hooks
int		key_press(int keycode, t_window *win);

// Cleaning
int		cleaning(t_window *win, char *line, int fd);
void	free_win(t_window *win);
void	ft_free_mtx(char **str);

#endif