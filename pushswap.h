/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:02:31 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/14 02:40:52 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "./libft/includes/libft.h"
# include "./ft_printf/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*	Struct of our stacks a && b
 *	summit represents the top index reachable in our array
 *	range represents the max capacity of our array
 *
 *	count in a -> total of operations done
 *			 b -> which algo to uses depending on chunks
 *
 *	border represents the previous chunk borders
 *	array stores our numbers waiting to get sorted	*/

typedef	struct	s_array
{
	struct s_array	*next;
	struct s_array	*prev;
	int		value;
}			t_array;

typedef struct	s_stack
{
	int			summit;
	int			range;
	int			count;
	int			border;
	int			value;
	t_array		*lst;
	int			*array;
}				t_stack;

/*	Our double linked list to avoid declaring too many variables at once */
typedef	struct	s_link
{
	t_stack		*a;
	t_stack		*b;
	int			*clone;
}				t_link;

/*	Lst functions	*/
void	lstadd_new(t_array **lst, int value);
void	lst_remove_if(t_array **lst);
t_array	*lst_last(t_array *lst);

/*	Random array generator	used for testing	*/
int		*randomgen(int a);
int		*randomneg(int a);

/*	Colorized putnbr && putstr	*/
void	bluenbr(int nb);
void	redstr(int bg, char *str);
void	purplestr(int bg, char *str);
void	bluestr(int bg, char *str);
void	yellowstr(int bg, char *str);

/*	Functions to initialize and print our stacks	*/
void	fill_stack(t_stack *a, t_stack *b, int *filler, char **av);
t_stack	*init_s(int ac);
int		*createSort(t_stack *a, int index, int j, int tmp);
void	print_cpy(int *cpy, t_stack *a);
void	print_stack(t_stack *s1, t_stack *s2, char *str);
t_array	*init_array(int ac, char **av);
int		*init_a(int ac, char **av);

/*	Free / return in case of mem alloc error	*/
int		free_a(t_stack *a);
int		free_ab(t_stack *a, t_stack *b);
int		free_abc(t_stack *a, t_stack *b, int *tmp);
int		free_all(int *cpy, int *tmp, t_stack *a, t_stack *b);

/*	Pushswap commands 	*/
void	pa(t_stack *a, t_stack *b, char *str);
void	pb(t_stack *a, t_stack *b, char *str);
void	ra(t_stack *a, t_stack *b, char *str);
void	rb(t_stack *a, t_stack *b, char *str);
void	rr(t_stack *a, t_stack *b, char *str);
void	rra(t_stack *a, t_stack *b, char *str);
void	rrb(t_stack *a, t_stack *b, char *str);
void	rrr(t_stack *a, t_stack *b, char *str);
void	sa(t_stack *a, t_stack *b, char *str);
void	sb(t_stack *a, t_stack *b, char *str);
void	ss(t_stack *a, t_stack *b, char *str);

/*	main commands	*/
t_link	*ft_l(int ac, char **av, t_stack *(*fl)(int), int *(*fa)(int, char **));
int		ft_lstfree(t_link *lst, int ac, char **av);
int		a_c(int ac, char *av);

/*	Algo functions
 *		Create && isSorted mainly used for testing purpose	*/
int		*create_clone(t_stack *a, int index, int j, int tmp);
int		isSorted(t_stack *a, int *cpy);
void	algo(t_stack *a, t_stack *b, int *cpy);

#endif
