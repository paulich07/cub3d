/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:36:59 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/01 22:06:26 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_window	win;
	char		*filename;

	win = (t_window){0};
	if (argc != 2)
		return (ft_printf("Wrong usage: ./cub3d <map.ber>\n"), 1);
	// FILENAME
	filename = argv[1];
	if (!is_valid_file(filename))
		return (1);
	// PATHS
	if (parse_paths(&win, filename) < 0)
		exit_program(&win, "Invalid texture path or rgb", 1);

	// CREATE MAP
	// set_hl(&win); integrato in count_map_size
	// fill_map(&win, filename); // diventa check_and_allocate_map
	check_and_allocate_map(&win, filename);
	printf("CHECK ALLOCATE OK");

	// FILL MAP
	// TO DO

	// if (!win.map || !*win.map)
	// 	exit_program(&win, "Map not allocated properly", 1); // if fill fails

	// PARSE MAP
	// if (sign(&config) == -1)
	// 	return (free_config(&config), 1);
	// if (find_player(&config) == -1)
	// 	return (free_config(&config), 1);
	// if (validate_textures(&config) == -1)
	// 	return (free_config(&config), 1);
	// if (check_wall(&config) == -1)
	// 	return (free_config(&config), 1);
	// if (validate_map_enclosed(&config) == -1)
	// 	return (free_config(&config), 1);
	// write(1, "map validated\n", 15);
	// free_config(&config);
	return (0);
}
