/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:28:18 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/16 16:28:20 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		did_executor(t_opt *flags, va_list ap)
{
	intmax_t	nb;
	int			len;

	len = 0;
	nb = take_arg_d(flags, ap);
	if (if_check_sign(flags,nb) && flags->width > flags->precision)
		flags->width--;
	if (!flags->width && !flags->precision)
		return ((len = did_0(flags, nb)));
	else if (flags->width && !flags->precision)
		return ((len = did_1(flags, nb)));
	else if (!flags->width && flags->precision)
		return ((len = did_2(flags, nb)));
	else if (flags->width && flags->precision)
		return ((len = did_3(flags, nb)));
	ft_putnbr(nb);
	len = ft_len(nb, 10);
	if (nb < 0)
		len++;
	return (len);
}

int		percent_executor(t_opt *flags)
{
	int	i;

	i = 1;
	if (flags->width)
	{
		if (flags->minus)
		{
			write(1, "%", 1);
			i += ft_loop(flags->width - 1, ' ');
			return (i);
		}
		else
			i += ft_loop(flags->width - 1, ' ');
	}
	write(1, "%", 1);
	return (i);
}

int		executor(t_opt *flags, va_list ap)
{
	int		len;

	len = 0;
	if (flags->sp_type == 'd' || flags->sp_type == 'i' ||
		flags->sp_type == 'D')
		len = did_executor(flags, ap);
	else if (flags->sp_type == 's')
		len = s_executor(flags, ap);
	else if (flags->sp_type == 'c')
		len = c_execute(flags, ap);
	else if (flags->sp_type == '%')
		len = percent_executor(flags);
	return (len);
}