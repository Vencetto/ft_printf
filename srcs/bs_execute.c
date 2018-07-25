/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:41:38 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/24 14:41:39 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_unistrwrite(wchar_t *str, int count)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] && count > 0)
	{
		len += put_wchar(str[i]);
		count--;
		i++;
	}
	return (len);
}

int		bs_minus_2(wchar_t *str, t_opt *flags)
{
	int len;

	len = 0;
	if (flags->minus)
	{
		len = ft_unistrwrite(str, flags->precision);
		len += ft_loop(flags->width - len, ' ');
	}
	else
	{
		len = ft_loop(flags->width - flags->precision, ' ');
		len += ft_unistrwrite(str, flags->precision);
	}
	return (len);
}

int		bs_minus(wchar_t *str, t_opt *flags)
{
	int len;

	len = 0;
	if (flags->minus)
	{
		ft_putunistr(str);
		len = ft_unistrlen(str);
		len += ft_loop(flags->width - (int)ft_unistrlen(str), ' ');
	}
	else
	{
		len = ft_loop(flags->width - (int)ft_unistrlen(str), ' ');
		ft_putunistr(str);
		len += ft_unistrlen(str);
	}
	return (len);
}

int		bs_executor_2(wchar_t *str, t_opt *flags)
{
	int len;

	len = 0;
	if (flags->precision && !flags->width)
	{
		len = ft_unistrwrite(str, flags->precision);
		return (len);
	}
	else if (flags->precision && flags->width)
	{
		if (flags->width > (int)ft_unistrlen(str))
			return ((len += bs_minus_2(str, flags)));
		len = ft_unistrwrite(str, flags->precision);
		return (len);
	}
	else
		ft_putunistr(str);
	return (ft_unistrlen(str));
}

int		bs_executor(t_opt *flags, va_list ap)
{
	int		len;
	wchar_t	*str;

	len = 0;
	str = va_arg(ap, wchar_t *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else if (ft_unistrlen(str) == 0)
	{
		if (flags->width)
			len = ft_loop(flags->width, ' ');
		return (len);
	}
	else if (flags->width && !flags->precision)
	{
		if (flags->width > (int)ft_unistrlen(str))
			return ((len = bs_minus(str, flags)));
		len = ft_putunistr(str);
		return (len);
	}
	len = bs_executor_2(str, flags);
	return (len);
}