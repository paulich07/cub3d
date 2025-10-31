/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:23:27 by sel-khao          #+#    #+#             */
/*   Updated: 2025/10/31 16:05:50 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	place_img(t_config *config)
{
	config->no = creat_textu(config->map, "textur/no.xpm", config);
    config->ea = creat_textu(config->map, "textur/ea.xpm", config);
    config->so = creat_textu(config->map, "textur/so.xpm", config);
    config->we = creat_textu(config->map, "textur/we.xpm", config);
	config->floor = creat_textu(config->map, "textur/floor.xpm", config);
	config->ceiling = creat_textu(config->map, "textur/ceiling.xpm", config);
}
//to change
int	key_hook(int keycd, t_config *config)
{
	if (keycd == XK_w)
		mv_player(config, config->x, config->y -1);
	else if (keycd == XK_s)
		mv_player(config, config->x, config->y +1);
	else if (keycd == XK_a)
		mv_player(config, config->x - 1, config->y);
	else if (keycd == XK_d)
		mv_player(config, config->x + 1, config->y);
	else if (keycd == XK_Escape)
		cls_win(config);
	return (0);
}

int	img_check(char *file)
{
	int		fd;
	size_t	len;

	if (!file || ft_strlen(file) < 5)
		return (write (2, "Error Image\n", 12), -1);
	len = ft_strlen(file) - 4;
	if (ft_strncmp(file + len, ".xpm", 4) != 0)
		return (write (2, "Error Image\n", 12), -1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error Image\n", 12), -1);
	close (fd);
	return (0);
}

void	dest_img(t_config *config)
{
	if (config->floor)
		mlx_destroy_image(config->map, config->floor);
	if (config->ceiling)
		mlx_destroy_image(config->map, config->ceiling);
	if (config->ea)
		mlx_destroy_image(config->map, config->ea);
	if (config->so)
		mlx_destroy_image(config->map, config->so);
	if (config->we)
		mlx_destroy_image(config->map, config->we);
	if (config->no)
		mlx_destroy_image(config->map, config->no);
	dest_win(config);
}

void	dest_win(t_config *config)
{
	if (!config)
		return ;
	if (config->map)
		ft_free(config->map);
	if (config->map)
	{
		mlx_destroy_display(config->map);
		free(config->map);
	}
}

int	close_win(t_config *config)
{
	dest_img(config);
	exit(1);
	return (0);
}
