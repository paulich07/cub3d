/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:01:17 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/26 19:30:15 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// if player found set pos and dir, returns 1
// if player not found return -1
int	init_player(t_window *win)
{
	int	i;
	int	j;
	int	player_count;

	if (!win || !win->map) // ADD NULL CHECK
		return (0);
	player_count = 0;
	i = -1;
	while (win->map[++i])
	{
		j = -1;
		while (win->map[i][++j])
		{
			if (win->map[i][j] == 'N' || win->map[i][j] == 'S' || 
				win->map[i][j] == 'E' || win->map[i][j] == 'W')
			{
				player_count++;
				win->player_pos_x = j + 0.5;
				win->player_pos_y = i + 0.5;
				printf("DEBUG: Found player '%c' at map[%d][%d], setting position to (%f, %f)\n", win->map[i][j], i, j, win->player_pos_x, win->player_pos_y);
				set_player_direction(win, win->map[i][j]);
				win->map[i][j] = '0';
			}
		}
	}
	printf("DEBUG: init_player result: %d players found\n", player_count);
	return (player_count == 1);
}

/* int	init_player(t_window *win)
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
				win->map[y][x] = '0';
				p++;
			}
			x++;
		}
		y++;
	}
	return (p);
} */
