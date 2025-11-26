/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:13:57 by plichota          #+#    #+#             */
/*   Updated: 2025/11/26 13:45:13 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int keycode, t_window *win)
{
	if (!win)
		exit_program(win, "key_press error, window not found", 1);
	if (keycode == XK_Escape)
		exit_program(win, "Exit", 0);
	if (keycode == XK_a)
		move_player(win, win->dir_y * MOV_SPEED, -win->dir_x * MOV_SPEED);
	else if (keycode == XK_d)
		move_player(win, -win->dir_y * MOV_SPEED, win->dir_x * MOV_SPEED);
	else if (keycode == XK_w)
		move_player(win, win->dir_x * MOV_SPEED, win->dir_y * MOV_SPEED);
	else if (keycode == XK_s)
		move_player(win, -win->dir_x * MOV_SPEED, -win->dir_y * MOV_SPEED);
	else if (keycode == XK_Right)
		rotate_player(win, ROT_ANGLE);
	else if (keycode == XK_Left)
		rotate_player(win, -ROT_ANGLE);
	win->moving = 1;
	win->keycode = keycode;
	return (1);
}

int	key_release(int keycode, t_window *win)
{
	if (!win)
		exit_program(win, "key_release error, window not found", 1);
	if (keycode == XK_a || keycode == XK_d
		|| keycode == XK_w || keycode == XK_s
		|| keycode == XK_Left || keycode == XK_Right)
	{
		win->moving = 0;
		win->keycode = 0;
	}
	return (1);
}

void	handle_input(t_window *win)
{
	if (!win)
		exit_program(win, "handle_input error, window not found", 1);
	if (win->moving)
		key_press(win->keycode, win);
}
