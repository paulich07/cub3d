/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:27 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/05 20:14:22 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	init_window(t_window *win)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		return (1);
	win->win = mlx_new_window(win->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!win->win)
		exit_program(win, "Window not loaded properly", 1);
	return (1);
}

int	close_window(t_window *win)
{
	exit_program(win, "Window closed", 0);
	return (0);
}

// TO DO
// void	place_img(t_window *win)
// {
// 	win->no = creat_textu(win->map, "textur/no.xpm", win);
// 	win->ea = creat_textu(win->map, "textur/ea.xpm", win);
// 	win->so = creat_textu(win->map, "textur/so.xpm", win);
// 	win->we = creat_textu(win->map, "textur/we.xpm", win);
// 	win->floor = creat_textu(win->map, "textur/floor.xpm", win);
// 	win->ceiling = creat_textu(win->map, "textur/ceiling.xpm", win);
// }

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

// int	img_check(char *file)
// {
// 	int		fd;
// 	size_t	len;

// 	if (!file || ft_strlen(file) < 5)
// 		return (write (2, "Error Image\n", 12), -1);
// 	len = ft_strlen(file) - 4;
// 	if (ft_strnwindow.ccmp(file + len, ".xpm", 4) != 0)
// 		return (write (2, "Error Image\n", 12), -1);
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (write(2, "Error Image\n", 12), -1);
// 	close (fd);
// 	return (0);
// }
