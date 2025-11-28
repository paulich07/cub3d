/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:56:55 by plichota          #+#    #+#             */
/*   Updated: 2025/11/28 19:46:03 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	validate_remaining_lines(char *line, int fd)
{
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line && line[0] != '\n')
		return (free(line), 0);
	if (line)
		free(line);
	return (1);
}

int	skip_to_map_start(int fd, char **line)
{
	int	map_started;

	map_started = 0;
	*line = skip_config_lines(fd);
	if (!*line)
		return (0);
	while (*line != NULL)
	{
		if (is_config_line(*line))
			return (free(*line), 0);
		if ((*line)[0] == '\n')
		{
			if (map_started)
				break;
			free(*line);
			*line = get_next_line(fd);
			continue ;
		}
		map_started = 1;
		break;
	}
	return (map_started);
}

int	process_map_lines(t_window *win, int fd, char *line)
{
	int	i;

	i = 0;
	while (line != NULL && i < win->map_height)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		win->map[i] = ft_strdup(line);
		if (!win->map[i])
			return (free(line), 0);
		free(line);
		i++;
		line = get_next_line(fd);
		if (line && line[0] == '\n')
			break ;
	}
	win->map[i] = NULL;
	return (validate_remaining_lines(line, fd));
}

int	allocate_map_from_file(t_window *win, int fd)
{
	char	*line;
	int		map_started;

	map_started = skip_to_map_start(fd, &line);
	if (!map_started)
		return (0);
	
	return (process_map_lines(win, fd, line));
}

