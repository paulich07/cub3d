/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 04:10:05 by plichota          #+#    #+#             */
/*   Updated: 2025/11/28 20:36:52 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_texture_color(t_img *img, int x, int y)
{
	char	*pixel;
	int		color;

	if (!img)
		return (-1);
	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

// calcola quale punto della parete colpisce il raggio
// wall_x percentuale del muro colpito (in decimale)
// moltiplicando per texture width ottengo larghezza in pixel
// in base al punto colpito della wall stretcha la texture_x
// side = 0 verticale, leggo dall'alto al basso (Y)
// side = 1 orizzontale, leggo dalla sinistra a destra (X)
void	calculate_texture_x(t_window *win, t_ray *ray)
{
	double	wall_x;

	if (!win || !ray)
		exit_program(win, "calculate_texture_x Window error", 1);
	if (ray->side == 0)
		wall_x = win->player_pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		wall_x = win->player_pos_x + ray->perp_wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	ray->texture_x = (int)(wall_x * (double)ray->texture->width);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		ray->texture_x = ray->texture->width - ray->texture_x - 1;
}
