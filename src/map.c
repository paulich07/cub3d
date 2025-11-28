/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:52:41 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 16:53:47 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_map(t_window *win)
{
	printf("DEBUG: Starting parse_map\n");
	if (!win || !win->map)
		exit_program(win, "Map not found", 1);
	if (sign(win) == -1)
		exit_program(win, "Invalid character in map", 1);
	printf("DEBUG: Initializing player\n");
	if (init_player(win) != 1)
		exit_program(win, "Invalid number of players", 1);
	printf("DEBUG: Starting flood fill\n");
	if (!check_map_enclosure_with_flood_fill(win))
		exit_program(win, "Map is not properly enclosed by walls", 1);
	printf("DEBUG: parse_map completed successfully\n");
}

char	*skip_config_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && !is_map_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	count_map_size(t_window *win, char *filename)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_program(win, "Error in file opening", 1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line))
		{
			win->map_height++;
			len = ft_strlen(line);
			if (line[len - 1] == '\n')
				len--;
			if (len > win->map_width)
				win->map_width = len;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	check_and_allocate_map(t_window *win, char *filename)
{
	int	fd;

	if (!win)
		exit_program(win, "Window is NULL", 1);
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
