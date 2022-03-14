/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:53:49 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 23:15:02 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_stack *a, t_stack *b, char *str)
{
	t_array	*alpha;
	t_array	*beta;

	if (b->summit < 0)
		return ;
	ft_putstr(str);
	alpha = a->lst;
	beta = b->lst;
	lstadd_new(&alpha, beta->value);
	a->lst = alpha;
	lst_remove_if(&beta);
	b->lst = beta;
	a->summit++;
	b->summit--;
	a->count++;
}

void	pb(t_stack *a, t_stack *b, char *str)
{
	t_array	*alpha;
	t_array	*beta;

	if (a->summit < 0)
		return ;
	ft_putstr(str);
	alpha = a->lst;
	beta = b->lst;
	lstadd_new(&beta, alpha->value);
	b->lst = beta;
	lst_remove_if(&alpha);
	a->lst = alpha;
	b->summit++;
	a->summit--;
	a->count++;
}
