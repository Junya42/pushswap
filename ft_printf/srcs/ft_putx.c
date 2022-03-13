/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:42:36 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 10:07:34 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_xsize(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_putx(unsigned int n, char x)
{
	if (n > 15)
		ft_putx(n / 16, x);
	if ((n % 16) < 10)
		size_char((n % 16) + '0');
	else
		size_char((n % 16) + x - 33);
}

int	ft_returnputx(unsigned int n, char x)
{
	ft_putx(n, x);
	return (ft_get_xsize(n));
}
