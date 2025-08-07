/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:52:22 by plichota          #+#    #+#             */
/*   Updated: 2024/11/20 11:52:23 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locate last instance of character in string

char	*ft_strrchr(const char *s, int n)
{
	const char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)n)
			last = s;
		s++;
	}
	if (*s == (unsigned char)n)
		last = s;
	return ((char *)last);
}

/* int	main(void)
{
	printf("%s", ft_strrchr("Hello World Wide", 'i'));
} */
