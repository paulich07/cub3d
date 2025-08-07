/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:30:50 by plichota          #+#    #+#             */
/*   Updated: 2024/11/30 20:30:51 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	size_t	l2;
	size_t	n;
	char	*s;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	l = ft_strlen(s1);
	l2 = ft_strlen(s2);
	n = l + l2;
	s = malloc((n + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, l);
	ft_memcpy(&s[l], s2, l2);
	s[n] = '\0';
	return (s);
}
/*
int	main(void)
{
	char *s1 = NULL;
	char *s2 = "Maremma zucchinasss";
	s2 = ft_strjoin(s1, s2);
	printf("%s\n", s2);
	printf("size %ld", ft_strlen(s2));
	free(s2);
}
*/
