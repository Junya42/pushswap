/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:43:19 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 11:21:41 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	count_sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int	get_av_size(char const *s, char c)
{
	int	size;

	size = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (!count_sep(*s, c))
		{
			size++;
			while (*s && !count_sep(*s, c))
				s++;
		}
		else
			s++;
	}
	return (size);
}

int	a_c(int ac, char *av)
{
	if (ac == 1)
		ac = get_av_size(av, ' ');
	return (ac);
}

int	*init_a(int ac, char **av)
{
	int	i;
	int	*tmp;
	
	i = 0;
	tmp = (int *)malloc(sizeof(int) * ac);
	if (!tmp)
		return (NULL);
	while (i < ac)
	{
		tmp[i] = ft_atoi(av[i + 1]);
		printf("%d ", tmp[i]);
		i++;
	}
	printf("\n");
	return (tmp);
}
