/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:37:35 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/13 10:06:27 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	size_char(char c);
int	size_str(char *str);
int	ft_putnbrsize(int n);
int	ft_putunbrsize(unsigned int n);
int	ft_returnputx(unsigned int n, char x);
int	ft_returnaddress(unsigned long int n, char x);
int	ft_printf(const char *format, ...);

#endif
