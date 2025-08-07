/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:42:07 by plichota          #+#    #+#             */
/*   Updated: 2024/11/25 16:42:08 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	l;
	char	*s2;

	i = 0;
	l = ft_strlen(s);
	s2 = malloc((l + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (i < l)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/* int main(void)
{
	char *s = "Hello World!";
	char *s2 = ft_strdup(s);
	printf("%s", s2);
} */