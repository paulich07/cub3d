/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:01:17 by sel-khao          #+#    #+#             */
/*   Updated: 2025/10/31 16:44:39 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_player(int p)
{
	if (p != 1)
		return (write(2, "Error player\n", 13), -1);
	return (0);
}

int	find_player(t_config *config)
{
	int	x;
	int	y;
	int	p;

	p = 0;
	if (!config || !config->map)
		return (write(2, "Error player\n", 13), -1);
	y = 0;
	while (config->map[y])
	{
		x = 0;
		while (config->map[y][x])
		{
			if (config->map[y][x] == 'N' || config->map[y][x] == 'W' ||
				config->map[y][x] == 'S' || config->map[y][x] == 'E')
			{
				config->x = x;
				config->y = y;
				p++;
			}
			x++;
		}
		y++;
	}
	return (check_player(p));
}
