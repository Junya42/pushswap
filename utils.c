/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:57:06 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 11:23:24 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fill_stack(t_stack *a, t_stack *b, int *filler, char **av)
{
//	a->lst = init_array(a->range, av);
	(void)av;
	a->lst = NULL;
	b->lst = NULL;
	while (++a->summit < a->range)
		a->array[a->summit] = filler[a->summit];
	a->summit--;
//	return (print_stack(a, b, "Initialisation"));
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
	tmp->array = (int *)malloc(sizeof(int) * tmp->range);
	return (tmp);
}

void	print_cpy(int *cpy, t_stack *a)
{
	int	x;

	x = 0;
	ft_printf("\n");
	redstr(0, "Voici le resultat qu'il faut obtenir dans votre stack a\n");
	while (x < a->range)
		ft_printf("%d ", cpy[x++]);
	ft_printf("\n\n");
	redstr(0, "Commencez a entrer les commandes lies a l'exercice\n\n");
}

void	print_stack(t_stack *a, t_stack *b, char *str)
{
	int	i;
	int	ai;
	int	bi;

	i = a->range;
	ai = a->summit;
	bi = b->summit;
	purplestr(1, str);
	ft_printf("\n ____________________\n");
	ft_printf("|a		 b|\n");
	while (--i > -1)
	{
		if (bi < i && ai < i)
			ft_printf("|  		     |\n");
		else if (ai < i)
			ft_printf("|  		   %d |\n", b->array[i]);
		else if (bi < i)
			ft_printf("| %d		     |\n", a->array[i]);
		else
			ft_printf("| %d		   %d |\n", a->array[i], b->array[i]);
	}
	ft_printf(" ____________________\n\n");
}

t_array *init_array(int ac, char **av)
{
	int		i;
	t_array	*tmp;
	
	i = ac - 1;
	tmp = NULL;
	/*tmp = (t_array *)malloc(sizeof(t_array));
	if (!tmp)
		return (NULL);*/
	while (i > -1)
	{
		lstadd_new(&tmp, ft_atoi(av[i + 1]));
		i--;
	}
	return (tmp);
}
