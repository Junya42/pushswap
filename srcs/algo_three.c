/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:49:01 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/22 23:30:27 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	check_low(t_stack *a)
{
	t_array	*tmp;
	int		low;
	int		i;

	tmp = a->lst;
	low = INT_MAX;
	i = a->summit;
	while (i > -1)
	{
		if (tmp->value <= low)
			low = tmp->value;
		tmp = tmp->next;
		i--;
	}
	return (low);
}

int	check_high(t_stack *a)
{
	t_array	*tmp;
	int		high;
	int		i;

	tmp = a->lst;
	high = INT_MIN;
	i = a->summit;
	while (i > -1)
	{
		if (tmp->value >= high)
			high = tmp->value;
		tmp = tmp->next;
		i--;
	}
	return (high);
}

void	algo_three(t_stack *a, t_stack *b)
{
	t_array	*ptr;

	ptr = a->lst->next;
	ptr = ptr->next;
	if (a->lst->value == check_low(a) && ptr->value == check_high(a))
		return ;
	else if (a->lst->value == check_low(a) && ptr->value != check_high(a))
	{
		sa(a, b, "sa\n");
		ra(a, b, "ra\n");
	}
	else if (a->lst->value == check_high(a) && ptr->value == check_low(a))
	{
		sa(a, b, "sa\n");
		rra(a, b, "rra\n");
	}
	else if (a->lst->value == check_high(a) && ptr->value != check_low(a))
		ra(a, b, "ra\n");
	else if (ptr->value == check_low(a))
		rra(a, b, "rra\n");
	else if (ptr->value == check_high(a))
		sa(a, b, "sa\n");
}
