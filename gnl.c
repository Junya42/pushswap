/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:46:59 by anremiki          #+#    #+#             */
/*   Updated: 2022/03/14 19:05:26 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;
	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*join(char *str, char c)
{
	char	*tmp;
	int			i;

	if (!c)
		return (NULL);
	if (!str)
	{
		tmp = (char *)malloc(sizeof(char) * 1);
		if (!tmp)
			return (NULL);
		*tmp = c;
		return (tmp);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	i = -1;
	while (str[++i])
		tmp[i] = str[i];
	tmp[i++] = c;
	tmp[i] = '\0';
	return (tmp);
}

char	*gnl(int fd)
{
	char	c;
	char	*str;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (read(fd, &c, 1) > 0)
	{
		str = join(str, c);
		if (c == '\n')
			break ;
	}
	return (str);
}

int main()
{
	int fd;
	char	*ptr;
	int	i;
	
	i = 0;
	fd = open("main.c", O_RDONLY);
	if (fd < 0)
		return (write(2, "fd\n", 3));
	while (i < 50)
	{
		ptr = gnl(fd);
		printf("%s", ptr);
		if (ptr)
			free(ptr);
		i++;
	}
}
