/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_into_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:11:28 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/15 17:11:31 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_flags(char c, t_opt *flags)
{
	if (c == ' ')
		flags->space = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == '#')
		flags->sharp = 1;
	else if (c == '0')
		flags->zero = 1;
}

void	put_precision(int c, t_opt *flags)
{
	if (c >= '0' && c <= '9')
		flags->precision = c - '0';
}

void	put_width(int c, t_opt *flags)
{
	if (c >= '0' && c <= '9')
		flags->width = c - '0';
}

void	put_specificator(char c, t_opt *flags)
{
	flags->sp_type = c;
}

int		put_modificator(char c, char s, t_opt *flags)
{
	if (c == 'h')
	{
		if (s == 'h')
		{
			flags->modif = 'H';
			return (1);
		}
		else
			flags->modif = 'h';
	}
	else if (c == 'l')
	{
		if (s == 'l')
		{
			flags->modif = 'L';
			return (1);
		}
		else
			flags->modif = 'l';
	}
	else if (c == 'j')
		flags->modif = 'j';
	else if (c == 'z')
		flags->modif = 'z';
	return (0);
}
