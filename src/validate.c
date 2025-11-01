/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:03:42 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/01 20:58:30 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	sign(t_window *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->map[i])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] != 'N' && win->map[i][j] != '0' && \
				win->map[i][j] != 'S' && win->map[i][j] != '1' && \
				win->map[i][j] != 'E' && win->map[i][j] != ' ' && \
				win->map[i][j] != 'W')
				return (write(2, "Error sign\n", 11), -1);
			j++;
		}
		i++;
	}
	return (0);
}

// char	*remove_newline(char *line)
// {
// 	int	len;

// 	if (!line)
// 		return (NULL);
// 	len = ft_strlen(line);
// 	if (len > 0 && line[len -1] == '\n')
// 		line[len -1] = '\0';
// 	return (line);
// }

// void	set_hl(t_window *win)
// {
// 	size_t	i;
// 	size_t	max;
// 	size_t	curr;

// 	i = 0;
// 	max = 0;
// 	while (win->map[i])
// 	{
// 		curr = ft_strlen(win->map[i]);
// 		if (curr > max)
// 			max = curr;
// 		i++;
// 	}
// 	win->h = i;
// 	win->l = max;
// }

int	check_wall(t_window *win)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(win->map[0]) - 2;
	while (win->map[i])
	{
		j = 0;
		while (win->map[i][j] && win->map[i][j] != '\n')
		{
			if (i == 0 && win->map[i][j] != '1' && win->map[i][j] != ' ')
				return (write(2, "Error Walls\n", 12), -1);
			if ((i == win->h - 1) && win->map[i][j] != '1'
				&& win->map[i][j] != ' ')
				return (write(2, "Error Walls\n", 12), -1);
			if (j == 0 && win->map[i][j] != '1' && win->map[i][j] != ' ')
				return (write(2, "Error Walls\n", 12), -1);
			if (j == len && win->map[i][j] != '1' && win->map[i][j] != 32)
				return (write(2, "Error Walls\n", 12), -1);
			j++;
		}
		i++;
	}
	return (0);
}
