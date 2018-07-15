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
	while (str && count > 1)
	{
		write(1, str, 1);
		str++;
		count--;
		i++;
	}
	return (i);
}

int		s_executor_2(char *str, t_opt *flags)
{
	int len;

	len = 0;
	if (flags->precision && !flags->width)
	{
		write(1, str, flags->precision);
		return (flags->precision);
	}
	else if (flags->precision && flags->width)
	{
		if (flags->width > (int)ft_strlen(str))
			len = ft_loop(flags->width - (int)ft_strlen(str), ' ');
		// printf("flags->width: %d, ft_strlen(str): %zu, len: %d, flags->precision: %d\n", flags->width, ft_strlen(str), len, flags->precision);
		len += ft_strwrite(str, flags->precision);
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
		write(1, "(null)\0", 7);
		return (7);
	}
	else if (flags->width && !flags->precision)
	{
		if (flags->width > (int)ft_strlen(str))
			len = ft_loop(flags->width - (int)ft_strlen(str), ' ');
		write(1, str, ft_strlen(str));
		return (len += ft_strlen(str));
	}
	len = s_executor_2(str, flags);
	return (len);
}