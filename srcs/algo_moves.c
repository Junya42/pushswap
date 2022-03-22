/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 07:16:56 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/22 23:33:54 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	best_moves(t_stack *a, t_stack *b)
{
	int		i;
	int		low;
	int		tmp;
	int		best;
	t_array	*ptr;

	ptr = b->lst;
	i = -1;
	best = 500;
	while (++i <= b->summit)
	{
		low = lowest_index(a, ptr->value);
		tmp = count_moves(a, b, i, low);
		if (tmp <= best)
		{
			best = tmp;
			a->border = low;
			a->value = get_alpha_value(a, low);
			b->border = i;
			b->value = ptr->value;
		}
		ptr = ptr->next;
	}
}

int	count_moves(t_stack *a, t_stack *b, int i, int low)
{
	if (low > a->summit)
		return (501);
	if (low <= a->summit / 2 && i <= b->summit / 2)
		return (low + i);
	if (low <= a->summit / 2 && i > b->summit / 2)
		return (low + b->summit - i + 1);
	if (low > a->summit / 2 && i <= b->summit / 2)
		return ((a->summit - low) + 1 + i);
	return (a->summit - low + b->summit - i + 2);
}

void	move_a(t_stack *a, t_stack *b)
{
	int	alpha;

	alpha = b->count;
	while (a->lst->value != alpha)
	{
		if (a->border > a->summit / 2)
			rra(a, b, "rra\n");
		else
			ra(a, b, "ra\n");
	}
}

void	move_b(t_stack *a, t_stack *b, int alpha, int beta)
{
	b->count = alpha;
	while (b->lst->value != beta)
	{
		if (a->lst->value != alpha)
		{
			if (a->border <= a->summit / 2 && b->border <= b->summit / 2)
				rr(a, b, "rr\n");
			else if (b->border <= b->summit / 2)
				rb(a, b, "rb\n");
			else if (a->border > a->summit / 2 && b->border > b->summit / 2)
				rrr(a, b, "rrr\n");
			else
				rrb(a, b, "rrb\n");
		}
		else
		{
			if (b->border < b->summit / 2)
				rb(a, b, "rb\n");
			else
				rrb(a, b, "rrb\n");
		}
	}
}

void	init_moves(t_stack *a, t_stack *b)
{
	move_b(a, b, a->value, b->value);
	move_a(a, b);
	pa(a, b, "pa\n");
}
