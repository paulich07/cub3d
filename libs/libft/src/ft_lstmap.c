/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:29:53 by plichota          #+#    #+#             */
/*   Updated: 2024/12/08 16:29:55 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;

	head = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
/* 
void	*increment(void *content)
{
	char	*str;

	str = (char *)content;
	if (str[0])
		str[0] = 'a';
	return (content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*p;
	t_list	*new;
	void	*content;
	char	s[] = "prova  ";
	int		i;
	char	c;
	void	*d = &del;

	i = 0;
	c = (i + 48);
	s[5] = c;
	content = ft_substr(s, 0, ft_strlen(s));
	new = ft_lstnew(content);
	if (!new)
		printf("Error\n");
	i++;
	lst = new;

	while (i < 3)
	{
		c = (i + 48);
		s[5] = c;
		content = ft_substr(s, 0, ft_strlen(s));
		new = ft_lstnew(content);
		if (!new)
			printf("Error\n");
		i++;
		ft_lstadd_back(&lst, new);
	}
	// stampo lista
	p = lst;
	while(p)
	{
		printf("%s\n", (char *)p->content);
		p = p->next;
	}
	// lstmap
	ft_lstmap(lst, increment, d);
	// stampo lista
	p = lst;
	while(p)
	{
		printf("%s\n", (char *)p->content);
		p = p->next;
	}
	// cancello tutto
	ft_lstclear(&lst, d);
	// stampo lista
	p = lst;
	printf("stampo dopo clear\n");
	while(p)
	{
		printf("%s\n", (char *)p->content);
		p = p->next;
	}
	free(lst);
}
 */