/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:16:13 by plichota          #+#    #+#             */
/*   Updated: 2025/11/05 21:49:59 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// render single frame
int	engine(t_window *win)
{
	(void) win;
	int	x;
	int color = 0xABCDEF;

	color = mlx_get_color_value(mlx, color);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		if (x < WINDOW_WIDTH / 2)
			mlx_put_img_to_win(win->mlx, win->img_floor, x, 0);
		else
			mlx_put_img_to_win(win->mlx, win->img_ceiling, x, 0);
		// disegno colonna per colonna dentro immagine
		// metto a schermo l'immagine con mlx_put_img_to_win
		x++;
	}
	return (0);
}
