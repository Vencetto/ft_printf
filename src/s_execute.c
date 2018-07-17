/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:03:40 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/14 15:03:41 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_loop(int count, char ch)
{
	int len;

	len = 0;
	while (count)
	{
		write(1, &ch, 1);
		len++;
		count--;
	}
	return (len);
}

int		ft_strwrite(char *str, int count)
{
	int i;

	i = 0;
	while (str[i] && count > 0)
	{
		write(1, &str[i], 1);
		count--;
		i++;
	}
	return (i);
}

int		s_minus_2(char *str, t_opt *flags)
{
	int len;

	len = 0;
	if (flags->minus)
	{
		len = ft_strwrite(str, flags->precision);
		len += ft_loop(flags->width - len, ' ');
	}
	else
	{
		len = ft_loop(flags->width - flags->precision, ' ');
		len += ft_strwrite(str, flags->precision);
	}
	return (len);
}

int		s_minus(char *str, t_opt *flags)
{
	int len;

	len = 0;
	if (flags->minus)
	{
		write(1, str, ft_strlen(str));
		len = ft_strlen(str);
		len += ft_loop(flags->width - (int)ft_strlen(str), ' ');
	}
	else
	{
		len = ft_loop(flags->width - (int)ft_strlen(str), ' ');
		write(1, str, ft_strlen(str));
		len += ft_strlen(str);
	}
	return (len);
}

int		s_executor_2(char *str, t_opt *flags)
{
	int len;

	len = 0;
	if (flags->precision && !flags->width)
	{
		len = ft_strwrite(str, flags->precision);
		return (len);
	}
	else if (flags->precision && flags->width)
	{
		if (flags->width > (int)ft_strlen(str))
			return ((len += s_minus_2(str, flags)));
		len = ft_strwrite(str, flags->precision);
		return (len);
	}
	else
		write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int		s_executor(t_opt *flags, va_list ap)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else if (ft_strlen(str) == 0)
	{
		if (flags->width)
			len = ft_loop(flags->width, ' ');
		return (len);
	}
	else if (flags->width && !flags->precision)
	{
		if (flags->width > (int)ft_strlen(str))
			return ((len = s_minus(str, flags)));
		write(1, str, ft_strlen(str));
		return (len);
	}
	len = s_executor_2(str, flags);
	return (len);
}