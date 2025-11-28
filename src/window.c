/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:27 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 18:26:26 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	init_win_img(t_window *win)
{
	win->win_img = malloc(sizeof(t_img));
	if (!win->win_img)
		exit_program(win, "init_win_img malloc error", 1);
	win->win_img->img = mlx_new_image(win->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!win->win_img->img)
		exit_program(win, "init_win_img mlx_new_image error", 1);
	win->win_img->addr = mlx_get_data_addr(win->win_img->img,
			&win->win_img->bpp, &win->win_img->line_len, &win->win_img->endian);
	if (!win->win_img->addr)
		exit_program(win, "init_win_img mlx_new_image error", 1);
	win->win_img->width = WINDOW_WIDTH;
	win->win_img->height = WINDOW_HEIGHT;
	return (0);
}

int	init_window(t_window *win)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		return (1);
	win->win = mlx_new_window(win->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!win->win)
		exit_program(win, "Window not loaded properly", 1);
	return (0);
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
