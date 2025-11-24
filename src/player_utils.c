/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:01:17 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/24 04:25:58 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// TO DO ADD ROT SPEED

// move player asdw
int	move_player(t_window *win, double x, double y)
{
	if (!win)
		exit_program(win, "Window error", 1);
	win->player_pos_x += x;
	win->player_pos_y += y;
	return (0);
}

// rotate player with arrows, direction vector and plane vector
void	rotate_player(t_window *win, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = win->plane_x;
	old_plane_x = win->dir_x;
	win->dir_x = win->dir_x * cos(rot_speed)
		- win->dir_y * sin(rot_speed);
	win->dir_y = old_dir_x * sin(rot_speed)
		+ win->dir_y * cos(rot_speed);
	win->plane_x = win->plane_x * cos(rot_speed)
		- win->plane_y * sin(rot_speed);
	win->plane_y = old_plane_x * sin(rot_speed)
		+ win->plane_y * cos(rot_speed);
}

int	set_player_position(t_window *win, double y, double x)
{
	if (!win)
		exit_program(win, "Window error", 1);
	win->player_pos_y = y;
	win->player_pos_x = x;
	return (0);
}

// to do error handling? valid chars
int	set_player_direction(t_window *win, char c)
{
	if (!win)
		exit_program(win, "Window error", 1);
	if (c == 'N')
	{
		win->dir_y = -1;
		win->plane_x = FOV_OFFSET;
	}
	else if (c == 'S')
	{
		win->dir_y = 1;
		win->plane_x = -FOV_OFFSET;
	}
	else if (c == 'E')
	{
		win->dir_x = 1;
		win->plane_y = FOV_OFFSET;
	}
	else if (c == 'W')
	{
		win->dir_x = -1;
		win->plane_y = -FOV_OFFSET;
	}
	else
		exit_program(win, "Invalid direction", 1);
	return (0);
}
