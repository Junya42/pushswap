/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixalgo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 01:50:59 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/14 11:58:14 by anremiki         ###   ########.fr       */
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

int	hightestIndex(t_stack *n)
{
	int	i;
	int	j;
	int	ret;
	t_array	*ptr;

	ptr = n->lst;
	i = ptr->value;
	j = 0;
	while (j <= n->summit)
	{
		if (ptr->value >= i)
		{
			i = ptr->value;
			ret = j;
		}
		ptr = ptr->next;
		j++;
	}
	return (ret);
}

int	hightestValue(t_stack *n)
{
	t_array	*ptr;
	int		tmp;

	ptr = n->lst;
	tmp = ptr->value;
	while (ptr->next)
	{
		if (ptr->value >= tmp)
			tmp = ptr->value; 
		if (ptr->next == n->lst)
			break ;
		ptr = ptr->next;
	}
	return (tmp);
}

int	getMiddle(int *cpy, int len, int lastMiddle)
{
	lastMiddle = len / 2;
	return  (cpy[lastMiddle]);
}

int	lowestIndex(t_stack *a, int b)
{
	int		i;
	int		x;
	int		tmp;
	t_array	*ptr;

	i = -1;
	ptr = a->lst;
	x = hightestValue(a);
	tmp = x;
	//printf("int = %d\n", b);
	//printf("hightest value = %d\n", x);
	while (++i <= a->summit)
	{
		//printf("ptr->value = %d\n", ptr->value);
		if (ptr->value <= x && ptr->value <= tmp && ptr->value > b)
		{
			tmp = ptr->value;
			//printf("x = %d > %d found his target at array[%d] = %d\n", x, b, i, ptr->value);
			x = i;
		}
		else if (ptr->value < tmp && ptr->value > b)
		{
			tmp = ptr->value;
			//printf("x = %d > %d found a new target at array[%d] = %d\n", x, b, i, ptr->value);
			x = i;
		}
		ptr = ptr->next;
	}
	//printf("\n");
	return (x);
}

int	lowestValue(t_stack *a, int b)
{
	int		i;
	int		x;
	t_array	*ptr;

	i = -1;
	ptr = a->lst;
	x = hightestValue(a);
	while (++i <= a->summit)
	{
		if (ptr->value < x && ptr->value > b)
			x = ptr->value;
		ptr = ptr->next;
	}
	return (x);
}

int	count_moves(t_stack *a, t_stack *b, int i, int low)
{
	//printf("low = %d\n", low);
	//printf("---a->summit = %d\n", a->summit);
	//printf("------i = %d\n", i);
	//printf("---------b->summit = %d\n", b->summit);
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

void	best_moves(t_stack *a, t_stack *b)
{
	int		i;
	int		low;
	int		tmp;
	int		best;
	t_array	*ptr;

	ptr = b->lst;
	i = -1;
	//printf("b summit = %d\n", b->summit);
	best = 500;
	while(++i <= b->summit)
	{
		low = lowestIndex(a, ptr->value);
		tmp = count_moves(a, b, i, low);
		//printf("------count_moves = %d\n\n", tmp);
		if (tmp <= best)
		{
			//printf("tmp <= best : %d <= %d\n", tmp, best);
			best = tmp;
			a->border = low;
			a->value = get_alpha_value(a, low);
			//printf("a->value = %d\n", a->value);
			/*printf("low = %d -> a->array[low] = %d\n", low , lowestValue(a, ptr->value));
			printf("nombre de coup = %d\n", tmp);
			printf("a->array[%d] = %d\n", low, lowestValue(a, ptr->value));
			printf("---> b->array[%d] = %d\n", i, ptr->value);*/
			b->border = i;
			b->value = ptr->value;
			//printf("b->value = %d\n\n", b->value);
		}
		ptr = ptr->next;
	}
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

void	move_b(t_stack *a, t_stack *b)
{
	int	beta = b->value;
	int alpha = a->value;

	b->count = alpha;
	//printf("B = current value of *blst = %d >>> target is = %d\n", b->lst->value, beta);
	//printf("A = current value of *alst = %d >>> target is = %d\n", a->lst->value, alpha);
	//printf("a->border = %d\n", a->border);
	//printf("b->border = %d\n", b->border);
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
	move_b(a, b);
	//print_stack(a, b, "move b");
	move_a(a, b);
	pa(a, b, "pa\n");
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

	median = getMiddle(cpy, a->range, 0);
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

	//print_stack(a , b, "hello");
	start_b(a, b, cpy);
//	print_stack(a , b, "start_b");
	while (b->summit > -1)
	{
		best_moves(a, b);
		init_moves(a, b);
	//	print_stack(a , b, "init moves");
	}
	//print_stack(a, b, "moves");
	highvalue = hightestValue(a);
	rotate = hightestIndex(a);
	alst = lst_last(a->lst);
	//printf("alst value = %d >>> highvalue = %d\n", alst->value, highvalue);
	//printf("rotate = %d >>> a->summit / 2 = %d\n", rotate, a->summit / 2);
	//print_stack(a, b, "before final");
	while (alst->value != highvalue)
	{
		if (rotate < a->summit / 2)
			ra(a, b, "ra\n");
		else
			rra(a, b, "rra\n");
		alst = lst_last(a->lst);
	}
//	print_stack(a, b, "final rotate");
}
