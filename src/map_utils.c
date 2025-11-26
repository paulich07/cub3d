/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:21:32 by plichota          #+#    #+#             */
/*   Updated: 2025/11/26 18:55:46 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_map_line(char *line)
{
	int	i;
	if (!line || line[0] == '\0' || line[0] == '\n')
		return (0);
	if (is_config_line(line))
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1' &&
			line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && 
			line[i] != 'W' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

/* int	is_map_line(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0
		|| line[0] == '\n'
		|| ft_strlen(line) <= 0)
		return (0);
	return (1);
} */

void	print_map(t_window *win)
{
	int	i;

	if (!win || !win->map) {
		printf("Map is NULL!\n");
		return;
	}
	
	i = 0;
	while (i < win->map_height && win->map[i])
	{
		printf("Map[%d]: '", i);
		// Stampa carattere per carattere per vedere spazi
		for (int j = 0; j < (int)ft_strlen(win->map[i]); j++) {
			if (win->map[i][j] == ' ')
				printf(" ");
			else
				printf("%c", win->map[i][j]);
		}
		printf("' (len: %zu)\n", ft_strlen(win->map[i]));
		i++;
	}
}

/* void	print_map(t_window *win)
{
	int	i;

	if (!win || !win->map) {
		printf("Map is NULL!\n");
		return;
	}
	i = 0;
	while (i < win->map_height && win->map[i])
	{
		printf("Map[%d]: %s\n", i, win->map[i]);
		i++;
	}
} */
