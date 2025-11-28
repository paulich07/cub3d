/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:19:39 by sel-khao          #+#    #+#             */
/*   Updated: 2025/11/28 19:31:06 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//handles no,so,we,ea
int	handle_texture(t_window *win, char *line, char **path_ptr)
{
	(void)win;
	if (*path_ptr != NULL)
		return (-1);
	*path_ptr = extract_path(line);
	if (*path_ptr == NULL)
		return (-1);
	return (0);
}

//handles lines of f/c
int	handle_color(t_window *win, char *line, int *rgb, int *flag)
{
	(void)win;
	if (*flag == 1)
		return (-1);
	*rgb = parse_rgb(line);
	if (*rgb < 0)
		return (-1);
	*flag = 1;
	return (0);
}

int	is_valid_rgb(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+')
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return (0);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (str[i] == '\0' || str[i] == ',');
}

int	parse_rgb(char *line)
{
	char	**split;
	char	*str;
	int		result;
	int		i;

	str = line + 1;
	while (*str == ' ')
		str++;
	if (str[ft_strlen(str) - 1] == '\n')
		str[ft_strlen(str) - 1] = '\0';
	split = ft_split(str, ',');
	if (!split)
		return (write(2, "Error: Memory allocation failed\n", 32), -1);
	i = 0;
	while (split[i] && i < 4)
		i++;
	if (i != 3 || split[0][0] == '\0' || split[1][0] == '\0'
		|| split[2][0] == '\0')
	{
		ft_free_mtx(split);
		return (write(2, "Error: RGB empty\n", 17), -1);
	}
	result = validate_and_convert_rgb(split);
	ft_free_mtx(split);
	return (result);
}

int	validate_and_convert_rgb(char **split)
{
	int	r;
	int	g;
	int	b;

	if (!is_valid_rgb(split[0]) || !is_valid_rgb(split[1])
		|| !is_valid_rgb(split[2]))
	{
		write(2, "RGB must be numbers\n", 20);
		return (-1);
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		write(2, "Error Rgb\n", 10);
		return (-1);
	}
	return ((r << 16) | (g << 8) | b);
}
