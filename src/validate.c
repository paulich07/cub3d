/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:03:42 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 18:56:17 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	verify_config_complete(t_window *win)
{
	if (win->floor_set == 0 || win->ceiling_set == 0)
		return (0);
	if (!win->path_no || !win->path_so)
		return (0);
	if (!win->path_we || !win->path_ea)
		return (0);
	return (1);
}

int	validate_all_textures(t_window *win)
{
	if (!val_tex_path(win->path_no) || !val_tex_path(win->path_so)
		|| !val_tex_path(win->path_we) || !val_tex_path(win->path_ea))
		return (0);
	return (1);
}

int	val_tex_path(char *path)
{
	int		fd;
	size_t	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 5)
		return (0);
	if (ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	sign(t_window *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->map[i])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] != 'N' && win->map[i][j] != '0' && \
				win->map[i][j] != 'S' && win->map[i][j] != '1' && \
				win->map[i][j] != 'E' && win->map[i][j] != ' ' && \
				win->map[i][j] != 'W')
				return (write(2, "Error sign\n", 11), -1);
			j++;
		}
		i++;
	}
	return (0);
}
