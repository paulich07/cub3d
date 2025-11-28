/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:47:06 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 13:49:31 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	validate_line_end(char *line, int i)
{
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_config_line(char *line)
{
	if (!line || line[0] == '\n')
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

int	parse_config_line(t_window *win, char *line)
{
	int	result;

	result = 0;
	if (ft_strncmp(line, "NO ", 3) == 0)
		result = handle_texture(win, line, &win->path_no);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		result = handle_texture(win, line, &win->path_so);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		result = handle_texture(win, line, &win->path_we);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		result = handle_texture(win, line, &win->path_ea);
	else if (ft_strncmp(line, "F ", 2) == 0)
		result = handle_color(win, line, &win->rgb_floor, &win->floor_set);
	else if (ft_strncmp(line, "C ", 2) == 0)
		result = handle_color(win, line, &win->rgb_ceiling, &win->ceiling_set);
	return (result);
}

int	parse_paths(t_window *win, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_program(win, "Error\nFile opening failed", 1);
	line = get_next_line(fd);
	while (line)
	{
		if (is_config_line(line))
		{
			if (parse_config_line(win, line) < 0)
				return (cleaning(win, line, fd));
		}
		else if (line[0] != '\n')
			break ;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (!verify_config_complete(win))
		return (-1);
	return (0);
}

char	*extract_path(char *line)
{
	int		i;
	int		j;
	char	*path;

	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (line[j] && line[j] != '\n')
		j++;
	path = malloc(sizeof(char) * (j - i + 1));
	if (!path)
		return (NULL);
	j = 0;
	while (line[i] && line[i] != '\n')
	{
		path[j] = line[i];
		i++;
		j++;
	}
	path[j] = '\0';
	while (j > 0 && (path[j - 1] == ' ' || path[j - 1] == '\t'))
		path[--j] = '\0';
	return (path);
}
