/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:53:12 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/23 02:20:12 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	check_sort(int ac, char **av)
{
	int	ptr;
	int	current;
	int	limit;

	limit = -1;
	if (av[0][0] == '.')
		limit = 0;
	while (--ac > 0)
	{
		current = ft_atoi(av[ac]);
		ptr = ac;
		while (--ptr > limit)
			if (current < ft_atoi(av[ptr]))
				return (0);
	}
	return (1);
}

int	check_cmp(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_parse_av(int ac, char **av, int i, long j)
{
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!check_cmp("+-0123456789", av[i][0]))
				return (write(2, "Error\n", 6));
			if (j)
				if ((av[i][j] < '0' || av[i][j] > '9'))
					return (write(2, "Error\n", 6));
			if ((av[i][0] == '-' || av[i][0] == '+') &&
					(!av[i][1] || !check_cmp("0123456789", av[i][1])))
				return (write(2, "Error\n", 6));
		}
		j = i;
		while (++j < ac)
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (write(2, "Error\n", 6));
		j = ft_atoi(av[i]);
		if (j < INT_MIN || j > INT_MAX)
			return (write(2, "Error\n", 6));
	}
	return (check_sort(ac, av));
}

void	choose_algo(t_link *link, int ac)
{
	if (ac == 2)
		sa(link->a, link->b, "sa\n");
	else if (ac == 3)
		algo_three(link->a, link->b);
	else if (ac == 5)
		algo_five(link->a, link->b);
	else
		algo(link->a, link->b, link->clone);
}

int	main(int ac, char **av)
{
	t_link	*link;
	char	**av_split;
	int		ac_size;

	av_split = NULL;
	ac_size = ac - 1;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		ac_size = a_c(ac - 1, av[1]);
		av_split = ft_split(av[1], ' ');
		if (ft_parse_av(ac_size, av_split + 1, -1, -1))
			return (free_avsplit(av_split));
		link = ft_l(ac_size, av_split, init_s, init_a);
	}
	else
	{
		if (ft_parse_av(ac, av, 0, -1))
			return (1);
		link = ft_l(ac - 1, av, init_s, init_a);
	}
	choose_algo(link, ac_size);
	return (ft_lstfree(link, ac_size, av_split));
}
