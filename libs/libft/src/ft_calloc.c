/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:37:47 by plichota          #+#    #+#             */
/*   Updated: 2024/11/25 15:37:48 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	if (nmemb * size > 2147483647)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}

/* int main(void)
{
	size_t size;
	size_t n;

	size = 8;
	n = 3;
	unsigned char *s = ft_calloc(n, size);
	size_t i = 0;
	while(i < n)
	{
		printf("%c", *s);
		i++;
	}
	free(s);
} */