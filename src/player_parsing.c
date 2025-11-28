/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:01:17 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 13:50:19 by sel-khao         ###   ########.fr       */
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
