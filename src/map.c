/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:52:41 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/26 15:15:20 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_valid_map_size(t_window *win)
{
	if (win->map_width < 3 || win->map_height < 3)
		return (0);
	return (1);
}

int	allocate_map_from_file(t_window *win, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (!is_map_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL)
	{
		if (is_config_line(line))
			return (0);
		if (line[0] == '\n')
			return (0);
		if (line[(ft_strlen(line)) - 1] == '\n')
			line[(ft_strlen(line)) - 1] = '\0';
		win->map[i++] = line;
		line = get_next_line(fd);
	}
	win->map[i] = NULL;
	return (1);
}

void	count_map_size(t_window *win, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_program(win, "Error in file opening", 1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
		{
			win->map_height++;
			if (ft_strlen(line) > 1
				&& (int)(ft_strlen(line) - 1) >= win->map_width)
				win->map_width = ft_strlen(line) - 1;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return ;
}

void	check_and_allocate_map(t_window *win, char *filename)
{
	int	fd;

	if (!filename)
		exit_program(win, "Filename not specified", 1);
	count_map_size(win, filename);
	if (!is_valid_map_size(win))
		exit_program(win, "Map has not a valid size", 1);
	win->map = ft_calloc(win->map_height + 1, sizeof(char *));
	if (!win->map)
		exit_program(win, "Map not allocated properly", 1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_program(win, "Error in file opening", 1);
	if (!allocate_map_from_file(win, fd))
	{
		close(fd);
		exit_program(win, "Map allocation from file failed", 1);
	}
	print_map(win);
	close(fd);
	return ;
}
