/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:20:24 by plichota          #+#    #+#             */
/*   Updated: 2025/11/17 18:38:14 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	free_paths(t_window *win)
{
	if (win->path_no)
		free(win->path_no);
	if (win->path_so)
		free(win->path_so);
	if (win->path_we)
		free(win->path_we);
	if (win->path_ea)
		free(win->path_ea);
}

// svuota win
// dealloca mappa
// dealloca eventuali immagini
// distrugge e libera window
void	exit_program(t_window *win, char *s, int error)
{
	// if (win->img_floor)
	// 	mlx_destroy_image(win->mlx, win->img_floor);
	// if (win->img_wall)
	// 	mlx_destroy_image(win->mlx, win->img_wall);
	// if (win->img_player)
	// 	mlx_destroy_image(win->mlx, win->img_player);
	// if (win->img_collect)
	// 	mlx_destroy_image(win->mlx, win->img_collect);
	// if (win->img_exit)
	// 	mlx_destroy_image(win->mlx, win->img_exit);
	if (win->map)
		ft_free_mtx(win->map);
	free_paths(win);
	if (win->win_img)
	{
		// mlx_destroy_image frees also addr
		if (win->win_img->img)
			mlx_destroy_image(win->mlx, win->win_img->img);
		free(win->win_img);
		win->win_img = NULL;
	}
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	if (error)
		ft_printf("Error ");
	if (s && ft_strlen(s) > 0)
		ft_printf("%s", s);
	ft_printf("\n");
	exit(0);
}
