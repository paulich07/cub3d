/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:41:29 by plichota          #+#    #+#             */
/*   Updated: 2025/11/18 20:08:39 by plichota         ###   ########.fr       */
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
void	init_ray(t_window *win, t_ray *ray, int x)
{
	double camera_x;
	
	camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	
	// Ray direction
	ray->dir_x = win->dir_x + win->plane_x * camera_x;
	ray->dir_y = win->dir_y + win->plane_y * camera_x;
	
	// Current map position
	ray->map_x = (int)win->player_x;
	ray->map_y = (int)win->player_y;
	
	// Length of ray from one side to next in map
	ray->delta_dist_x = ft_fabs(1 / ray->dir_x);
	ray->delta_dist_y = ft_fabs(1 / ray->dir_y);
	
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_step_x = (win->player_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_step_x = (ray->map_x + 1.0 - win->player_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_step_y = (win->player_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_step_y = (ray->map_y + 1.0 - win->player_y) * ray->delta_dist_y;
	}
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
