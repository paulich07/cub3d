/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:23:37 by plichota          #+#    #+#             */
/*   Updated: 2024/11/30 20:23:38 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	void	*new;

	if (!s)
		return (NULL);
	if (len + start >= ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	new = ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (NULL);
	if (len > 0)
		ft_memcpy(new, &s[start], (len));
	return (new);
}

/* int	main(void)
{
	char *s = "tripouille";
	// char *s2 = ft_substr(s, 3, 11);
	// printf("%s", s2);
	printf("%s", ft_substr(s, 100, 20));
	// free(s2);
} */