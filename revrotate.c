/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:56:08 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/14 01:32:03 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_stack *stacka, t_stack *stackb, char *str)
{
	t_array	*a;

	if (str)
		ft_putstr(str);
	(void)stackb;
	a = stacka->lst;
	a = a->prev;
	stacka->lst = a;
	stacka->count++;
}

void	rrb(t_stack *stacka, t_stack *stackb, char *str)
{
	t_array	*b;

	if (str)
		ft_putstr(str);
	b = stackb->lst;
	b = b->prev;
	stackb->lst = b;
	stacka->count++;
}

void	rrr(t_stack *alpha, t_stack *beta, char *str)
{
	if (str)
		ft_putstr(str);
	rra(alpha, beta, NULL);
	rrb(alpha, beta, NULL);
	alpha->count--;
}
