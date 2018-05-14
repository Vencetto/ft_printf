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
	int			precision;
	char		sp_type; // ти специфікатора
}				t_opt;

int		ft_printf(const char *format, ...);
int		checking(char *str);
void	search_for_flags(char *s, t_opt *flags);
int		parser(va_list ap, char *str);
void	set_all_zero(t_opt *flags);
void	put_flags(char c, t_opt *flags);
void	put_precision(int c, t_opt *flags);

void	show_structure(t_opt *flags);
#endif