/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:50:35 by plichota          #+#    #+#             */
/*   Updated: 2025/10/23 17:40:39 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_minimap(t_window *win)
{
	int		x;
	int		y;

	y = 0;
	while (win->map[y])
	{
		x = 0;
		while (win->map[y][x])
		{
			render_image(win, y, x);
			x++;
		}
		y++;
	}
}

void	render_minimap_tiles(t_window *win, int y, int x)
{
	char	tile;

	tile = win->map[y][x];
	if (win->map[y][x] == '1')
		mlx_put_image_to_window(win->mlx, win->win,
			win->img_wall, x * MINITILE, y * MINITILE);
	else if (win->map[y][x] == '0')
		mlx_put_image_to_window(win->mlx, win->win,
			win->img_floor, x * MINITILE, y * MINITILE);
	else if (is_player(win, y, x))
		mlx_put_image_to_window(win->mlx, win->win,
			win->img_player, x * MINITILE, y * MINITILE);
	else if (win->map[y][x] == 'C')
		mlx_put_image_to_window(win->mlx, win->win,
			win->img_collect, x * MINITILE, y * MINITILE);
	else if (tile == 'E')
		mlx_put_image_to_window(win->mlx, win->win,
			win->img_exit, x * MINITILE, y * MINITILE);
}
