/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:00:26 by plichota          #+#    #+#             */
/*   Updated: 2025/08/07 15:30:59 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	count_elements(t_window *win)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			if (win->map[y][x] == 'C')
				win->n_coins++;
			if (win->map[y][x] == 'P')
				win->n_players++;
			if (win->map[y][x] == 'E')
				win->n_exit++;
			x++;
		}
		y++;
	}
}

void	check_walls(t_window *win, char **map)
{
	int	i;

	i = 1;
	if (!contains_only(map[0], "1")
		|| !contains_only(map[win->map_height - 1], "1"))
		exit_program(win, "Invalid walls, map not closed properly", 1);
	while (i < win->map_height - 1)
	{
		if (!contains_only(map[i], "01EPC"))
			exit_program(win, "Invalid character found in map", 1);
		if (map[i][0] != '1' || map[i][win->map_width - 1] != '1')
			exit_program(win, "Invalid walls, map not closed properly", 1);
		i++;
	}
}

void	check_counted_elements(t_window *win)
{
	if (win->n_exit != 1)
		exit_program(win, "Invalid number of Exit (E)", 1);
	if (win->n_players != 1)
		exit_program(win, "Invalid number of Players (P)", 1);
	if (win->n_coins < 1)
		exit_program(win, "Invalid number of Collectables (C)", 1);
}

void	check_reachable(t_window *win)
{
	t_elements	elem;

	elem = (t_elements){0};
	if (!win->pos_x || !win->pos_y)
		exit_program(win, "Invalid player position", 1);
	flood_fill(win, &elem, win->pos_y, win->pos_x);
	if (win->n_players != elem.n_players
		|| win->n_coins != elem.n_coins
		|| elem.n_exit < 1)
		exit_program(win,
			"Invalid map:not all elements are reachable", 1);
}
