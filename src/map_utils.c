/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/08/07 15:30:59 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	deallocate_map(char **map, int height)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/// @brief create a dynamically allocated copy of the map 
/// @param win general structure containing
/// 		pointers to both the original map and the copy 
void	copy_map(t_window *win)
{
	int	i;

	if (!win->map)
		exit_program(win, "Map not saved properly: impossible to copy", 1);
	if (win->map_height < 1)
		exit_program(win, "Map height not appropriate", 1);
	if (win->map_width < 1)
		exit_program(win, "Map width not appropriate", 1);
	win->map_copy = ft_calloc(win->map_height + 1, sizeof(char *));
	if (!win->map_copy)
		exit_program(win, "Map not allocated properly", 1);
	i = 0;
	while (i < win->map_height)
	{
		win->map_copy[i] = ft_strdup(win->map[i]);
		if (!win->map_copy[i])
		{
			deallocate_map(win->map_copy, i);
			exit_program(win, "Map line not allocated properly", 1);
		}
		i++;
	}
	win->map_copy[i] = NULL;
}

void	render_map(t_window *win)
{
	int		x;
	int		y;

	y = 0;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			render_image(win, y, x);
			x++;
		}
		y++;
	}
}

int	allocate_map_from_file(t_window *win, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	win->map_width = ft_strlen(line);
	if (line[(ft_strlen(line)) - 1] == '\n')
		line[(ft_strlen(line)) - 1] = '\0';
	win->map_width = ft_strlen(line);
	while (line != NULL)
	{
		if (line[(ft_strlen(line)) - 1] == '\n')
			line[(ft_strlen(line)) - 1] = '\0';
		win->map[i++] = line;
		line = get_next_line(fd);
	}
	win->map[i] = NULL;
	return (1);
}
