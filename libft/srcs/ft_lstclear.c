/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 01:50:33 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/14 03:48:54 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"
#include "libft.h"

void	lstclear(t_array *lst, int summit)
{
	t_array	*tmp;
	t_array	*elem;
	int		i;

	elem = lst;
	i = -1;
	while (++i <= summit)
	{
		tmp = elem->next;
		if (elem)
		{
			free(elem);
			elem = NULL;
		}
		elem = tmp;
	}
	lst = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*elem;

	elem = *lst;
	while (elem)
	{
		tmp = elem->next;
		(*del)(elem->content);
		free(elem);
		elem = tmp;
	}
	*lst = NULL;
}
