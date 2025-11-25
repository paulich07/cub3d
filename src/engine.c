/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:16:13 by plichota          #+#    #+#             */
/*   Updated: 2025/11/25 01:27:54 by plichota         ###   ########.fr       */
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

// render single frame
int	engine(t_window *win)
{
	int	x;
	// to do handle input
	// to do update position
	// to do disegna frame
	// printf("engine working\n");

	x = 0;
	draw_background(win);
	while (x < WINDOW_WIDTH)
	{
		raycasting(win, x);
		x++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->win_img->img, 0, 0);
	return (0);
}
