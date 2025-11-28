/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:41:29 by plichota          #+#    #+#             */
/*   Updated: 2025/11/28 01:39:38 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// side = 0 muro verticale
void	dda(t_window *win, t_ray *ray)
{
	int	hit;
	int	steps;

	hit = 0;
	steps = 0;
	while (!hit && steps < MAX_STEPS)
	{
		if (ray->side_step_x < ray->side_step_y)
		{
			ray->side_step_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_step_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (win->map[ray->map_y][ray->map_x] == '1')
			hit = 1;
		steps++;
	}
	// if (hit)
	fix_fisheye(win, ray);
}

// ottiene distanza dal centro per una colonna di pixel (lavora con gli img address)
void	raycasting(t_window *win, int x)
{
	t_ray	ray;

	// init ray (estraggo raggio in base a pos player)
	init_ray(win, &ray, x);
	// dda (calcolare distanza perpendicolare, ottengo 1 vect pos e 1 vect dir)
	dda(win, &ray);
	// projection - draw_start e draw_end
	// disegno img
	projection(win, &ray, x);
}
