/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:01:00 by plichota          #+#    #+#             */
/*   Updated: 2024/11/19 18:01:01 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// we should return the full length of src
// regardless of how much we were able to copy
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (src[i] && i < n - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int main(void)
{
	char	dest[6] = "abcd";
	char	*src;
	unsigned int	res;

	src = "lorem ipsum dolor sit amet";
	res = ft_strlcpy(dest, src, 0);
	printf("res: %d\n", res);
	printf("a: %s\n", dest);
	printf("b: %s\n", src);
}
*/
