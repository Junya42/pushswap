/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:59:40 by anremiki          #+#    #+#             */
/*   Updated: 2021/10/15 19:59:40 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, int a, size_t j);
char	*ft_get_line(char *s1);
char	*ft_update_memory(char *s1, int len);
char	*ft_strchr(char *s, int c, int start);
char	*get_next_line(int fd);
char	*ft_check_eol(char *memory, int fd, int len);

#endif
