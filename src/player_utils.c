/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:01:17 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/05 21:35:41 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// TO DO ADD ROT SPEED

int	move_player(t_window *win, double x, double y)
{
	if (!win)
		exit_program(win, "Window error", 1);
	win->pos_x += x;
	win->pos_y += y;
	return (0);
}

int	set_player_position(t_window *win, double y, double x)
{
	if (!win)
		exit_program(win, "Window error", 1);
	win->pos_y = y;
	win->pos_x = x;
	return (0);
}

// to do error handling? valid chars
int	set_player_direction(t_window *win, char c)
{
	if (!win)
		exit_program(win, "Window error", 1);
	win->dir_x = 0;
	win->dir_y = 0;
	if (c == 'N')
		win->dir_y = -1;
	else if (c == 'S')
		win->dir_y = 1;
	else if (c == 'E')
		win->dir_x = 1;
	else if (c == 'W')
		win->dir_x = -1;
	return (0);
}
