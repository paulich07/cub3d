/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:01:17 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 18:25:59 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	move_player(t_window *win, double x, double y)
{
	if (!win)
		exit_program(win, "Window error", 1);
	if (is_wall(win, (int)(win->player_pos_x + x),
		(int)(win->player_pos_y + y)))
		return (printf("You hit a wall\n"), 1);
	win->player_pos_x += x;
	win->player_pos_y += y;
	return (0);
}

void	rotate_player(t_window *win, double rot_angle)
{
	double	old_dir_x;
	double	old_plane_x;

	if (!win)
		exit_program(win, "Window error", 1);
	old_dir_x = win->dir_x;
	old_plane_x = win->plane_x;
	win->dir_x = win->dir_x * cos(rot_angle)
		- win->dir_y * sin(rot_angle);
	win->dir_y = old_dir_x * sin(rot_angle)
		+ win->dir_y * cos(rot_angle);
	win->plane_x = win->plane_x * cos(rot_angle)
		- win->plane_y * sin(rot_angle);
	win->plane_y = old_plane_x * sin(rot_angle)
		+ win->plane_y * cos(rot_angle);
}

int	set_player_position(t_window *win, double y, double x)
{
	if (!win)
		exit_program(win, "Window error", 1);
	win->player_pos_y = y;
	win->player_pos_x = x;
	return (0);
}

int	set_player_direction(t_window *win, char c)
{
	if (!win)
		exit_program(win, "Window error", 1);
	if (c == 'N')
	{
		win->dir_y = -1;
		win->plane_x = 0.66;
	}
	else if (c == 'S')
	{
		win->dir_y = 1;
		win->plane_x = -0.66;
	}
	else if (c == 'E')
	{
		win->dir_x = 1;
		win->plane_y = 0.66;
	}
	else if (c == 'W')
	{
		win->dir_x = -1;
		win->plane_y = -0.66;
	}
	else
		exit_program(win, "Invalid direction", 1);
	return (0);
}
