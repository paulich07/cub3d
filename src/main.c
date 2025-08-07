/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:34:24 by plichota          #+#    #+#             */
/*   Updated: 2025/08/07 15:31:01 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_map(t_window *win)
{
	copy_map(win);
	check_walls(win, win->map_copy);
	count_elements(win);
	check_counted_elements(win);
	initialize_player_position(win);
	check_reachable(win);
}

int	is_valid_file(char *filename)
{
	if (!is_valid_filename(filename))
		return (ft_printf("Invalid file format"), 0);
	if (is_directory(filename))
		return (ft_printf("Directory instead of file provided"), 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_window	win;
	char		*filename;

	win = (t_window){0};
	if (argc != 2)
		return (ft_printf("Usage: ./so_long <map.ber>"), 1);
	filename = argv[1];
	if (!is_valid_file(filename))
		return (1);
	check_and_allocate_map(&win, filename);
	if (!win.map || !*win.map)
		exit_program(&win, "Map not allocated properly", 1);
	parse_map(&win);
	win.mlx = mlx_init();
	if (!win.mlx)
		return (1);
	win.win = mlx_new_window(win.mlx, win.map_width * TILE,
			win.map_height * TILE, "so_long");
	if (!win.win)
		exit_program(&win, "Window not loaded properly", 1);
	put_images(&win);
	render_map(&win);
	mlx_key_hook(win.win, key_press, &win);
	mlx_hook(win.win, 17, 0, close_window, &win);
	mlx_loop(win.mlx);
}
