/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:55:16 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 02:05:17 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_stack *stacka, t_stack *stackb, char *str)
{
	int	tmp;
	int	top;

	(void)stackb;
	if (stacka->summit < 1)
		return ;
	tmp = stacka->array[stacka->summit];
	top = stacka->summit + 1;
	while (--top)
		stacka->array[top] = stacka->array[top - 1];
	stacka->array[0] = tmp;
	stacka->count++;
	if (str)
		ft_putstr(str);
//	return (print_stack(stacka, stackb, "Rotate Alpha"));
}

void	rb(t_stack *stacka, t_stack *stackb, char *str)
{
	int	tmp;
	int	top;

	(void)stacka;
	if (stackb->summit < 1)
		return ;
	tmp = stackb->array[stackb->summit];
	top = stackb->summit + 1;
	while (--top)
		stackb->array[top] = stackb->array[top - 1];
	stackb->array[0] = tmp;
	stacka->count++;
	if (str)
		ft_putstr(str);
//	return (print_stack(stacka, stackb, "Rotate Beta"));
}

void	rr(t_stack *alpha, t_stack *beta, char *str)
{
	ra(alpha, beta, NULL);
	rb(alpha, beta, NULL);
	if (str)
		ft_putstr(str);
	alpha->count--;
}
