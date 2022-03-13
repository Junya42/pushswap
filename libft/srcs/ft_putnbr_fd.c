/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 00:41:51 by anremiki          #+#    #+#             */
/*   Updated: 2021/10/14 05:05:32 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		n = -n;
	else
		ft_putchar_fd('-', fd);
	if (n < -9)
		ft_putnbr_fd(-n / 10, fd);
	ft_putchar_fd(-(n % 10) + '0', fd);
}
