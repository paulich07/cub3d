/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:16:13 by plichota          #+#    #+#             */
/*   Updated: 2025/11/18 19:31:26 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	draw_background(t_window *win)
{
	int	tot_pixels;
	int	half_pixels;
	int	*pixel;
	int	i;

	tot_pixels = WINDOW_WIDTH * WINDOW_HEIGHT;
	half_pixels = tot_pixels / 2;
	pixel = (int *)win->win_img->addr;
	i = 0;
	while (i < half_pixels)
	{
		pixel[i] = win->rgb_floor;
		i++;
	}
	while (i < tot_pixels)
	{
		pixel[i] = win->rgb_ceiling;
		i++;
	}
	return (0);
}

// calcola draw_end e draw_start
// sovrascrive colori muro per colonna x della win_img
int	draw_column(t_window *win, int x, int dist)
{
	int draw_start;
	int draw_end;

	// draw walls (raycasting)
	// printf("draw walls\n");
	return (0);
}

// render single frame
int	engine(t_window *win)
{
	int	x;
	double	dist;
	// to do handle input
	// to do update position
	// to do disegna frame
	printf("engine working\n");

	x = 0;
	draw_background(win);
	while (x < WINDOW_WIDTH)
	{

		dist = raycasting(win, x); // ottiene distanza perpendicolare
		// draw_column(win, x, dist);
		x++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->win_img->img, 0, 0);
	return (0);
}
