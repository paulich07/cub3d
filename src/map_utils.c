/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:21:32 by plichota          #+#    #+#             */
/*   Updated: 2025/11/01 20:49:50 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	deallocate_map(char **map, int height)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	allocate_map_from_file(t_window *win, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	win->map_width = ft_strlen(line);
	if (line[(ft_strlen(line)) - 1] == '\n')
		line[(ft_strlen(line)) - 1] = '\0';
	win->map_width = ft_strlen(line);
	while (line != NULL)
	{
		if (line[(ft_strlen(line)) - 1] == '\n')
			line[(ft_strlen(line)) - 1] = '\0';
		win->map[i++] = line;
		line = get_next_line(fd);
	}
	win->map[i] = NULL;
	return (1);
}
