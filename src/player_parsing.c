/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:01:17 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/05 21:13:12 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"



// if player found set pos and dir, returns 1
// if player not found return -1
int	find_player(t_window *win)
{
	int	x;
	int	y;
	int	p;

	if (!win || !win->map)
		exit_program(win, "Map not found", 1);
	p = 0;
	y = 0;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			if (win->map[y][x] == 'N' || win->map[y][x] == 'W' ||
				win->map[y][x] == 'S' || win->map[y][x] == 'E')
			{
				set_player_position(win, (double)y + 0.5, (double)x + 0.5);
				set_player_direction(win, win->map[y][x]);
				p++;
			}
			x++;
		}
		y++;
	}
	if (p != 1)
		exit_program(win, "Invalid number of players", 1);
	return (p);
}
