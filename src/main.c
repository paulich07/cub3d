/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:36:59 by sel-khao          #+#    #+#             */
/*   Updated: 2025/10/31 17:07:19 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

/* int validate_textures(t_config *config)
{
	int	fd;

	
} */

//make it a sepaate functio for errors + message
int	main(int argc, char **argv)
{
	t_config	config;

	initial(&config);
	if (argc != 2)
		return (write(2, "wrong usage\n", 13), 1);
	if (configure(argv[1], &config) == -1)
		return (free_config(&config), 1);
	set_hl(&config);
	if (sign(&config) == -1)
		return (free_config(&config), 1);
	if (find_player(&config) == -1)
		return (free_config(&config), 1);
	if (validate_textures(&config) == -1)
		return (free_config(&config), 1);
	if (check_wall(&config) == -1)
		return (free_config(&config), 1);
	if (validate_map_enclosed(&config) == -1)
		return (free_config(&config), 1);
	write(1, "map validated\n", 15);
	free_config(&config);
	return (0);
}
