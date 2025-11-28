/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:36:59 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 20:39:23 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx(t_window *win)
{
	mlx_key_hook(win->win, key_press, win);
	mlx_hook(win->win, KeyPress, KeyPressMask, key_press, win);
	mlx_hook(win->win, KeyRelease, KeyReleaseMask, key_release, win);
	mlx_hook(win->win, 17, 0, close_window, win);
	mlx_loop_hook(win->mlx, engine, win);
	mlx_loop(win->mlx);
}

int	main(int argc, char **argv)
{
	t_window	win;
	char		*filename;

	ft_memset(&win, 0, sizeof(t_window));
	if (argc != 2)
		return (ft_printf("Wrong usage: ./cub3d <map.cub>\n"), 1);
	filename = argv[1];
	if (!is_valid_file(filename))
		return (1);
	if (parse_paths(&win, filename) < 0)
		exit_program(&win, "Invalid texture path or rgb", 1);
	if (validate_all_textures(&win) == 0)
		exit_program(&win, "Invalid texture file", 1);
	check_and_allocate_map(&win, filename);
	if (!win.map || !*win.map)
	{
		free_paths(&win);
		exit_program(&win, "Map not allocated properly", 1);
	}
	parse_map(&win);
	init_window(&win);
	init_win_img(&win);
	init_textures(&win);
	init_mlx(&win);
	return (0);
}
