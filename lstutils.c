/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:19:09 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 11:21:14 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	lst_remove_if(t_array **lst)
{
	t_array *previous;
	t_array *current;
	t_array *ptr;

	previous = *lst;
	current = previous->next;
	ptr = previous->prev;
	current->prev = ptr;
	ptr->next = current;
	*lst = current;
	free(previous);
}

void	lstadd_front(t_array **lst, t_array *new)
{
	if (*lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
		*lst = new;
}

t_array	*lst_new(int value)
{
	t_array *new;

	new = (t_array *)malloc(sizeof(t_array) * 1);
	if (!new)
		return (NULL);
	new->value = value;
	new->next = 0;
	new->prev = 0;
	return (new);
}

void	lst_circular(t_array **lst)
{
	t_array	*start;
	t_array	*ptr;
	t_array	*prev;

	start = *lst;
	ptr = start;
	while (ptr->next)
	{
		prev = ptr;
		ptr = ptr->next;
		ptr->prev = prev;
	}
	ptr->next = start;
	start->prev = ptr;
}

void	lstadd_new(t_array **lst, int value)
{
	t_array	*new;

	new = lst_new(value);
	lstadd_front(lst, new);
	//lst_circular(lst);
}
