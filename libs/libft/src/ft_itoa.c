/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:18:28 by plichota          #+#    #+#             */
/*   Updated: 2024/12/07 16:18:31 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	allocate_number(char *s, long int n, int count)
{
	char	c;

	c = (n % 10) + '0';
	s[count - 1] = c;
	if (n / 10 >= 1)
		allocate_number(s, n / 10, count - 1);
}

static int	count_numbers(long int n)
{
	int	count;

	count = 0;
	while (n / 10 >= 1)
	{
		count++;
		n /= 10;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	int			count;
	int			sign;
	long int	nmb;
	char		*s;

	count = 0;
	sign = 1;
	nmb = (long int)n;
	if (nmb < 0)
	{
		sign *= -1;
		nmb *= -1;
		count++;
	}
	count += count_numbers(nmb);
	s = ft_calloc((count + 1), sizeof(char));
	if (!s)
		return (NULL);
	allocate_number(s, nmb, count);
	if (sign < 0)
		s[0] = '-';
	return (s);
}

/* int	main(void)
{
	char *s = ft_itoa(-2147483648);
	printf("printf %s", s);
} */
