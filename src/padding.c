/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:23:54 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 14:25:52 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	normalize_spaces_to_walls(t_window *win)
{
	int	i;
	int	j;

	if (!win || !win->map)
		return ;
	i = 0;
	while (i < win->map_height && win->map[i])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] == ' ')
				win->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

char	*normalize_map_line(char *line, int target_width)
{
	char	*new_line;
	int		i;
	int		len;

	len = ft_strlen(line);
	new_line = malloc(target_width + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < target_width)
	{
		if (i < len && line[i] != '\n')
			new_line[i] = line[i];
		else
			new_line[i] = ' ';
		i++;
	}
	new_line[target_width] = '\0';
	return (new_line);
}

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
