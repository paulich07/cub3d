/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:52:41 by sel-khao          #+#    #+#             */
/*   Updated: 2025/10/31 16:54:12 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	initial(t_config *config)
{
	config->x = 0;
	config->y = 0;
	config->h = 0;
	config->l = 0;
	config->map = NULL;
	config->no = NULL;
	config->so = NULL;
	config->ea = NULL;
	config->we = NULL;
	config->ceiling_set = 0;
	config->floor_set = 0;
	config->floor = -1;
	config->ceiling = -1;
}

int	count_line(char *file, t_config *config)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if (check_open(file) < 0)
		return (write(2, "invalid file\n", 13), -1);
	fd = open(file, O_RDONLY);
/* 	config->l = ft_strlen(line) -1;
	config->h = 0; //u gotta fill the map, 3x3 is minimum */
	line = get_next_line(fd);
	while ((line))
	{
		if (!(ft_strncmp(line, "NO ", 3) == 0
				|| ft_strncmp(line, "SO ", 3) == 0
				|| ft_strncmp(line, "EA ", 3) == 0 || line[0] == '\n'
				|| ft_strncmp(line, "WE ", 3) == 0
				|| ft_strncmp(line, "F ", 2) == 0
				|| ft_strncmp(line, "C ", 2) == 0))
			i++;
		free(line);
	}
	close (fd);
	return (i);
}

void	fill_map(char *file, t_config *config)
{
	int	len;

	len = count_line(file, config);
	config->map = malloc(sizeof(char *) * (len + 1));
	if (!config->map)
		return ;
	config->map[len] = NULL;
	return ;
}
