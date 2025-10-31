/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:28:01 by plichota          #+#    #+#             */
/*   Updated: 2025/10/31 16:17:32 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef TILE
#  define TILE 64
# endif

# include "libft.h"
//# include "mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct s_config
{
	size_t		h;
	size_t		l;
	int		x;
	int		y;
	char	**map;
	char	*no;//texture
	char	*so;
	char	*we;
	char	*ea;
	int		floor_set;
	int		floor;//color
	int		ceiling_set;
	int		ceiling;
}	t_config;

int		check_player(int p);
int		find_player(t_config *config);
void	set_hl(t_config *config);
int		check_wall(t_config *config);
int		sign(t_config *config);
char	*remove_newline(char *line);
char	*extract_path(char *line);
void	initial(t_config *config);

int		cleaning(char *line, int fd, t_config *config);
void	free_config(t_config *config);
void	ft_free(char **str);

int		parse_rgb(char *line);
int		check_open(char *file);
int		configure(char *file, t_config *config);
int		count_line(char *file, t_config *config);
void	fill_map(char *file, t_config *config);
//int		error_handling(char *file, t_config *config);

#endif