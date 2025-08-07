/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:18:58 by plichota          #+#    #+#             */
/*   Updated: 2024/12/06 12:18:59 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char delim)
{
	int	count;
	int	new_word;

	count = 0;
	new_word = 1;
	while (*s != '\0')
	{
		if (new_word)
		{
			count++;
			new_word = 0;
		}
		if (*s == delim)
			new_word = 1;
		s++;
	}
	return (count);
}

static char	**dealloc(char **l, int i)
{
	while (i >= 0)
		free(l[--i]);
	free(l);
	return (NULL);
}

static char	**allocate_words(char **l, const char *s, char delim, int n)
{
	int	i;
	int	start;
	int	end;
	int	word_length;

	i = 0;
	start = 0;
	end = 0;
	while (i < n)
	{
		while (s[end] == delim && s[end] != '\0')
			end++;
		start = end;
		while (s[end] != delim && s[end] != '\0')
			end++;
		word_length = end - start;
		if (word_length > 0)
		{
			l[i] = ft_substr(s, start, word_length);
			if (!l[i])
				return (dealloc(l, i));
		}
		i++;
	}
	return (l);
}

char	**ft_split(const char *s, char c)
{
	int		l;
	char	**list;

	l = count_words(s, c);
	list = ft_calloc((l + 1), sizeof(char *));
	if (!list)
		return (NULL);
	list = allocate_words(list, s, c, l);
	list[l] = NULL;
	return (list);
}
/* 
int	main(void)
{
	const char *s = "  coso  42  ";
	char delim = ' ';
	char **l = ft_split(s, delim);
	int i = 0;
	while(l[i] != NULL)
	{
		printf("%s\n", l[i]);
		free(l[i]);
		i++;
	}
	free(l);
} */
