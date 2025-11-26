/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:28:01 by plichota          #+#    #+#             */
/*   Updated: 2025/11/26 16:04:14 by sel-khao         ###   ########.fr       */
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
# include <math.h>

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600
# define ROT_ANGLE		0.01
# define MOV_SPEED		0.005
# define MAX_STEPS		100
# define FOV_OFFSET		0.66

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

// typedef struct s_vector
// {
// 	double	x;
// 	double	y;
// }	t_vector;

typedef struct s_ray
{
	int			map_x;
	int			map_y;
	double		dir_x;
	double		dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_step_x;
	double		side_step_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
}	t_ray;

// plane rappresenta metà dell'ampiezza della finestra
// FOV = 2 × atan(plane / 1)

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		*win_img;
	int			map_height;
	int			map_width;
	double		map_x;
	double		map_y;
	double		player_pos_x;
	double		player_pos_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		dir_x;
	double		dir_y;
	char		**map;
	int			rgb_floor;
	int			rgb_ceiling;
	int			floor_set;
	int			ceiling_set;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	int			moving;
	int			keycode;
}	t_window;

//new ones
int		validate_and_convert_rgb(char **split);
void	check_boundary_escape(t_window *win, int y, int x, int **visited);
void	flood_fill_neighbors(t_window *win, int y, int x, int **visited);

int		check_map_enclosure_with_flood_fill(t_window *win);
void	flood_fill(t_window *win, int y, int x, int **visited);
int		verify_config_complete(t_window *win);
int		handle_texture(t_window *win, char *line, char **path_ptr);
int		handle_color(t_window *win, char *line, int *rgb, int *flag);
int		validate_all_textures(t_window *win);
int		val_tex_path(char *path);
int		is_config_line(char *line);

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
// int		check_wall(t_window *config); // se serve cambia nome
int		sign(t_window *config);

// Player parsing
int		init_player(t_window *config);

// Player utils
int		move_player(t_window *win, double x, double y);
int		set_player_position(t_window *win, double y, double x);
int		set_player_direction(t_window *win, char c);
void	rotate_player(t_window *win, double rot_angle);

// Window
int		init_win_img(t_window *win);
int		init_window(t_window *win);
int		close_window(t_window *win);

// Program utils
void	exit_program(t_window *win, char *s, int error);

// Ray casting
void	dda(t_window *win, t_ray *ray);
void	raycasting(t_window *win, int x);

// Ray
void	init_ray_step(t_window *win, t_ray *ray);
void	init_ray(t_window *win, t_ray *ray, int x);

// Draw
void	fix_fisheye(t_window *win, t_ray *ray);
void	put_pixel_to_img(t_img *img, int x, int y, int color);
void	draw_column(t_window *win, int x, int start, int end, int color);
void	proiezione(t_window *win, t_ray *ray, int x);

// Engine
int		engine(t_window *win);

// Hooks
int		key_press(int keycode, t_window *win);
int		key_release(int keycode, t_window *win);
void	handle_input(t_window *win);

// Cleaning

void	small_free(int size, int **arr);
int		cleaning(t_window *win, char *line, int fd);
void	free_win(t_window *win);
void	ft_free_mtx(char **str);

// Utils
double	ft_fabs(double x);
int		is_wall(t_window *win, int x, int y);

#endif