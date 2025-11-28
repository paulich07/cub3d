/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 04:10:05 by plichota          #+#    #+#             */
/*   Updated: 2025/11/28 18:24:01 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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

int	get_texture_color(t_img *img, int x, int y)
{
	return (0x789CAC);
}

int	calculate_texture_x(t_img *win, int x, int y)
{
	
}

void	draw_column_textures(t_window *win, t_ray *ray, int x)
{
	double step;
	
	step = 1.0 * ray->texture->height / ray->column_height;
	// capisce quale x della texture usare (prospettiva, tipo scaling orizzontale)
	// capisce quanto stretcharla lungo la colonna (tipo scaling verticale)
	// per ogni y della colonna prende pixel, calcola colore e lo disegna

}

void	projection(t_window *win, t_ray *ray, int x)
{
	if (!win || !ray)
		exit_program(win, "projection error", 1);
	ray->column_height = (int)(WINDOW_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->column_height / 2 + WINDOW_HEIGHT / 2;
	ray->draw_end = ray->column_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
	ray->texture = get_side_texture(win, ray);
	draw_column_textures(win, ray, x);
}
