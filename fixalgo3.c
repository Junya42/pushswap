/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixalgo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 01:50:59 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 09:49:16 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	filla(t_stack *a, t_stack *b);
int	isSemiSortedB(t_stack *b, int *cpy, int middle);

int	*createSort(t_stack *a, int index, int j, int tmp)
{
	int	*cpy;
	int	i;

	cpy = (int *)malloc(sizeof(int) * a->range);
	while (++index < a->range)
		cpy[index] = a->array[index];
	while (++j < a->range)
	{
		i = -1;
		while (++i < a->range)
		{
			if (cpy[i] > cpy[j])
			{
				tmp = cpy[i];
				cpy[i] = cpy[j];
				cpy[j] = tmp;
			}
		}
	}
	return (cpy);
}

int	hightestValue(t_stack *b)
{
	int	i;
	int	j;
	int	ret;

	i = b->array[b->summit];
	j = b->summit;
	while (j--)
	{
		if (b->array[j] >= i)
		{
			i = b->array[j];
			ret = j;
		}
	}
	return (ret);
}

int	getMiddle(int *cpy, int len, int lastMiddle)
{
	lastMiddle = len / 2;
	return  (cpy[lastMiddle]);
}

int	lowestValue(t_stack *a, int b)
{
	int	i;
	int	x;

	i = -1;
	x = hightestValue(a);
	while (++i <= a->summit)
		if (a->array[i] < a->array[x] && a->array[i] > b)
			x = i;
	return (x);
}

int	count_moves(t_stack *a, t_stack *b, int i, int low)
{
	if (low < a->summit / 2 && i < b->summit / 2)
		return (low + 1 + i + 1);
	if (low < a->summit / 2 && i >= b->summit / 2)
		return (low + 1 + b->summit - i);
	if (low >= a->summit && i < b->summit / 2)
		return (a->summit - low + i + 1);
	return (a->summit - low + b->summit - i);
}

void	best_moves(t_stack *a, t_stack *b)
{
	int	i;
	int	low;
	int	tmp;
	int	best;

	i = b->summit;
	//printf("b summit = %d\n", b->summit);
	best = 500;
	while(i > -1)
	{
		low = lowestValue(a, b->array[i]);
		tmp = count_moves(a, b, i, low);
		if (tmp <= best)
		{
			best = tmp;
			a->border = low;
			//printf("low = %d -> a->array[low] = %d\n", low ,a->array[low]);
			//printf("nombre de coup = %d\n", tmp);
			//printf("a->array[%d] = %d\n", low, a->array[low]);
			//printf("---> b->array[%d] = %d\n", i, b->array[i]);
			b->border = i;
		}
		i--;
	}
}

void	move_a(t_stack *a, t_stack *b)
{
	int	alpha;

	alpha = b->count;
	while (a->array[a->summit] != alpha)
	{
		if (a->border >= a->summit / 2)
			ra(a, b, "ra\n");
		else
			rra(a, b, "rra\n");
	}
}

void	move_b(t_stack *a, t_stack *b)
{
	int	beta = b->array[b->border];
	int alpha = a->array[a->border];

	b->count = alpha;
	while (b->array[b->summit] != beta)
	{
		if (a->array[a->summit] != alpha)
		{
			if (a->border < a->summit / 2 && b->border < b->summit / 2)
				rrr(a, b, "rrr\n");
			else if (b->border < b->summit / 2)
				rrb(a, b, "rrb\n");
			else if (a->border >= a->summit / 2 && b->border >= b->summit / 2)
				rr(a, b, "rr\n");
			else
				rb(a, b, "rb\n");	
		}
		else
		{
			if (b->border < b->summit / 2)
				rrb(a, b, "rrb\n");
			else
				rb(a, b, "rb\n");
		}
	}
}

void	init_moves(t_stack *a, t_stack *b)
{
	move_b(a, b);
	move_a(a, b);
	pa(a, b, "pa\n");
}

int	break_start(t_stack *b, int median)
{
	int	i;

	i = b->summit;
	while (i > -1)
	{
		if (b->array[i] > median)
			return (0);
		i--;
	}
	return (1);
}

int	ascending_check(t_stack *a)	
{
	int	i;

	i = a->summit - 1;
	while (i > -1)
	{
		if (a->array[i + 1] > a->array[i])
			return (0);
		i--;
	}
	return (1);
}

void	start_b(t_stack *a, t_stack *b, int *cpy)
{
	int	high;
	int	median;

	median = getMiddle(cpy, a->range, 0);
	high = a->array[hightestValue(a)];
	while (a->summit != 0)
	{
		if (a->summit > 0)
			if (ascending_check(a))
				return ;
		if (!break_start(b, median))
			if (a->array[a->summit] == high && b->array[b->summit] <= median)
				rr(a, b, "rr\n");
		if (a->array[a->summit] == high)
			ra(a, b, "ra\n");
		pb(a, b, "pb\n");
		if (!break_start(b, median))
			if (b->array[b->summit] <= median)
				rb(a, b, "rb\n");
	}
	pa(a, b, "pa\n");
}

void	algo(t_stack *a, t_stack *b, int *cpy)
{
	int	rotate;
	int	highvalue;

	start_b(a, b, cpy);
	//print_stack(a , b, "hello");
	while (b->summit > -1)
	{
		best_moves(a, b);
		init_moves(a, b);
		//print_stack(a, b, "clear b");
	}
	rotate = hightestValue(a);
	//print_stack(a, b, "moves");
	highvalue = a->array[hightestValue(a)];
	while (a->array[a->summit] != highvalue)
	{
		if (rotate < a->summit / 2)
			rra(a, b, "rra\n");
		else
			ra(a, b, "ra\n");
	}
//	print_stack(a, b, "final rotate");
}
