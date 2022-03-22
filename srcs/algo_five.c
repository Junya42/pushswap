/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 21:02:11 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/22 23:33:23 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	push_first_two(t_stack *a, t_stack *b)
{
	if (a->lst->value == hightest_value(a))
		ra(a, b, "ra\n");
	pb(a, b, "pb\n");
	if (a->lst->value == hightest_value(a))
		ra(a, b, "ra\n");
	pb(a, b, "pb\n");
}

void	algo_five(t_stack *a, t_stack *b)
{
	t_array	*alst;
	int		high;
	int		rotate;

	push_first_two(a, b);
	algo_three(a, b);
	while (b->summit > -1)
	{
		best_moves(a, b);
		init_moves(a, b);
	}
	alst = lst_last(a->lst);
	rotate = hightest_index(a);
	high = hightest_value(a);
	while (alst->value != high)
	{
		if (rotate < a->summit / 2)
			ra(a, b, "ra\n");
		else
			rra(a, b, "rra\n");
		alst = lst_last(a->lst);
	}
}
