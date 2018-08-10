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

	if (count < 0)
		return (0);
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
	int		len;
	char	ch;
	int		tmp;

	ch = flags->zero ? '0' : ' ';
	len = ft_strlen(str);
	tmp = flags->precision < len ? flags->precision : len;
	if (flags->minus)
	{
		len = ft_strwrite(str, flags->precision);
		len += ft_loop(flags->width - tmp, ' ');
	}
	else
	{
		len = ft_loop(flags->width - tmp, ch);
		len += ft_strwrite(str, flags->precision);
	}
	return (len);
}

int		s_minus(char *str, t_opt *flags)
{
	int		len;
	int		tmp;
	int		ch;

	ch = flags->zero ? '0' : ' ';
	len = ft_strlen(str);
	tmp = len < flags->width ? len : flags->width;
	if (flags->minus)
	{
		len = write(1, str, tmp);
		len += ft_loop(flags->width - tmp, ' ');
	}
	else
	{
		len = ft_loop(flags->width - tmp, ch);
		len += write(1, str, tmp);
	}
	return (len);
}

int		s_executor_3(char *str, t_opt *flags)
{
	int	len;
	int	tmp;
	int	f;

	len = 0;
	f = ft_strlen(str);
	tmp = flags->precision < f ? flags->precision : f;
	if (flags->precision && flags->width)
	{
		if (flags->width > tmp)
			return ((len += s_minus_2(str, flags)));
		len = ft_strwrite(str, flags->precision);
		return (len);
	}
	else
		write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int		if_catch_exept(t_opt *flags)
{
	if (flags->point && !flags->precision && flags->zero)
		return (1);
	if (flags->point && !flags->precision && flags->width)
		return (1);
	return (0);
}

int		ft_catch_exept(t_opt *flags)
{
	int	len;

	len = 0;
	if (flags->point && !flags->precision && flags->zero)
		return ((len = ft_loop(flags->width, '0')));
	if (flags->point && !flags->precision && flags->width)
		return ((len = ft_loop(flags->width, ' ')));
	return (len);
}

int		s_executor_2(char *str, t_opt *flags)
{
	int	len;
	int	tmp;
	int	f;

	len = 0;
	f = ft_strlen(str);
	tmp = flags->precision < f ? flags->precision : f;
	if (if_catch_exept(flags))
		return ((len = ft_catch_exept(flags)));
	if (flags->width && !flags->precision)
	{
		if (flags->width > tmp)
			return ((len = s_minus(str, flags)));
		len = ft_strwrite(str, flags->width);
		return (len);
	}
	if (flags->precision && !flags->width)
	{
		len = ft_strwrite(str, flags->precision);
		return (len);
	}
	len = s_executor_3(str, flags);
	return (len);
}

int		s_executor(t_opt *flags, va_list ap)
{
	int		len;
	char	*str;
	char	ch;

	len = 0;
	ch = flags->zero ? '0' : ' ';
	str = va_arg(ap, char *);
	if (str == NULL && !flags->width)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else if (ft_strlen(str) == 0)
	{
		if (flags->width)
			len = ft_loop(flags->width, ch);
		return (len);
	}
	len = s_executor_2(str, flags);
	return (len);
}