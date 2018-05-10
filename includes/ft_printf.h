/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:46:09 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/03 13:46:12 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "../libft/libft.h"
									#include <stdio.h>

typedef struct	s_opt
{
	int			defis;
	int			plus;
	int			space;
	int			sharp;
	int			zero;
}				t_opt;

int		ft_printf(const char *format, ...);
int		parser(va_list ap, char *str);
int		searcher(char *str, int i, va_list ap);
void	some_funk(char c, va_list ap);

#endif