/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:00:24 by plichota          #+#    #+#             */
/*   Updated: 2025/04/15 00:54:55 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_window *win)
{
	if (keycode == XK_Escape)
		exit_program(win, "Exit", 0);
	if (keycode == XK_Left)
		move_player(win, -1, 0);
	else if (keycode == XK_Right)
		move_player(win, 1, 0);
	else if (keycode == XK_Up)
		move_player(win, 0, -1);
	else if (keycode == XK_Down)
		move_player(win, 0, 1);
	return (1);
}

int	close_window(t_window *win)
{
	exit_program(win, "Window closed", 0);
	return (0);
}
