/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:58:50 by plichota          #+#    #+#             */
/*   Updated: 2024/12/07 23:58:51 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*p;

	count = 0;
	p = lst;
	if (lst == NULL)
		return (0);
	count++;
	while (p->next != NULL)
	{
		count++;
		p = p->next;
	}
	return (count);
}
