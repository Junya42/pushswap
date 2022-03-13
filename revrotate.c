/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:56:08 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 02:06:09 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_stack *stacka, t_stack *stackb, char *str)
{
	int	tmp;
	int	low;

	(void)stackb;
	if (stacka->summit < 1)
		return ;
	tmp = stacka->array[0];
	low = -1;
	while (++low < stacka->summit + 1)
		stacka->array[low] = stacka->array[low + 1];
	stacka->array[low - 1] = tmp;
	stacka->count++;
	if (str)
		ft_putstr(str);
//	return (print_stack(stacka, stackb, "Rev rotate Alpha"));
}

void	rrb(t_stack *stacka, t_stack *stackb, char *str)
{
	int	tmp;
	int	low;

	(void)stacka;
	if (stackb->summit < 1)
		return ;
	tmp = stackb->array[0];
	low = -1;
	while (++low < stackb->summit + 1)
		stackb->array[low] = stackb->array[low + 1];
	stackb->array[low - 1] = tmp;
	stacka->count++;
	if (str)
		ft_putstr(str);
//	return (print_stack(stacka, stackb, "Rev rotate Beta"));
}

void	rrr(t_stack *alpha, t_stack *beta, char *str)
{
	rra(alpha, beta, NULL);
	rrb(alpha, beta, NULL);
	if (str)
		ft_putstr(str);
	alpha->count--;
}
