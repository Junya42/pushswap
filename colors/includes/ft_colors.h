/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 01:04:23 by anremiki          #+#    #+#             */
/*   Updated: 2021/10/17 05:31:23 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLORS_H
# define FT_COLORS_H

# include <unistd.h>

void	ft_putstr(char *str);
void	bluestr(int font, char *str);
void	redstr(int font, char *str);
void	yellowstr(int font, char *str);
void	purplestr(int font, char *str);
void	resetcolor(void);

#endif
