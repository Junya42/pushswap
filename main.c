/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:53:12 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/14 12:27:08 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_sort(int ac, char **av)
{
	int	ptr;
	int	current;

	while (--ac > 0)
	{
		current = ft_atoi(av[ac]);
		ptr = ac;
		while (--ptr > -1)
			if (current < ft_atoi(av[ptr]))
				return (0);
	}
	return (1);
}

int	ft_parse_av(int ac, char **av)
{
	int		i;
	long	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][0] != '+' || av[i][0] != '-')
					|| (av[i][0] < '0' || av[i][0] > '9'))
				return (write(2, "Error\n", 6));
			if (j)
				if ((av[i][j] < '0' || av[i][j] > '9') || av[i][j] != 32)
					return (write(2, "Error\n", 6));
		}
		j = i;
		while (++j < ac)
			if (ft_atoi(av[i] == ft_atoi(av[j])))
				return (write(2, "Error\n", 6));
		j = ft_atoi(av[i]);
		if (j < INT_MIN || j > INT_MAX)
			return (write(2, "Error\n", 6));
	}
	return (check_sort(ac, av));
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
			if (ft_parse_av(ac_size, av_split))
				return (0);
			link = ft_l(ac_size, av_split, init_s, init_a);
		}
		else
		{
			if (ft_parse_av(ac, av))
				return (0);
			link = ft_l(ac - 1, av, init_s, init_a);
		}
		algo(link->a, link->b, link->clone);
		return (ft_lstfree(link, ac_size, av_split));
	}
	return (0);
}
