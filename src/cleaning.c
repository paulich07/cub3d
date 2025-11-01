/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:15:37 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/01 21:09:20 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	cleaning(t_window *win, char *line, int fd)
{
	free(line);
	close(fd);
	free_win(win);
	write(2, "Malloc Failure\n", 15);
	return (-1);
}

void	ft_free_mxt(char **mxt)
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

void	free_win(t_window *win)
{
	if (win->path_no)
	{
		free(win->path_no);
		win->path_no = NULL;
	}
	if (win->path_so)
	{
		free(win->path_so);
		win->path_so = NULL;
	}
	if (win->path_ea)
	{
		free(win->path_ea);
		win->path_ea = NULL;
	}
	if (win->path_we)
	{
		free(win->path_we);
		win->path_we = NULL;
	}
	if (win->map)
	{
		ft_free_mxt(win->map);
		win->map = NULL;
	}
}


