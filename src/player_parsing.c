/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:01:17 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 19:46:03 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_player(t_window *win)
{
	int	i;
	int	j;
	int	player_count;

	if (!win || !win->map)
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
				set_player_direction(win, win->map[i][j]);
				win->map[i][j] = '0';
			}
		}
	}
	return (player_count == 1);
}
