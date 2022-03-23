/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:11:36 by anremiki          #+#    #+#             */
/*   Updated: 2021/10/15 19:59:17 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_check_eol(char *memory, int fd, int len)
{
	char	*buffer;
	int		eob;
	int		a;

	eob = 1;
	a = 0;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(memory, '\n', (a - eob)) && eob)
	{
		eob = read(fd, buffer, BUFFER_SIZE);
		if (eob == -1)
		{
			free(buffer);
			return (NULL);
		}
		a += eob;
		buffer[eob] = '\0';
		memory = ft_strjoin(memory, buffer, (len + a), -1);
	}
	free(buffer);
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory = ft_check_eol(memory, fd, ft_strlen(memory));
	if (!memory)
	{
		free(memory);
		return (NULL);
	}
	line = ft_get_line(memory);
	memory = ft_update_memory(memory, ft_strlen(memory));
	return (line);
}
