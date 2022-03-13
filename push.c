/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:53:49 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 10:14:24 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_stack *a, t_stack *b, char *str)
{
	if (b->summit < 0)
		return ;
	a->array[++a->summit] = b->array[b->summit--];
	a->count++;
	ft_putstr(str);
//	return (print_stack(a, b, "Push Alpha"));
}

void	pb(t_stack *a, t_stack *b, char *str)
{
	if (a->summit < 0)
		return ;
	b->array[++b->summit] = a->array[a->summit--];
	a->count++;
	ft_putstr(str);
//	return (print_stack(a, b, "Push Beta"));
}
