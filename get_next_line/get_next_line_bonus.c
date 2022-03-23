/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 03:25:17 by anremiki          #+#    #+#             */
/*   Updated: 2021/10/12 02:58:28 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*memory[4097];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory[fd] = ft_check_eol(memory[fd], fd, ft_strlen(memory[fd]));
	if (!memory[fd])
	{
		free(memory[fd]);
		return (NULL);
	}
	line = ft_get_line(memory[fd]);
	memory[fd] = ft_update_memory(memory[fd], ft_strlen(memory[fd]));
	return (line);
}
