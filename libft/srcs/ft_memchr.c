/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:47:39 by anremiki          #+#    #+#             */
/*   Updated: 2021/10/12 04:17:34 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*ps;

	i = -1;
	ps = (char *)s;
	if ((char)c == '\0')
		return ((void *)s + ft_strlen(ps));
	while (ps[++i] && i < n)
		if (ps[i] == c)
			return ((void *)s + i);
	return (NULL);
}
