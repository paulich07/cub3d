/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:41:29 by plichota          #+#    #+#             */
/*   Updated: 2025/11/28 15:15:27 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// side = 0 muro verticale
// ottiene distanza dal centro per una colonna di pixel
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
	fix_fisheye(win, ray);
}

// init ray (estraggo raggio in base a pos player)
// dda (calcolare distanza perpendicolare, ottengo 1 vect pos e 1 vect dir)
// disegno img
void	raycasting(t_window *win, int x)
{
	t_ray	ray;

	init_ray(win, &ray, x);
	dda(win, &ray);
	projection(win, &ray, x);
}
