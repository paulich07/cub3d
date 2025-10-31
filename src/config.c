/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:47:06 by sel-khao          #+#    #+#             */
/*   Updated: 2025/10/31 18:12:34 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_open(char *file)
{
	int		fd;
	size_t	len;

	if (!file || ft_strlen(file) < 4)
		return (write(2, "Error file\n", 11), -1);
	len = ft_strlen(file) - 4;
	if (ft_strncmp(file + len, ".cub", 4) != 0)
		return (write(2, "Error file\n", 11), -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error file\n", 11), -1);
	return (fd);
}

//more or less 3 num X
//values outside 0-255
int	parse_rgb(char *line)
{
	int		r;
	int		g;
	int		b;
	char	**split;
	char	*str;

	str = line + 1; //skip f or c
	while (*str == ' ')
		str++;
	split = ft_split(str, ',');
	if (!split || !split[0] || !split[1] || !split[2] || split[3])
		return (write(2, "Error RGB/n", 9), -1);
	if (!valid_nbr(split[0]) || !valid_nbr(split[1]) || !valid_nbr(split[2]))
	{
		ft_free(split);
		return (write(2, "RGB must be numbers\n", 20), -1);
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_free(split);
		return (write(2, "Error Rgb\n", 10), -1);
	}
	ft_free(split);
	return ((r << 16) | (g << 8) | b);
}

//line = "NO ./path/to/texture.xpm\n"
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
/* 
int	error_handling(char *file, t_config *config)
{
	int		err;

	err = configure(file, config);
	if (err == 3)
		return (write(2, "Duplic\n", 6), -1);
	if (err == 4)
		return (write(2, "Error\n", 6), -1);
	return (0);
} */

int	cleaning(char *line, int fd, t_config *config)
{
	free(line);
	close(fd);
	free_config(config);
	write(2, "Malloc Failure\n", 15);
	return (-1);
}

int	configure(char *file, t_config *config)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (check_open(file) < 0)
		return (write(2, "invalid file\n", 13), -1);
	fill_map(file, config);
	fd = open(file, O_RDONLY);
	while (line = get_next_line(fd))
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			if (config->no != NULL)
				return (cleaning(line, fd, config));
			config->no = extract_path(line);
			if (config->no == NULL)
				return (cleaning(line, fd, config));
		}
		else if (ft_strncmp(line, "SO ", 3) == 0)
		{
			if (config->so != NULL)
				return (cleaning(line, fd, config));
			config->so = extract_path(line);
			if (config->so == NULL)
				return (cleaning(line, fd, config));
		}
		else if (ft_strncmp(line, "WE ", 3) == 0)
		{
			if (config->we != NULL)
				return (cleaning(line, fd, config));
			config->we = extract_path(line);
			if (config->we == NULL)
				return (cleaning(line, fd, config));
		}
		else if (ft_strncmp(line, "EA ", 3) == 0)
		{
			if (config->ea != NULL)
				return (cleaning(line, fd, config));
			config->ea = extract_path(line);
			if (config->ea == NULL)
				return (cleaning(line, fd, config));
		}
		else if (ft_strncmp(line, "F ", 2) == 0)
		{
			if (config->floor_set)
				return (3);
			config->floor = parse_rgb(line);
			if (config->floor == -1)
				return (cleaning(line, fd, config));
			config->floor_set = 1;
		}
		else if (ft_strncmp(line, "C ", 2) == 0)
		{
			if (config->ceiling_set)
				return (3);
			config->ceiling = parse_rgb(line);
			if (config->ceiling == -1)
				return (cleaning(line, fd, config));
			config->ceiling_set = 1;
		}
		else if (line[0] && line[0] != '\n')
		{
			config->map[i] = remove_newline(ft_strdup(line));
			if (!config->map[i])
				return (cleaning(line, fd, config));
			i++;
		}
		free(line);
	}
	if (!config->ceiling_set || !config->floor_set || !config->no
		|| !config->we || !config->ea || !config->so)
		return (4);
	close (fd);
	return (0);
}
