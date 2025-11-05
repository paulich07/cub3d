/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:21:32 by plichota          #+#    #+#             */
/*   Updated: 2025/11/05 21:02:44 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// is map 1
// is not map 0
int	is_map_line(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0
		|| line[0] == '\n'
		|| ft_strlen(line) <= 0)
		return (0);
	return (1);
}

void	print_map(t_window *win)
{
	int	i;

	i = 0;
	while (i < win->map_height)
	{
		printf("%s\n", win->map[i]);
		i++;
	}
	return ;
}
