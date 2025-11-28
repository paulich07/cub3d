/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:21:32 by plichota          #+#    #+#             */
/*   Updated: 2025/11/28 19:46:03 by plichota         ###   ########.fr       */
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
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	print_map(t_window *win)
{
	int	i;
	int	j;

	if (!win || !win->map)
		return ((void)printf("Map is NULL!\n"));
	i = -1;
	while (++i < win->map_height && win->map[i])
	{
		printf("Map[%d]: '", i);
		j = -1;
		while (++j < (int)ft_strlen(win->map[i]))
		{
			if (win->map[i][j] == ' ')
				printf(" ");
			else
				printf("%c", win->map[i][j]);
		}
		printf("' (len: %zu)\n", ft_strlen(win->map[i]));
	}
}

int	is_valid_map_size(t_window *win)
{
	if (win->map_width < 3 || win->map_height < 3)
		return (0);
	return (1);
}
