/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 01:00:13 by anremiki          #+#    #+#             */
/*   Updated: 2021/10/18 05:08:53 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colors.h"

void	resetcolor(void)
{
	ft_putstr("\033[0m");
}

void	redstr(int font, char *str)
{
	if (!font)
		ft_putstr("\033[1;31m");
	else
		ft_putstr("\033[1;41m");
	ft_putstr(str);
	resetcolor();
}

void	purplestr(int font, char *str)
{
	if (!font)
		ft_putstr("\033[1;35m");
	else
		ft_putstr("\033[1;45m");
	ft_putstr(str);
	resetcolor();
}

void	bluestr(int font, char *str)
{
	if (!font)
		ft_putstr("\033[1;32m");
	else
		ft_putstr("\033[1;42m");
	ft_putstr(str);
	resetcolor();
}

void	yellowstr(int font, char *str)
{
	if (!font)
		ft_putstr("\033[1;33m");
	else
		ft_putstr("\033[1;43m");
	ft_putstr(str);
	resetcolor();
}
