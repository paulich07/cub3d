/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:21:32 by plichota          #+#    #+#             */
/*   Updated: 2025/11/27 13:23:09 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	normalize_spaces_to_walls(t_window *win)
{
	int	i;
	int	j;

	if (!win || !win->map)
		return ;
	i = 0;
	while (i < win->map_height && win->map[i])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] == ' ')
				win->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

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
