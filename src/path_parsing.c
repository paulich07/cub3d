/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:47:06 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/01 21:11:28 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int is_valid_rgb(char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ')
		i++;
	j = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
		j++;
	}
	return (j == 3 && i == j);
}

// more or less 3 num X
// values outside 0-255
int	parse_rgb(char *line)
{
	int		r;
	int		g;
	int		b;
	char	**split;
	char	*str;

	str = line + 1; // skip F or C line
	while (*str == ' ')
		str++;
	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2])
		return (write(2, "Error RGB/n", 9), -1);
	if (!is_valid_rgb(split[0]) || !is_valid_rgb(split[1]) || !is_valid_rgb(split[2]))
	{
		ft_free_mxt(split);
		return (write(2, "RGB must be numbers\n", 20), -1);
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_free_mxt(split);
		return (write(2, "Error Rgb\n", 10), -1);
	}
	ft_free_mxt(split);
	return ((r << 16) | (g << 8) | b);
}

// line = "NO ./path/to/texture.xpm\n"
// TO DO check if the path is valid
char	*extract_path(char *line)
{
	int		i;
	int		j;
	char	*path;

	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = 0;
	path = malloc(sizeof(char) * (ft_strlen(line + i) + 1));
	if (!path)
		return (NULL);
	while (line[i] && line[i] != '\n' && line[i] != ' ')
	{
		path[j] = line[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}


// TO DO differentiate errors (failed path extraction vs wrong parsing)
// TO DO handle ALL errors (see below)
int	parse_paths(t_window *win, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_program(win, "Error in file opening", 1);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			if (win->path_no != NULL)
				return (cleaning(win, line, fd));
			win->path_no = extract_path(line);
			if (win->path_no == NULL)
				return (cleaning(win, line, fd));
		}
		else if (ft_strncmp(line, "SO ", 3) == 0)
		{
			if (win->path_so != NULL)
				return (cleaning(win, line, fd));
			win->path_so = extract_path(line);
			if (win->path_so == NULL)
				return (cleaning(win, line, fd));
		}
		else if (ft_strncmp(line, "WE ", 3) == 0)
		{
			if (win->path_we != NULL)
				return (cleaning(win, line, fd));
			win->path_we = extract_path(line);
			if (win->path_we == NULL)
				return (cleaning(win, line, fd));
		}
		else if (ft_strncmp(line, "EA ", 3) == 0)
		{
			if (win->path_ea != NULL)
				return (cleaning(win, line, fd));
			win->path_ea = extract_path(line);
			if (win->path_ea == NULL)
				return (cleaning(win, line, fd));
		}
		else if (ft_strncmp(line, "F ", 2) == 0)
		{
			if (parse_rgb(line) < 0)
				return (cleaning(win, line, fd));
			win->rgb_floor = parse_rgb(line);
			win->floor_set = 1;
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			if (parse_rgb(line) < 0)
				return (cleaning(win, line, fd));
			win->rgb_ceiling = parse_rgb(line);
			win->ceiling_set = 1;
		}
		else if (line[0] && line[0] != '\n') // TO DO CORREGGERE
		{
			// win->map[i] = remove_newline(ft_strdup(line)); // ??
			// if (!win->map[i])
			// 	return (cleaning(win, line, fd));
			i++;
		}
		// else
		// {
			// TO DO errore generico?
			// se c'e' spazio prima del nome? se e' formattato male? se c'e' roba dopo il path?
			// es     EAS ./path
		// 	return (cleaning(win, line, fd));
		// }
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (win->floor_set == 0 || win->ceiling_set == 0
		|| !win->path_no || !win->path_so || !win->path_we || !win->path_ea)
		return (4);
	close (fd);
	return (0);
}
