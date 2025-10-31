/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:15:37 by sel-khao          #+#    #+#             */
/*   Updated: 2025/10/31 15:04:56 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void free_config(t_config *config)
{
	if (!config)
		return ;
	if (config->no)
	{
		free(config->no);
		config->no = NULL;
	}
	if (config->so)
	{
		free(config->so);
		config->so = NULL;
	}
	if (config->ea)
	{
		free(config->ea);
		config->ea = NULL;
	}
	if (config->we)
	{
		free(config->we);
		config->we = NULL;
	}
	if (config->map)
	{
		ft_free(config->map);
		config->map = NULL;
	}
}

void	ft_free(char **mxt)
{
	int	i;

	i = 0;
	if (!mxt)
		return ;
	while (mxt[i])
	{
		free(mxt[i]);
		i++;
	}
	free(mxt);
}
