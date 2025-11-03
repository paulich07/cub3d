/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:21:32 by plichota          #+#    #+#             */
/*   Updated: 2025/11/03 18:52:36 by plichota         ###   ########.fr       */
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

// allocate rows
// TO DO TEST
int	allocate_map_from_file(t_window *win, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (!is_map_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
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

void	print_map(t_window *win)
{
	int	i;

	i = 0;
	while (i < win->map_height)
	{
		printf("%s\n", win->map[i]);
		i++;
	}
	return ;
}
