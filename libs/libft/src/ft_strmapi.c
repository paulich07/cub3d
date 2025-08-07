/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:10:11 by plichota          #+#    #+#             */
/*   Updated: 2024/12/07 17:10:12 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*new;

	i = 0;
	len = ft_strlen(s);
	new = ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
/*
char	foo(unsigned int n, char c)
{   
	return (c + 1);
}   

int main(void)
{
	char *s1 = "abc";
	char *s = ft_strmapi(s, &foo);
} */