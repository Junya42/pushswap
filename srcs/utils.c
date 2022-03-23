/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:57:06 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/23 02:20:27 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	fill_stack(t_stack *a, t_stack *b, int *filler, char **av)
{
	a->lst = init_array(a->range, av);
	b->lst = NULL;
	while (++a->summit < a->range)
		a->array[a->summit] = filler[a->summit];
	a->summit--;
}

t_stack	*init_s(int ac)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->summit = -1;
	tmp->range = ac;
	tmp->count = 0;
	tmp->border = 0;
	tmp->lst = NULL;
	tmp->array = (int *)malloc(sizeof(int) * tmp->range);
	return (tmp);
}

t_array	*init_array(int ac, char **av)
{
	int		i;
	t_array	*tmp;

	i = ac - 1;
	tmp = NULL;
	while (i > -1)
	{
		lstadd_new(&tmp, ft_atoi(av[i + 1]));
		i--;
	}
	return (tmp);
}
