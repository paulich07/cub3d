/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:41:29 by plichota          #+#    #+#             */
/*   Updated: 2025/11/17 19:39:28 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// performo dda
// (dalla pos player e dall'inclinazione del raggio calcola punto colpito sul raggio)
// calcola distanza
// ottieni distanza perpendicolare
// calcola draw_end e draw_start
// applica per colonna x della win_img
int	draw_column(t_window *win, int x, int dist)
{
	int draw_start;
	int draw_end;

	// draw walls (raycasting)
	// printf("draw walls\n");
	return (0);
}	

void	proiezione(t_window *win)
{
	
}

void	dda(t_window *win)
{
	
}

// estraggo raggio in base a pos player
void	init_ray(t_window *win)
{
	
}

// ottiene distanza dal centro per una colonna di pixel (lavora con gli img address)
int	raycasting(t_window *win)
{
	(void) win;

	// init ray (estraggo raggio in base a pos player)
	// dda (calcolare distanza perpendicolare, ottengo 1 vect pos e 1 vect dir)
	// proiezione - draw_start e draw_end
	// disegno floor and ceiling
	// disegno img	
	return (0);
}
