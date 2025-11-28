/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:42:11 by plichota          #+#    #+#             */
/*   Updated: 2025/11/28 18:26:17 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// float absolute value
double	ft_fabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	is_wall(t_window *win, int x, int y)
{
	if (x < 0 || x >= win->map_width || y < 0 || y >= win->map_height)
		return (1);
	if (win->map[y][x] == '1')
		return (1);
	return (0);
}
