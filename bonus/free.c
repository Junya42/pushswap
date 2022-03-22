/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 01:26:20 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/22 22:58:12 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	free_a(t_stack *a)
{
	free(a->array);
	return (0);
}

int	free_ab(t_stack *a, t_stack *b)
{
	free(a->array);
	free(b->array);
	return (0);
}

int	free_abc(t_stack *a, t_stack *b, int *tmp)
{
	free(a->array);
	free(b->array);
	free(tmp);
	return (0);
}

int	free_all(int *cpy, int *tmp, t_stack *a, t_stack *b)
{
	ft_putnbr(a->count);
	free(cpy);
	free(tmp);
	free(a->array);
	free(b->array);
	return (1);
}

int	free_avsplit(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
		free(av[i]);
	free(av);
	return (1);
}
