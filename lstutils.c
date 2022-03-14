/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:19:09 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/14 03:54:12 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


t_array	*lst_last(t_array *lst)
{
	t_array	*ptr;
	
	ptr = lst;
	while (ptr)
	{
		if (ptr->next == lst)
			return (ptr);
		ptr = ptr->next;
	}
	return (ptr);
}

void	lst_remove_if(t_array **lst)
{
	t_array *previous;
	t_array *current;
	t_array *ptr;

	previous = lst_last(*lst);
	current = *lst;
	ptr = current->next;
	previous->next = ptr;
	ptr->prev = previous;
	free(current);
	/*previous = previous->next;
	previous = ptr->prev;*/	//Valgrind invalid read, check if it still works
	*lst = ptr;
}

void	lstadd_front(t_array **lst, t_array *new)
{
	t_array *ptr;
	t_array	*head;

	head = *lst;
	ptr = lst_last(*lst);
	if (*lst)
	{
		new->next = *lst;
		new->prev = ptr;
		ptr->next = new;
		head->prev = new;
		*lst = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
		*lst = new;
	}
}

t_array	*lst_new(int value)
{
	t_array *new;

	new = (t_array *)malloc(sizeof(t_array) * 1);
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	lstadd_new(t_array **lst, int value)
{
	t_array	*new;

	new = lst_new(value);
	lstadd_front(lst, new);
}
