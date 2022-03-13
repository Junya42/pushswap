/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:53:12 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 03:22:54 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_parse_av(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][0] != '+' || av[i][0] != '-')
					|| (av[i][0] < '0' || av[i][0] > '9'))
				return (0);
			if (j)
				if ((av[i][j] < '0' || av[i][j] > '9') || av[i][j] != 32)
					return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_link	*link;
	char	**av_split;
	int		ac_size;

	av_split = NULL;
	ac_size = ac;
	if (ac == 2)
		ac_size = a_c(ac - 1, av[1]);
	if (ac > 1)
	{
		if (ac == 2)
		{
			av_split = ft_split(av[1], ' ');
			link = ft_l(ac_size, av_split, init_s, init_a);
		}
		else
			link = ft_l(ac - 1, av, init_s, init_a);
		algo(link->a, link->b, link->clone);
	//	printf("\n\nCOUNT = %d\n\n", link->a->count);
		return (ft_lstfree(link, ac_size, av_split));
	}
	return (0);
}
