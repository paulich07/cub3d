/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:00:33 by plichota          #+#    #+#             */
/*   Updated: 2025/04/15 00:35:55 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_program(t_window *win, char *s, int error)
{
	deallocate_map(win->map, win->map_height);
	deallocate_map(win->map_copy, win->map_height);
	if (win->img_floor)
		mlx_destroy_image(win->mlx, win->img_floor);
	if (win->img_wall)
		mlx_destroy_image(win->mlx, win->img_wall);
	if (win->img_player)
		mlx_destroy_image(win->mlx, win->img_player);
	if (win->img_collect)
		mlx_destroy_image(win->mlx, win->img_collect);
	if (win->img_exit)
		mlx_destroy_image(win->mlx, win->img_exit);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	if (error)
		ft_printf("Error\n");
	if (s && ft_strlen(s) > 0)
		ft_printf("%s\n", s);
	exit(0);
}
