/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:56:55 by plichota          #+#    #+#             */
/*   Updated: 2025/11/26 15:14:22 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// se fallisce exit program + svuota win e mappa
void	parse_map(t_window *win)
{
	if (!win || !win->map)
		exit_program(win, "Map not found", 1);
	if (sign(win) == -1)
		exit_program(win, "Invalid character in map", 1);
	if (init_player(win) != 1)
		exit_program(win, "Invalid number of players", 1);
	if (!check_map_enclosure_with_flood_fill(win))
		exit_program(win, "Map is not properly enclosed by walls", 1);
}
