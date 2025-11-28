/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:53:58 by plichota          #+#    #+#             */
/*   Updated: 2025/11/28 18:26:14 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// to do textures walls per ea e we
t_img	*get_side_texture(t_window *win, t_ray *ray)
{
	if (!win || !ray)
		exit_program(win, "get_side_texture error", 1);
	if (ray->side == 0)
		return (win->no);
	else
		return (win->so);
}

// last 4 chars are .xpm
int	check_texture_path(char *path)
{
	size_t	len;

	if (!path)
		return (write(2, "Missing Texture\n", 17), -1);
	if (ft_strlen(path) < 4)
		return (write(2, "Error, invalid .xmp\n", 21), -1);
	len = ft_strlen(path) - 4;
	if (is_directory(path))
		return (write(2, "Error, texture is a directory\n", 30), -1);
	return (1);
}

int	load_texture(t_window *win, t_img *img, char *path)
{
	if (!win || !img || !path)
		exit_program(win, "load_texture error", 1);
	img = malloc(sizeof(t_img));
	if (!img)
		exit_program(win, "load_texture malloc error", 1);
	img->img = mlx_xpm_to_image(win->mlx, &path, &img->width, &img->height);
	if (!img->img)
		exit_program(win, "load_texture mlx_xpm_to_image error", 1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	if (!img->addr)
		exit_program(win, "load_texture mlx_get_data_addr error", 1);
	img->width = TEXTURE_WIDTH;
	img->height = TEXTURE_HEIGHT;
	return (0);
}

int	init_textures(t_window *win)
{
	if (!win || !win->path_ea || !win->path_no
		|| !win->path_so || !win->path_we)
		exit_program(win, "init_textures error", 1);
	load_texture(win, win->no, win->path_no);
	load_texture(win, win->so, win->path_so);
	load_texture(win, win->we, win->path_we);
	load_texture(win, win->ea, win->path_ea);
	return (0);
}
