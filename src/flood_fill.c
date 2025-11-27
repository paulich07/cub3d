/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:11:53 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/27 13:24:29 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_boundary_escape(t_window *win, int y, int x)
{
    if (y == 0 || y == win->map_height - 1 || x == 0 || x == win->map_width - 1)
    {
        if (win->map[y][x] == '0' || win->map[y][x] == 'N' ||
            win->map[y][x] == 'S' || win->map[y][x] == 'E' ||
            win->map[y][x] == 'W')
        {
            win->escape_found = 1;
        }
    }
}

void	flood_fill_neighbors(t_window *win, int y, int x, int **visited)
{
	flood_fill(win, y - 1, x, visited);
	if (win->escape_found)
		return ;
	flood_fill(win, y + 1, x, visited);
	if (win->escape_found)
		return ;
	flood_fill(win, y, x - 1, visited);
	if (win->escape_found)
		return ;
	flood_fill(win, y, x + 1, visited);
}

void	flood_fill(t_window *win, int y, int x, int **visited)
{
    if (win->escape_found)
        return ;
    if (y < 0 || y >= win->map_height || x < 0 || x >= win->map_width)
    {
        win->escape_found = 1;
        return ;
    }
    if (win->map[y][x] == '1')
        return ;
    if (visited[y][x])
        return ;
    visited[y][x] = 1;
    check_boundary_escape(win, y, x);
    if (win->escape_found)
        return ;
    flood_fill(win, y - 1, x, visited);
    flood_fill(win, y + 1, x, visited);
    flood_fill(win, y, x - 1, visited);
    flood_fill(win, y, x + 1, visited);
}

int	check_map_enclosure_with_flood_fill(t_window *win)
{
	int	**visited;
	int	i;
	int	result;
	int	real_height;

	win->escape_found = 0;
	real_height = 0;
	while (real_height < win->map_height && win->map[real_height] != NULL)
		real_height++;
	if (real_height == 0)
		return (0);
	visited = malloc(sizeof(int *) * real_height);
	if (!visited)
		return (0);
	i = -1;
	while (++i < real_height)
	{
		visited[i] = ft_calloc(ft_strlen(win->map[i]) + 1, sizeof(int));
		if (!visited[i])
		{
			small_free(i, visited);
			return (0);
		}
	}
	printf("DEBUG: Flood fill starting from player position (%f, %f) -> (%d, %d)\n", win->player_pos_x, win->player_pos_y, (int)win->player_pos_y, (int)win->player_pos_x);
	flood_fill(win, (int)win->player_pos_y, (int)win->player_pos_x, visited);
	printf("DEBUG: Flood fill completed. Escape found: %d\n", win->escape_found);
	result = !win->escape_found;
	small_free(real_height, visited);
	return (result);
}
