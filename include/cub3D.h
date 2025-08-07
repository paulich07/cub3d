/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:28:01 by plichota          #+#    #+#             */
/*   Updated: 2025/08/07 15:28:43 by plichota         ###   ########.fr       */
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

// typedef struct s_data
// {
// 	void	*mlx;
// 	void	*win;
// 	char	**map;
// 	char	**map_copy;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	void	*img_floor;
// 	void	*img_wall;
// 	void	*img_player;
// 	void	*img_collect;
// 	void	*img_exit;
// 	int		pos_x;
// 	int		pos_y;
// 	int		map_height;
// 	int		map_width;
// 	int		n_coins;
// 	int		n_players;
// 	int		n_exit;
// 	int		n_moves;
// 	int		n_collected_coins;
// }	t_window;

// typedef struct s_elements
// {
// 	int		n_coins;
// 	int		n_players;
// 	int		n_exit;
// }	t_elements;

// // Main
// void	parse_map(t_window *win);
// int		is_valid_file(char *filename);

// // Hooks
// int		key_press(int keycode, t_window *vars);
// int		close_window(t_window *win);

// // Parsing
// int		is_valid_filename(char *filename);
// int		is_directory(char *filename);
// int		check_every_line(t_window *win, int fd, char **l);
// int		is_valid_map_size(t_window *win, char *filename);
// void	check_and_allocate_map(t_window *win, char *filename);

// // Map parsing
// void	count_elements(t_window *win);
// void	check_walls(t_window *win, char **map);
// void	check_counted_elements(t_window *win);
// void	check_reachable(t_window *win);

// // Utils
// int		is_walkable(t_window *win, int x, int y);
// int		contains_only(char *s, char *allowed);
// void	flood_fill(t_window *win, t_elements *elem, int curr_x, int curr_y);
// void	render_image(t_window *win, int y, int x);
// void	put_images(t_window *win);

// // Player Utils
// void	initialize_player_position(t_window *win);
// void	move_player(t_window *win, int move_x, int move_y);
// int		all_coins_collected(t_window *win);
// int		is_exit(t_window *win, int pos_y, int pos_x);

// // Program Utils
// void	exit_program(t_window *win, char *s, int error);

// // Map Utils
// void	deallocate_map(char **map, int height);
// void	copy_map(t_window *win);
// void	render_map(t_window *win);
// int		allocate_map_from_file(t_window *win, int fd);

#endif