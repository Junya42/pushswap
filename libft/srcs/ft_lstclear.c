/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 01:50:33 by anremiki          #+#    #+#             */
/*   Updated: 2021/09/25 01:53:00 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
