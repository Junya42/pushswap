/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 07:05:15 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/14 03:49:35 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_avfree(int ac, char	**av)
{
	int	i;

	i = -1;
	while (++i <= ac)
		if (av[i])
			free(av[i]);
	free(av);
}

int	ft_lstfree(t_link *lst, int ac, char **av)
{
	t_link	*elem;

	if (av)
		ft_avfree(ac, av);
	if (!lst)
		return (0);
	elem = lst;
	if (elem->a)
	{
		if (elem->a->array)
			free(elem->a->array);
		lstclear(elem->a->lst, elem->a->summit);
		free(elem->a);
	}
	if (elem->b)
	{
		if (elem->b->array)
			free(elem->b->array);
		free(elem->b);
	}
	if (elem->clone)
		free(elem->clone);
	free(elem);
	//free(lst);
	return (0);
}

t_link	*ft_l(int ac, char **av, t_stack *(*fl)(int), int *(*fa)(int, char **))
{
	t_link	*tmp;
	int		*filler;

//	printf("\nac = %d\n", ac);
	tmp = (t_link *)malloc(sizeof(t_link));
	if (!tmp)
		return (NULL);
	tmp->a = (*fl)(ac);
	tmp->b = (*fl)(ac);
	if (!tmp->a || !tmp->b)
		return (NULL);
	filler = (*fa)(ac, av);
	if (!filler)
	{
		free(filler);
		return (NULL);
	}
	fill_stack(tmp->a, tmp->b, filler, av);
	free(filler);
	tmp->clone = createSort(tmp->a, -1, -1, 0);
	if (!tmp->clone)
		return (NULL);
	return (tmp);
}
