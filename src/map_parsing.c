/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:56:55 by plichota          #+#    #+#             */
/*   Updated: 2025/11/27 16:52:34 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	parse_map(t_window *win)
{
	printf("DEBUG: Starting parse_map\n");
	if (!win || !win->map)
		exit_program(win, "Map not found", 1);
	printf("=============BEFORE================");
	print_map(win);
	normalize_spaces_to_walls(win);
	printf("=============AFTER================");
	print_map(win);
	if (sign(win) == -1)
		exit_program(win, "Invalid character in map", 1);
	printf("DEBUG: Initializing player\n");
	if (init_player(win) != 1)
		exit_program(win, "Invalid number of players", 1);
	printf("DEBUG: Starting flood fill\n");
	if (!check_map_enclosure_with_flood_fill(win))
		exit_program(win, "Map is not properly enclosed by walls", 1);
	printf("DEBUG: parse_map completed successfully\n");
}
