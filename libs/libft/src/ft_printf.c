/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:44:55 by plichota          #+#    #+#             */
/*   Updated: 2024/12/20 21:36:08 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// per x e X passare unsigned intlib
// void * deve essere unsigned char

static int	assign(int type, va_list args)
{
	if (type == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (type == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (type == 'd' || type == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (type == 'p')
		return (ft_putptr_fd(va_arg(args, void *), 1));
	if (type == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), 1));
	if (type == 'x')
		return (ft_puthex_fd(va_arg(args, unsigned int), 0, 1));
	if (type == 'X')
		return (ft_puthex_fd(va_arg(args, unsigned int), 1, 1));
	if (type == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		c;
	va_list	args;

	i = 0;
	c = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			c += assign(s[i + 1], args);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			c++;
		}
		i++;
	}
	va_end(args);
	return (c);
}
/* 
int main(void)
{
	char *s = "gg lucky guy";
	char *s2 = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	ft_strlcpy(s2, s, ft_strlen(s));
	void *c = s;

	int a =    printf("coso %d %s %p %p %p\n", -23432423, "ciao", s, s2, c);
	int b = ft_printf("coso %d %s %p %p %p\n", -23432423, "ciao", s, s2, c);
	
	printf("a: %d, b: %d\n", a, b);

	a =    printf("coso %u %u %x %X %%\n", -2, -49672396, 23425, -111111);
	b = ft_printf("coso %u %u %x %X %%\n", -2, -49672396, 23425, -111111);
	
	printf("a: %d, b: %d\n", a, b);
} */
