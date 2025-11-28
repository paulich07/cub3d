/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:21:19 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 18:24:12 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	is_valid_filename(char *filename)
{
	if (!filename)
		return (0);
	if (ft_strlen(filename) < 4)
		return (0);
	if (ft_strncmp(filename + (ft_strlen(filename) - 4), ".cub", 4) != 0)
		return (0);
	return (1);
}

int	is_directory(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd < 0)
		return (0);
	return (close(fd), 1);
}

int	is_valid_file(char *filename)
{
	if (!is_valid_filename(filename))
		return (printf("Invalid file format\n"), 0);
	if (is_directory(filename))
		return (printf("Directory instead of file provided\n"), 0);
	return (1);
}
