/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:21:19 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/01 21:18:56 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/// check if filename ends with ".ber"
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

/// check if the filename is a directory
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
		return (ft_printf("Invalid file format\n"), 0);
	if (is_directory(filename))
		return (ft_printf("Directory instead of file provided\n"), 0);
	return (1);
}
