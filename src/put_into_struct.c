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
	int nb;
	int len;

	len = ft_strlen(s);
	nb = ft_atoi(s);
	flags->precision = nb;
	return (s);// + len);
}

char	*put_width(char *s, t_opt *flags)
{
	// int		nb;
	// int		len;
	// char	*str;
	// char	*tmp;
	(void)flags;
	// len = 0;
	// while (*s >= '0' && *s <= '9')
	// {
	// 	len++;
	// 	s++;
	// }
	// printf("len: %d", len);
	// tmp = ft_strnew(len);
	// str = ft_strnew(len);
	// str = ft_strncpy(tmp, s, len);
	// nb = ft_atoi(str);
	// flags->width = nb;
	// free(tmp);
	// free(str);
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
