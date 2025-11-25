/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 04:10:05 by plichota          #+#    #+#             */
/*   Updated: 2025/11/25 16:40:19 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fix_fisheye(t_window *win, t_ray *ray)
{
	if (!win)
		exit_program(win, "fix_fisheye Window error", 1);
	if (ray->side == 0)
	{
		if (ray->dir_x == 0)
			ray->perp_wall_dist = 0.01;
		else
		{
			ray->perp_wall_dist = (ray->map_x - win->player_pos_x
					+ (1 - ray->step_x) / 2) / ray->dir_x;
		}
		if (ray->perp_wall_dist == 0)
			ray->perp_wall_dist = 0.01;
	}
	else
	{
		if (ray->dir_y == 0)
			ray->perp_wall_dist = 0.01;
		else
		{
			ray->perp_wall_dist = (ray->map_y - win->player_pos_y
					+ (1 - ray->step_y) / 2) / ray->dir_y;
		}
		if (ray->perp_wall_dist == 0)
			ray->perp_wall_dist = 0.01;
	}
}

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char	*dist;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dist = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int*)dist = color;
	}
}

void	draw_column(t_window *win, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y <= end)
	{
		put_pixel_to_img(win->win_img, x, y, color);
		y++;
	}
}


void	proiezione(t_window *win, t_ray *ray, int x)
{
	int	column_height;
	int	draw_start;
	int	draw_end;
	int	color;

	column_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);

	draw_start = -column_height / 2 + WINDOW_HEIGHT / 2;
	draw_end = column_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;

  // TO DO choose color based on side
	color = 0x789CAC;
	draw_column(win, x, draw_start, draw_end, color);
}