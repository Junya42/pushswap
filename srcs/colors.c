/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 01:00:13 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/22 20:38:28 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	bluenbr(int nb)
{
	ft_putstr("\033[1;32m");
	ft_putnbr(nb);
	ft_putstr("\033[0m");
}

void	redstr(int bg, char *str)
{
	if (!bg)
		ft_putstr("\033[1;31m");
	else
		ft_putstr("\033[1;41m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void	purplestr(int bg, char *str)
{
	if (!bg)
		ft_putstr("\033[1;35m");
	else
		ft_putstr("\033[1;45m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void	bluestr(int bg, char *str)
{
	if (!bg)
		ft_putstr("\033[1;32m");
	else
		ft_putstr("\033[1;42m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void	yellowstr(int bg, char *str)
{
	if (!bg)
		ft_putstr("\033[1;33m");
	else
		ft_putstr("\033[1;43m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}
