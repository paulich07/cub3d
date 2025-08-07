/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:43:00 by plichota          #+#    #+#             */
/*   Updated: 2024/11/20 11:43:01 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locate character in string
// SI PUO' USARE MEMCHR E CAST A CHAR*
char	*ft_strchr(const char *s, int n)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)n)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)n)
		return ((char *)s);
	return (NULL);
}

/* int	main(void)
{
	char *s = ft_strchr("Hello World", ' ');
	printf("%s", s);
} */
