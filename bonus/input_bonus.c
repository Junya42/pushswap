/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:57:13 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/23 02:20:02 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	ft_lstadd_mnew(t_list **alst, void *content)
{
	t_list	*new;

	if (content)
	{
		new = ft_lstmnew(content);
		if (!new)
			return ;
		ft_lstadd_back(alst, new);
	}
}

int	do_rotate(t_stack *a, t_stack *b, t_list *lst)
{
	if (ft_strcmp(lst->content, "ra\n") == 0)
		ra(a, b, "");
	else if (ft_strcmp(lst->content, "rb\n") == 0)
		rb(a, b, "");
	else if (ft_strcmp(lst->content, "rr\n") == 0)
		rr(a, b, "");
	else if (ft_strcmp(lst->content, "rra\n") == 0)
		rra(a, b, "");
	else if (ft_strcmp(lst->content, "rrb\n") == 0)
		rrb(a, b, "");
	else if (ft_strcmp(lst->content, "rrr\n") == 0)
		rrr(a, b, "");
	else
		return (0);
	return (1);
}

int	do_swap(t_stack *a, t_stack *b, t_list *lst)
{
	if (ft_strcmp(lst->content, "sa\n") == 0)
		sa(a, b, "");
	else if (ft_strcmp(lst->content, "sb\n") == 0)
		sb(a, b, "");
	else if (ft_strcmp(lst->content, "ss\n") == 0)
		ss(a, b, "");
	else
		return (0);
	return (1);
}

int	do_input(t_stack *a, t_stack *b, t_list *lst)
{
	int	checker;

	while (lst)
	{
		checker = 0;
		if (ft_strncmp(lst->content, "r", 1) == 0)
			checker = do_rotate(a, b, lst);
		else if (ft_strncmp(lst->content, "s", 1) == 0)
			checker = do_swap(a, b, lst);
		else if (ft_strncmp(lst->content, "p", 1) == 0)
			checker = do_push(a, b, lst);
		else
			checker = 0;
		if (checker == 0)
		{
			ft_putstr_fd("Error\n", 1);
			return (2);
		}
		lst = lst->next;
	}
	return (check_input(a, b));
}

void	wait_input(t_stack *a, t_stack *b)
{
	char	*checker;
	t_list	*lst;

	lst = NULL;
	checker = NULL;
	while (42)
	{
		checker = get_next_line(0);
		if (!checker)
			break ;
		if (checker)
			ft_lstadd_mnew(&lst, checker);
		free(checker);
	}
	print_result(do_input(a, b, lst), a, b);
	ft_lstclear(&lst, free);
}
