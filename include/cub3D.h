/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:28:01 by plichota          #+#    #+#             */
/*   Updated: 2025/11/01 21:08:58 by plichota         ###   ########.fr       */
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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			map_height;
	int			map_width;
	float		pos_x;
	float		pos_y;
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

// Map parsing
int		is_valid_map_size(t_window *win);
void	count_map_size(t_window *win, char *filename);
void	check_and_allocate_map(t_window *win, char *filename);

// Textures
int		check_texture(char *name, char *path);

// Map utils
void	deallocate_map(char **map, int height);
int		allocate_map_from_file(t_window *win, int fd);

// Program utils
void	exit_program(t_window *win, char *s, int error);

// Fill Map
int		count_line(char *file, t_window *config);
void	fill_map(char *file, t_window *config);

// Map validation
int		check_player(int p);
int		find_player(t_window *config);

int		check_wall(t_window *config);
int		sign(t_window *config);
// char	*remove_newline(char *line);

// Cleaning
int		cleaning(t_window *win, char *line, int fd);
void	free_win(t_window *win);
void	ft_free_mxt(char **str);

#endif