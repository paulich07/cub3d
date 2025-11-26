/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:11:53 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/26 15:11:33 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_valid_flood_position(t_window *win, int y, int x)
{
	if (y < 0 || y >= win->map_height || x < 0)
		return (0);
	if (!win->map[y] || x >= (int)ft_strlen(win->map[y]))
		return (0);
	if (win->map[y][x] == '1' || win->map[y][x] == ' ')
		return (0);
	return (1);
}

// Flood fill to check if map is properly enclosed
void	flood_fill(t_window *win, int y, int x, int **visited)
{
	if (visited[0][0] == -1)
		return ;
	if (!is_valid_flood_position(win, y, x))
	{
		if (y >= 0 && y < win->map_height && x >= 0)
			visited[0][0] = -1;
		return ;
	}
	if (visited[y][x])
		return ;
	visited[y][x] = 1;
	check_boundary_escape(win, y, x, visited);
	if (visited[0][0] == -1)
		return ;
	flood_fill_neighbors(win, y, x, visited);
}

void	check_boundary_escape(t_window *win, int y, int x, int **visited)
{
	if (y == 0 || y == win->map_height - 1 || x == 0
		|| x == (int)ft_strlen(win->map[y]) - 1)
	{
		if (win->map[y][x] == '0' || win->map[y][x] == 'N'
			|| win->map[y][x] == 'S' || win->map[y][x] == 'E'
			|| win->map[y][x] == 'W')
		{
			visited[0][0] = -1;
		}
	}
}

void	flood_fill_neighbors(t_window *win, int y, int x, int **visited)
{
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

	visited = malloc(sizeof(int *) * win->map_height);
	if (!visited)
		return (0);
	i = 0;
	while (i < win->map_height)
	{
		visited[i] = ft_calloc(ft_strlen(win->map[i]), sizeof(int));
		if (!visited[i])
			return (small_free(i, visited), 0);
		i++;
	}
	flood_fill(win, (int)win->player_pos_y, (int)win->player_pos_x, visited);
	result = (visited[0][0] != -1);
	i = 0;
	while (i < win->map_height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	return (result);
}
