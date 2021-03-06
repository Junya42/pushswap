/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 06:20:07 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/22 20:39:21 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	colornbr(unsigned char *str, int nb)
{
	while (*str && *str != '%')
		write(1, str++, 1);
	str++;
	bluenbr(nb);
	while (*str)
		write(1, str++, 1);
}

void	classicnbr(unsigned char *str, int nb)
{
	while (*str && *str != '%')
		write(1, str++, 1);
	str++;
	ft_putnbr(nb);
	while (*str)
		write(1, str++, 1);
}
