/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:36:59 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/26 15:13:33 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_window	win;
	char		*filename;

	win = (t_window){0};
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
		exit_program(&win, "Map not allocated properly", 1);
	parse_map(&win);
	init_window(&win);
	init_win_img(&win);
	mlx_key_hook(win.win, key_press, &win);
	mlx_hook(win.win, 17, 0, close_window, &win);
	mlx_loop_hook(win.mlx, engine, &win);
	mlx_loop(win.mlx);
	return (0);
}
