/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:52:41 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/27 13:22:34 by sel-khao         ###   ########.fr       */
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
	while (line && !is_map_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line != NULL && i < win->map_height)
	{
		if (is_config_line(line))
			return (free(line), 0);
		if (line[0] == '\n')
			return (free(line), 0);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		printf("DEBUG allocate: Processing line %d: '%s'\n", i, line);
		win->map[i] = normalize_map_line(line, win->map_width);
		if (!win->map[i])
			return (free(line), 0);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	win->map[i] = NULL;
	printf("DEBUG allocate: Actually allocated %d map lines\n", i);
	return (1);
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
			printf("DEBUG count_map: Found map line: '%.*s' (height=%d, width=%d)\n", len, line, win->map_height, win->map_width);
		}
		else
			printf("DEBUG count_map: Skipping non-map line: '%s'\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

char	*normalize_map_line(char *line, int target_width)
{
	char	*new_line;
	int		i;
	int		len;

	len = ft_strlen(line);
	new_line = malloc(target_width + 1);
	if (!new_line)
		return (NULL);
	
	i = 0;
	while (i < target_width)
	{
		if (i < len && line[i] != '\n')
			new_line[i] = line[i];
		else
			new_line[i] = ' ';  // Padding con spazi
		i++;
	}
	new_line[target_width] = '\0';
	return (new_line);
}

void	check_and_allocate_map(t_window *win, char *filename)
{
	int	fd;

	if (!win) // ADD THIS CHECK
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
