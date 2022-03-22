/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:57:06 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/22 23:40:15 by anremiki         ###   ########.fr       */
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

/*void	print_stack(t_stack *a, t_stack *b, char *str)
{
	int	i;
	int	ai;
	int	bi;
	t_array	*aptr;
	t_array	*bptr;

	i = a->range;
	ai = a->summit;
	bi = b->summit;
	aptr = a->lst;
	bptr = b->lst;
	purplestr(1, str);
	ft_printf("\n ____________________\n");
	ft_printf("|a		 b|\n");
	while (--i > -1)
	{
		if (bi < 0 && ai < 0)
			ft_printf("|  		     |\n");
		else if (ai > -1 && bi > -1)
			ft_printf("| %d		   %d |\n", aptr->value, bptr->value);
		else if (bi > -1)
			ft_printf("|  		   %d |\n", bptr->value);
		else if (ai > -1)
			ft_printf("| %d		     |\n", aptr->value);
		ai--;
		if (ai > -1)
			aptr = aptr->next;
		bi--;
		if (bi > -1)
			bptr = bptr->next;
	}
	ft_printf(" ____________________\n\n");
}*/

void	print_stack(t_stack *a, t_stack *b, char *str)
{
	t_array	*alst;
	t_array	*blst;
	int		x;

	alst = a->lst;
	blst = b->lst;
	x = -1;
	purplestr(1, str);
	printf("\n\nb->summit = %d\n", b->summit);
	ft_printf("________________________\n");
	ft_printf("|a		       b|\n");
	ft_printf("| 			|\n");
	while (++x < a->range)
	{
		if (x <= a->summit && x <= b->summit)
		{
			ft_printf("|%d		       %d|\n", alst->value, blst->value);
			alst = alst->next;
			blst = blst->next;
		}
		else if (x <= a->summit)
		{
			ft_printf("|%d			|\n", alst->value);
			alst = alst->next;
		}
		else if (x <= b->summit)
		{
			ft_printf("|		       %d|\n", blst->value);
			blst = blst->next;
		}
		else
			ft_printf("|			|\n");
	}
	ft_printf("________________________\n");
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
