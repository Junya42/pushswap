/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:56:33 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 09:55:10 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_stack *a, t_stack *b, char *str)
{
	int	tmp;

	(void)b;
	if (a->summit < 1)
		return ;
	tmp = a->array[a->summit];
	a->array[a->summit] = a->array[a->summit - 1];
	a->array[a->summit - 1] = tmp;
	a->count++;
	if (str)
		ft_putstr(str);
//	return (print_stack(a, b, "Swap a"));
}

void	sb(t_stack *a, t_stack *b, char *str)
{
	int	tmp;

	(void)a;
	if (b->summit < 1)
		return ;
	tmp = b->array[b->summit];
	b->array[b->summit] = b->array[b->summit - 1];
	b->array[b->summit - 1] = tmp;
	a->count++;
	if (str)
		ft_putstr(str);
//	return (print_stack(a, b, "Swap b"));
}

void	ss(t_stack *a, t_stack *b, char *str)
{
	sa(a, b, NULL);
	sb(a, b, NULL);
	if (str)
		ft_putstr(str);
	a->count--;
}
