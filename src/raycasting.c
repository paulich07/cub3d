/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:41:29 by plichota          #+#    #+#             */
/*   Updated: 2025/11/19 17:46:29 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	proiezione(t_window *win)
{
	
}

void	dda(t_window *win)
{

}

// estraggo raggio in base a pos player
// camera_x dice quanto sono spostata dal centro
// 	rispetto alla direzione in cui guardo e al campo visivo
void	init_ray(t_window *win, t_ray *ray, int x)
{
	double camera_x;

	camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->dir_x = win->dir_x + win->plane_x * camera_x;
	ray->dir_y = win->dir_y + win->plane_y * camera_x;
	ray->map_x = (int)win->player_x;
	ray->map_y = (int)win->player_y;
	ray->delta_dist_x = ft_fabs(1 / ray->dir_x);
	ray->delta_dist_y = ft_fabs(1 / ray->dir_y);
	init_ray_step(win, ray);
}

init_player(t_window *win)
{
	
}

// ottiene distanza dal centro per una colonna di pixel (lavora con gli img address)
int	raycasting(t_window *win, int x)
{
	t_ray	ray;

	// init ray (estraggo raggio in base a pos player)
	init_ray(win, &ray, x);
	// dda (calcolare distanza perpendicolare, ottengo 1 vect pos e 1 vect dir)
	dda(win, &ray);
	// proiezione - draw_start e draw_end
	proiezione(win, &ray, x);
	// disegno floor and ceiling
	// disegno img	
	return (0);
}
