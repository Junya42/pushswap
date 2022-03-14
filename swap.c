/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:56:33 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/14 12:09:34 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_stack *a, t_stack *b, char *str)
{
	int		tmp;
	t_array	*alst;

	(void)b;
	if (a->summit < 1)
		return ;
	alst = a->lst->next;
	tmp = a->lst->value;
	a->lst->value = alst->value;
	alst->value = tmp;
	a->count++;
	if (str)
		ft_putstr(str);
}

void	sb(t_stack *a, t_stack *b, char *str)
{
	int		tmp;
	t_array	*blst;

	(void)a;
	if (b->summit < 1)
		return ;
	blst = b->lst->next;
	tmp = b->lst->value;
	b->lst->value = blst->value;
	blst->value = tmp;
	a->count++;
	if (str)
		ft_putstr(str);
}

void	ss(t_stack *a, t_stack *b, char *str)
{
	sa(a, b, NULL);
	sb(a, b, NULL);
	if (str)
		ft_putstr(str);
	a->count--;
}
