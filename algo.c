/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 01:50:59 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/15 07:22:51 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		get_alpha_value(t_stack *a, int n)
{
	t_array	*ptr;
	int		index;

	ptr = a->lst;
	index = -1;
	while (++index != n)
		ptr = ptr->next;
	return (ptr->value);
}



int	break_start(t_stack *b, int median)
{
	t_array	*ptr;
	int		i;

	ptr = b->lst;
	i = b->summit;
	ptr = ptr->prev;
	while (i > -1)
	{
		if (ptr->value > median)
			return (0);
		ptr = ptr->prev;
		i--;
	}
	return (1);
}

int	ascending_check(t_stack *a)	
{
	t_array	*ptr;
	t_array	*nptr;
	int		i;

	ptr = a->lst;
	i = -1;
	while (++i <= a->summit)
	{
		nptr = ptr->next;
		if (ptr->value > nptr->value)
			return (0);
		if (ptr->next == a->lst)
			break ;
		ptr = ptr->next;
	}
	return (1);
}

void	start_b(t_stack *a, t_stack *b, int *cpy)
{
	int	high;
	int	median;

	median = cpy[a->range / 2];
	high = hightestValue(a);
	while (a->summit != 0)
	{
		if (a->summit > 0)
			if (ascending_check(a))
				return ;
		if (b->summit > 0)
			if (!break_start(b, median))
				if (a->lst->value == high && b->lst->value <= median)
					rr(a, b, "rr\n");
		if (a->lst->value == high)
			ra(a, b, "ra\n");
		pb(a, b, "pb\n");
		if (!break_start(b, median))
			if (b->lst->value <= median)
				rb(a, b, "rb\n");
	}
	pa(a, b, "pa\n");
}

void	algo(t_stack *a, t_stack *b, int *cpy)
{
	int		rotate;
	int		highvalue;
	t_array	*alst;

	start_b(a, b, cpy);
	while (b->summit > -1)
	{
		best_moves(a, b);
		init_moves(a, b);
	}
	highvalue = hightestValue(a);
	rotate = hightestIndex(a);
	alst = lst_last(a->lst);
	while (alst->value != highvalue)
	{
		if (rotate < a->summit / 2)
			ra(a, b, "ra\n");
		else
			rra(a, b, "rra\n");
		alst = lst_last(a->lst);
	}
}
