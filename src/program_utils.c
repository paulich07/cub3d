/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 17:20:24 by plichota          #+#    #+#             */
/*   Updated: 2025/11/28 18:54:23 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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

void	free_textures(t_window *win)
{
	if (win->no)
	{
		if (win->no->img)
			mlx_destroy_image(win->mlx, win->no);
		free(win->no);
	}
	if (win->so)
	{
		if (win->so->img)
			mlx_destroy_image(win->mlx, win->so);
		free(win->so);
	}
	if (win->we)
	{
		if (win->we->img)
			mlx_destroy_image(win->mlx, win->we);
		free(win->we);
	}
	if (win->ea)
	{
		if (win->ea->img)
			mlx_destroy_image(win->mlx, win->ea);
		free(win->ea);
	}
}

// svuota win
// dealloca mappa
// dealloca eventuali immagini
// distrugge e libera window
void	exit_program(t_window *win, char *s, int error)
{
	free_textures(win);
	free_paths(win);
	if (win->map)
		ft_free_mtx(win->map);
	if (win->win_img)
	{
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
