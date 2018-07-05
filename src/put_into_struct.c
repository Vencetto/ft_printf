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

char	*put_precision(char *s, t_opt *flags)
{
	int		len;
	char	*pos;

	len = 0;
	pos = s;
	// printf("precision s: %s\n", s);
	while (ft_isdigit(*s) && s++)
		len++;
	flags->precision = ft_atoi(pos);
	// printf("len: %d, nb: %d, flags->precision: %d\n", len, nb, flags->precision);
	return (s);
}

char	*put_width(char *s, t_opt *flags)
{
	int		nb;
	int		len;
	char	*tmp;
	char	*pos;

	len = 0;
	pos = s;
	// printf("1 width s: %s\n", s);
	while (ft_isdigit(*s) && s++)
		len++;
	// printf("len: %d\n", len);
	// printf("2 width s: %s\n", s);
	tmp = ft_strnew(len);
	ft_strncpy(tmp, pos, len);
	nb = ft_atoi(tmp);
	flags->width = nb;
	// printf("tmp: %s, nb: %d, flags->width: %d\n", tmp, nb, flags->width);
	ft_strdel(&tmp);
	return (s);
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
