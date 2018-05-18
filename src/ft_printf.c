/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:46:26 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/03 13:46:28 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		checking(char *str)
{
	if (ft_strchr((const char *)str, '%'))
		return (0);
	else
		write(1, str, ft_strlen(str));
	return (1);
}

void	set_all_zero(t_opt *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->sharp = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->sp_type = '0';
}

int		search_for_flags(char *s, t_opt *flags)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == ' ' || *s == '-' || *s == '+' || *s == '#' || *s == '0')
			put_flags(*s, flags);
		if (*s == '.')
		{
			put_precision(*(s + 1), flags);
			put_width(*(s - 1), flags);
		}
		if (*s == 'h' | *s == 'l' || *s == 'j' || *s == 'z')
			(put_modificator(*s, *(s + 1), flags) ? (s++ && i++) : 0);
		if (*s == 's' || *s == 'S' || *s == 'p' || *s == 'd' || *s == 'D' ||
			*s == 'i' || *s == 'o' || *s == 'O' || *s == 'u' || *s == 'U' ||
			*s == 'x' || *s == 'X' || *s == 'c' || *s == 'C')
		{
			put_specificator(*s, flags);
			return (i + 1);
		}
		s++;
		i++;
	}
	return (i);
}

int		parser(va_list ap, char *str)
{
	t_opt	flags;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
			{
				write(1, "%", 1);
				i += 2;
			}
			else
			{
				set_all_zero(&flags);
				i += search_for_flags(&str[i + 1], &flags);
				executor(&flags, ap);
			}
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	show_structure(&flags);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	if (format)
	{
		if (checking((char *)format))
			return (ft_strlen(format));
		else
		{
			va_start(ap, format);
			res = parser(ap, (char *)format);
			va_end(ap);
		}
	}
	return (0);
}
