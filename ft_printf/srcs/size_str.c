/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 00:38:18 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 10:02:42 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (size_str("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
