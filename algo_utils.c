/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 07:11:38 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/15 07:14:15 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
	while (++i <= a->summit)
	{
		if (ptr->value <= x && ptr->value <= tmp && ptr->value > b)
		{
			tmp = ptr->value;
			x = i;
		}
		else if (ptr->value < tmp && ptr->value > b)
		{
			tmp = ptr->value;
			x = i;
		}
		ptr = ptr->next;
	}
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
