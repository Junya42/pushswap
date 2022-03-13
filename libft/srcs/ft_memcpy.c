/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:53:38 by anremiki          #+#    #+#             */
/*   Updated: 2021/10/12 04:04:19 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*s2;

	if (!dest && !src)
		return (NULL);
	d1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	i = -1;
	while (++i < n)
		d1[i] = s2[i];
	return (dest);
}
