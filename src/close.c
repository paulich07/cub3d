/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:47:17 by sel-khao          #+#    #+#             */
/*   Updated: 2025/10/31 16:47:40 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
