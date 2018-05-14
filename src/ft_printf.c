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
	flags->defis = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->sharp = 0;
	flags->zero = 0;
	flags->sp_type = '0';
}

void	search_for_flags(char *s, t_opt *flags)
{
	while (*s)
	{
		if (*s == ' ' || *s == '-' || *s == '+' || *s == '#' || *s == '0')
			put_flags(*s, flags);
		if (*s == '.')
			put_precision(*(s + 1), flags);
		s++;
	}
}

int		parser(va_list ap, char *str)
{
	int		i;
	t_opt	flags;
													(void)ap;
	set_all_zero(&flags);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			search_for_flags(&str[i + 1], &flags);
		}
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
