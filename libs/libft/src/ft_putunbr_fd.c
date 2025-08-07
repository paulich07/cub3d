/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:38:27 by plichota          #+#    #+#             */
/*   Updated: 2024/12/21 16:55:14 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	digit;
	int	count;

	count = 0;
	if (n / 10 > 0)
		count += ft_putunbr_fd(n / 10, fd);
	digit = n % 10 + '0';
	write(fd, &digit, 1);
	count++;
	return (count);
}
