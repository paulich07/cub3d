/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:10:52 by plichota          #+#    #+#             */
/*   Updated: 2024/12/02 17:10:53 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		l;
	char	*new;

	if (!s1)
		return (NULL);
	l = ft_strlen(s1);
	i = 0;
	j = l - 1;
	while (ft_strrchr(set, s1[i]))
		i++;
	while (ft_strrchr(set, s1[j]))
		j--;
	l = j - i + 1;
	new = ft_substr(s1, i, l);
	return (new);
}

/* int	main(void)
{
	char *s = "    - ciao mondo ";
	char *s1 = " ";
	char *s2 = ft_strtrim(s, s1);
	printf("%s", s2);
	free(s2);
} */