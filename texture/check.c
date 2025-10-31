/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:21:19 by sel-khao          #+#    #+#             */
/*   Updated: 2025/10/31 19:10:29 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_texture(char *name, char *path)
{
	int		fd;
	size_t	len;

	if (!path)
		return (write(2, "Missing Texture\n", 17), -1);
	if (ft_strlen(path) < 4)
		return (write(2, "Error, invalid .xmp\n", 21), -1);
	len = ft_strlen(path) - 4;//.xmp starts at
}