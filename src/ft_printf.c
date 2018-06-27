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

char	*search_helper(char *s, t_opt *flags)
{
	while (s)
	{
		if (*s >= '0' && *s <= '9')
			s = put_width(s, flags);
		else if (*s == '.')
			s = put_precision(s + 1, flags);
		if (!(*(s + 1) >= '0' && *(s + 1) <= '9'))
			return (s);
		s++;
	}
	return (s);
}

char	*search_for_flags(char *s, t_opt *flags)
{
	while (s)
	{
		if (*s == ' ' || *s == '-' || *s == '+' || *s == '#' || *s == '0')
			put_flags(*s, flags);
		else if (*s == '.' || (*s >= '0' && *s <= '9'))
			s = search_helper(s, flags);
		else if (*s == 'h' | *s == 'l' || *s == 'j' || *s == 'z')
			(put_modificator(*s, *(s + 1), flags) ? s++ : 0);
		else if (*s == 's' || *s == 'S' || *s == 'p' || *s == 'd' || *s == 'D' ||
			*s == 'i' || *s == 'o' || *s == 'O' || *s == 'u' || *s == 'U' ||
			*s == 'x' || *s == 'X' || *s == 'c' || *s == 'C')
		{
			flags->sp_type = *s;
			return (s + 1);
		}
		s++;
	}
	return (s);
}

int		parser(va_list ap, char *str)
{
	t_opt	flags;
	int		i;

	(void)ap;
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == '%')
			{
				write(1, "%", 1);
				str = str + 2;
				i++;
			}
			else
			{
				set_all_zero(&flags);
				str = search_for_flags(str + 1, &flags);
				// executor(&flags, ap);
			}
		}
		else
		{
			write(1, str, 1);
			i++;
		}
		str++;
	}
	show_structure(&flags);
	return (i);
}

int		checking(char *str)
{
	if (ft_strchr((const char *)str, '%'))
		return (0);
	else
		write(1, str, ft_strlen(str));
	return (1);
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
