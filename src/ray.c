/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:33:15 by plichota          #+#    #+#             */
/*   Updated: 2025/11/19 17:40:15 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_ray_step(t_window *win, t_ray *ray)
{
	if (!win || !ray)
		exit_program(win, "init_ray_step error", 1);
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_step_x = (win->player_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_step_x = (ray->map_x + 1.0 - win->player_x)
			* ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_step_y = (win->player_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_step_y = (ray->map_y + 1.0 - win->player_y)
			* ray->delta_dist_y;
	}
}
