/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:13:57 by plichota          #+#    #+#             */
/*   Updated: 2025/11/05 21:44:12 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	key_hook(int keycd, t_window *win)
// {
// 	if (keycd == XK_w)
// 		mv_player(win, win->x, win->y -1);
// 	else if (keycd == XK_s)
// 		mv_player(win, win->x, win->y +1);
// 	else if (keycd == XK_a)
// 		mv_player(win, win->x - 1, win->y);
// 	else if (keycd == XK_d)
// 		mv_player(win, win->x + 1, win->y);
// 	else if (keycd == XK_Escape)
// 		cls_win(win);
// 	return (0);
// }

int	key_press(int keycode, t_window *win)
{
	if (keycode == XK_Escape)
		exit_program(win, "Exit", 0);
	if (keycode == XK_a)
		move_player(win, -1, 0);
	else if (keycode == XK_d)
		move_player(win, 1, 0);
	else if (keycode == XK_w)
		move_player(win, 0, -1);
	else if (keycode == XK_s)
		move_player(win, 0, 1);

	// if (keycode == XK_Left)
	// 	move_player(win, -1, 0);
	// else if (keycode == XK_Right)
	// 	move_player(win, 1, 0);
	// else if (keycode == XK_Up)
	// 	move_player(win, 0, -1);
	// else if (keycode == XK_Down)
	// 	move_player(win, 0, 1);
	return (1);
}
