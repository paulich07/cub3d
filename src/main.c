/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:36:59 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 13:52:07 by sel-khao         ###   ########.fr       */
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
	printf("DEBUG: Map height: %d, width: %d\n", win.map_height, win.map_width);
	printf("DEBUG: Player pos: %f, %f\n", win.player_pos_x, win.player_pos_y);
	if (!win.map || !*win.map)
		exit_program(&win, "Map not allocated properly", 1);
	parse_map(&win);
/* 	printf("=== STEP 6: Initialize window ===\n");
	init_window(&win);
	printf("DEBUG: Window initialized successfully\n");
	printf("=== STEP 7: Initialize image ===\n");
	init_win_img(&win);
	printf("DEBUG: Image initialized successfully\n");
	printf("=== STEP 8: Setting up hooks ===\n");
	mlx_key_hook(win.win, key_press, &win);
	printf("DEBUG: Key hook set\n");
	mlx_hook(win.win, KeyPress, KeyPressMask, key_press, &win);
	printf("DEBUG: Key press hook set\n");
	mlx_hook(win.win, KeyRelease, KeyReleaseMask, key_release, &win);
	printf("DEBUG: Key release hook set\n");
	mlx_hook(win.win, 17, 0, close_window, &win);
	printf("DEBUG: Close window hook set\n");
	printf("=== STEP 9: Starting main loop ===\n");
	mlx_loop_hook(win.mlx, engine, &win);
	printf("DEBUG: Loop hook set\n");
	mlx_loop(win.mlx);
	printf("DEBUG: MLX loop started\n"); */
	return (0);
}
