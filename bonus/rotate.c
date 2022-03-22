/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:55:16 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/22 23:39:44 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ra(t_stack *stacka, t_stack *stackb, char *str)
{
	t_array	*a;

	if (str)
		ft_putstr(str);
	(void)stackb;
	a = stacka->lst;
	a = a->next;
	stacka->lst = a;
	stacka->count++;
}

void	rb(t_stack *stacka, t_stack *stackb, char *str)
{
	t_array	*b;

	if (str)
		ft_putstr(str);
	b = stackb->lst;
	b = b->next;
	stackb->lst = b;
	stacka->count++;
}

void	rr(t_stack *alpha, t_stack *beta, char *str)
{
	if (str)
		ft_putstr(str);
	ra(alpha, beta, NULL);
	rb(alpha, beta, NULL);
	alpha->count--;
}
