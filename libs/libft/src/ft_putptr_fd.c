/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:48:53 by plichota          #+#    #+#             */
/*   Updated: 2024/12/21 16:54:22 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(void *p, int fd)
{
	unsigned long int	ptr;
	int					count;

	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ptr = (unsigned long int)p;
	count = 2;
	write(1, "0x", 2);
	count += ft_puthex_fd(ptr, 0, fd);
	return (count);
}
/* 
int main(void)
{
	char *s = "ciao";
	char *s2  = 0;

	printf("%p (printf)\n", s);
	ft_putptr_fd(s, 1);
	printf("\n%p (printf)\n", NULL);
	ft_putptr_fd(NULL, 1);
	printf("\n%p (printf)\n", s2);
	ft_putptr_fd(s2, 1);
} */
