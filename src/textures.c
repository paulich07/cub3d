/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:53:58 by plichota          #+#    #+#             */
/*   Updated: 2025/11/01 17:11:12 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_texture(char *name, char *path)
{
	int		fd;
	size_t	len;

	if (!path)
		return (write(2, "Missing Texture\n", 17), -1);
	if (ft_strlen(path) < 4)
		return (write(2, "Error, invalid .xmp\n", 21), -1);
	len = ft_strlen(path) - 4;//.xmp starts at
}
