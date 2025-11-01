/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:47:17 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/01 21:10:22 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	dest_img(t_window *win)
// {
// 	if (win->floor)
// 		mlx_destroy_image(win->map, win->floor);
// 	if (win->ceiling)
// 		mlx_destroy_image(win->map, win->ceiling);
// 	if (win->ea)
// 		mlx_destroy_image(win->map, win->ea);
// 	if (win->so)
// 		mlx_destroy_image(win->map, win->so);
// 	if (win->we)
// 		mlx_destroy_image(win->map, win->we);
// 	if (win->no)
// 		mlx_destroy_image(win->map, win->no);
// 	dest_win(win);
// }

void	destroy_win(t_window *win)
{
	if (!win)
		return ;
	if (win->map)
		ft_free_mxt(win->map);
	if (win->map)
	{
		mlx_destroy_display(win->map);
		free(win->map);
	}
}

int	close_win(t_window *win)
{
	dest_img(win);
	exit(1);
	return (0);
}
