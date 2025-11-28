/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:33:15 by plichota          #+#    #+#             */
/*   Updated: 2025/11/28 18:26:06 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	init_ray_step(t_window *win, t_ray *ray)
{
	if (!win || !ray)
		exit_program(win, "init_ray_step error", 1);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_step_x = (win->player_pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_step_x = (ray->map_x + 1.0 - win->player_pos_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_step_y = (win->player_pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_step_y = (ray->map_y + 1.0 - win->player_pos_y)
			* ray->delta_dist_y;
	}
}

// estraggo raggio in base a pos player
// camera_x dice quanto sono spostata dal centro
// 	rispetto alla direzione in cui guardo e al campo visivo
void	init_ray(t_window *win, t_ray *ray, int x)
{
	double camera_x;

	if (!win || !ray)
		exit_program(win, "init_ray error", 1);
	camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->dir_x = win->dir_x + win->plane_x * camera_x;
	ray->dir_y = win->dir_y + win->plane_y * camera_x;
	ray->map_x = (int)win->player_pos_x;
	ray->map_y = (int)win->player_pos_y;
	// if (ray->dir_x == 0)
	// 	ray->dir_x = 0.000001;
	// if (ray->dir_y == 0)
	// 	ray->dir_y = 0.000001;
	ray->delta_dist_x = ft_fabs(1 / ray->dir_x);
	ray->delta_dist_y = ft_fabs(1 / ray->dir_y);
	init_ray_step(win, ray);
}
