/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:44:59 by plichota          #+#    #+#             */
/*   Updated: 2024/12/21 16:53:52 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_fd(uintptr_t n, int caps, int fd)
{
	int	digit;
	int	count;
	int	base;

	count = 0;
	base = 16;
	if (n / base > 0)
		count += ft_puthex_fd(n / base, caps, fd);
	digit = n % base + '0';
	if (digit > '9' && caps == 0)
		digit = (n % base - 58 + 97) + '0';
	else if (digit > '9' && caps == 1)
		digit = (n % base - 58 + 65) + '0';
	write(fd, &digit, fd);
	count++;
	return (count);
}
/* 
int main(void)
{
	printf("\n%x (printf)\n", 22);
	ft_puthex_fd(22, 0, 1);

	printf("\n%x (printf)\n", 0);
	ft_puthex_fd(0, 0, 1);
} */
