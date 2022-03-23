/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:29:50 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/23 01:30:43 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	do_push(t_stack *a, t_stack *b, t_list *lst)
{
	if (ft_strcmp(lst->content, "pa\n") == 0)
		pa(a, b, "");
	else if (ft_strcmp(lst->content, "pb\n") == 0)
		pb(a, b, "");
	else
		return (0);
	return (1);
}

int	check_input(t_stack *a, t_stack *b)
{
	t_array	*tmp;
	t_array	*ptr;

	if (b->summit != -1)
		return (0);
	tmp = a->lst;
	while (tmp->next != a->lst)
	{
		ptr = tmp->next;
		while (ptr != a->lst)
		{
			if (tmp->value > ptr->value)
				return (0);
			ptr = ptr->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

void	print_result(int check, t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
	if (check == 0)
		ft_putstr_fd("KO\n", 1);
	else if (check == 1)
		ft_putstr_fd("OK\n", 1);
}
