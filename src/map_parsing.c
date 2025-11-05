/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:56:55 by plichota          #+#    #+#             */
/*   Updated: 2025/11/05 21:14:51 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// se fallisce exit program + svuota win e mappa
void	parse_map(t_window *win)
{
	if (!win || !win->map)
		exit_program(win, "Map not found", 1);
	// if (sign(&win) == -1)
	// 	return (free_win(&win), 1);
	if (find_player(win) != 1)
		exit_program(win, "Invalid number of players", 1);
	// if (validate_textures(&win) == -1)
	// 	return (free_win(&win), 1);
	// if (check_wall(&win) == -1)
	// 	return (free_win(&win), 1);
	// if (validate_map_enclosed(&win) == -1)
	// 	return (free_win(&win), 1);
	// free_win(&win);
}
