/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:23:27 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 10:03:33 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	d_size(int n, int size)
{
	if (n <= 0)
		size++;
	else
		n = -n;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	size_nbr(int n)
{
	if (n >= 0)
		n = -n;
	else
		size_char('-');
	if (n < -9)
		size_nbr(-(n / 10));
	size_char(-(n % 10) + '0');
}

int	ft_putnbrsize(int n)
{
	size_nbr(n);
	return (d_size(n, 0));
}
