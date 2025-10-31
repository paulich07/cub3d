/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:36:59 by sel-khao          #+#    #+#             */
/*   Updated: 2025/10/27 17:18:28 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdio.h>

//make it a sepaate functio for errors + message
int	main(int argc, char **argv)
{
	t_config config;

	initial(&config);
	if (argc == 2)
	{
		if (configure(argv[1], &config) == -1)
			return (1);
		set_hl(&config);
		if (sign(&config) == -1)
			return (1);
		if (find_player(&config) == -1)
			return (1);
		if (check_wall(&config) == -1)
			return (1);
	}
	return (0);
}