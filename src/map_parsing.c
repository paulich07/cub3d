/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:56:55 by plichota          #+#    #+#             */
/*   Updated: 2025/11/28 13:42:03 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*create_padded_line(t_window *win, int i)
{
	char	*new_line;
	int		j;

	new_line = malloc(win->map_width + 1);
	if (!new_line)
		return (NULL);
	j = 0;
	while (j < win->map_width)
	{
		if (j < (int)ft_strlen(win->map[i]) && win->map[i][j] != '\0')
			new_line[j] = win->map[i][j];
		else
			new_line[j] = ' ';
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

void	apply_padding_and_normalize(t_window *win)
{
	char	**padded_map;
	int		i;

	padded_map = ft_calloc(win->map_height + 1, sizeof(char *));
	if (!padded_map)
		exit_program(win, "Memory allocation failed", 1);
	i = 0;
	while (i < win->map_height && win->map[i])
	{
		padded_map[i] = create_padded_line(win, i);
		if (!padded_map[i])
		{
			ft_free_mtx(padded_map);
			exit_program(win, "Memory allocation failed", 1);
		}
		i++;
	}
	padded_map[i] = NULL;
	ft_free_mtx(win->map);
	win->map = padded_map;
	normalize_spaces_to_walls(win);
}

void	parse_map(t_window *win)
{
	printf("DEBUG: Starting parse_map\n");
	if (!win || !win->map)
		exit_program(win, "Map not found", 1);
	printf("=============ORIGINAL UNPADDED MAP================");
	print_map(win);
	if (sign(win) == -1)
		exit_program(win, "Invalid character in map", 1);
	printf("DEBUG: Initializing player\n");
	if (init_player(win) != 1)
		exit_program(win, "Invalid number of players", 1);
	printf("DEBUG: Starting flood fill\n");
	if (!check_map_enclosure_with_flood_fill(win))
		exit_program(win, "Map is not properly enclosed by walls", 1);
	printf("DEBUG: parse_map completed successfully\n");
	apply_padding_and_normalize(win);
	printf("=============FINAL PADDED MAP================");
	print_map(win);
	printf("DEBUG: parse_map completed successfully\n");
}
