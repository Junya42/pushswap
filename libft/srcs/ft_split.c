/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:03:10 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/22 22:50:55 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_haystack(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int	ft_get_size(char const *s, char c)
{
	int	size;

	size = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (!ft_haystack(*s, c))
		{
			size++;
			while (*s && !ft_haystack(*s, c))
				s++;
		}
		else
			s++;
	}
	return (size);
}

void	ft_memorycpy(char *memory, char const *s, char *res)
{
	while (memory < s)
		*(res++) = *(memory++);
	*res = '\0';
}

char	**ft_secure(char const *s, char c, char **res, char *memory)
{
	int	i;

	i = 1;
	res[0] = (char *)malloc(sizeof(char) * 2);
	res[0][0] = 'v';
	res[0][1] = '\0';
	while (*s)
	{
		if (!ft_haystack(*s, c))
		{
			memory = (char *)s;
			while (*s && !ft_haystack(*s, c))
				s++;
			res[i] = (char *)malloc(sizeof(char) * (s - memory + 1));
			if (!res[i])
				return (NULL);
			ft_memorycpy(memory, s, res[i]);
			i++;
		}
		else
			s++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*memory;

	memory = (char *)s;
	res = (char **)malloc(sizeof(char *) * (ft_get_size(s, c) + 2));
	if (!res || !s)
		return (NULL);
	return (ft_secure(s, c, res, memory));
}
