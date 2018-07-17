/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:26:55 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/15 18:26:56 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	take_arg_d(t_opt *flags, va_list ap)
{
	intmax_t	nb;

	nb = 0;
	if (!ft_strcmp(flags->modif, "h"))
		nb = (short)va_arg(ap, int);
	else if (!ft_strcmp(flags->modif, "hh"))
		nb = (signed char)va_arg(ap, int);
	else if (!ft_strcmp(flags->modif, "l"))
		nb = va_arg(ap, long);
	else if (!ft_strcmp(flags->modif, "ll"))
		nb = va_arg(ap, long long);
	else if (!ft_strcmp(flags->modif, "j"))
		nb = va_arg(ap, intmax_t);
	else if (!ft_strcmp(flags->modif, "z"))
		nb = (ptrdiff_t)va_arg(ap, size_t);
	else
		nb = va_arg(ap, int);
	return (nb);
}

int		if_check_sign(t_opt *flags, intmax_t nb)
{
	if (flags->plus)
		return (1);
	else if (flags->space)
		return (1);
	else if (nb < 0)
		return (1);
	return (0);
}

int		ft_check_sign(t_opt *flags, intmax_t nb)
{
	if (flags->plus)
	{
		if (nb < 0)
			ft_putchar('-');
		else
			ft_putchar('+');
		return (1);
	}
	else if (flags->space)
	{
		if (nb < 0)
			ft_putchar('-');
		else
			ft_putchar(' ');
		return (1);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

intmax_t	did_0(t_opt *flags, intmax_t nb)
{
	intmax_t	len;

	len = ft_len(nb, 10);
	len += ft_check_sign(flags, nb);
	ft_putnbr_m(nb);
	return (len);
}

intmax_t	did_2_help(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			tmp;
	int			i;

	len = ft_len(nb, 10);
	if (flags->zero)
	{
		tmp = ft_check_sign(flags, nb);
		i = ft_loop(flags->width - len, '0');
		ft_putnbr_m(nb);
	}
	else
	{
		i = ft_loop(flags->width - len, ' ');
		tmp = ft_check_sign(flags, nb);
		ft_putnbr_m(nb);
	}
	return (i + len + tmp);
}

intmax_t	did_1_help(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			tmp;
	int			i;

	len = ft_len(nb, 10);
	if (flags->zero)
	{
		tmp = ft_check_sign(flags, nb);
		i = ft_loop(flags->width - len, '0');
		ft_putnbr_m(nb);
	}
	else
	{
		i = ft_loop(flags->width - len, ' ');
		tmp = ft_check_sign(flags, nb);
		ft_putnbr_m(nb);
	}
	return (i + len + tmp);
}

intmax_t	did_1(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			tmp;

	tmp = 0;
	len = ft_len(nb, 10);
	if (flags->width > len)
	{
		if (flags->minus)
			i = did_1_help(flags, nb);
		else
			i = did_2_help(flags, nb);
		return (i);
	}
	ft_putnbr_m(nb);
	return (len + tmp);
}

intmax_t	did_2(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			ch;

	i = 0;
	len = ft_len(nb, 10);
	ch = ft_check_sign(flags, nb);
	if (flags->precision > len)
	{
		i = ft_loop(flags->precision - len, '0') + len;
		ft_putnbr_m(nb);
		return (i + ch);
	}
	ft_putnbr_m(nb);
	return (len + ch);
}

intmax_t	helper_did(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			tmp;
	int			ch;

	i = 0;
	len = ft_len(nb, 10);
	tmp = flags->precision > len ? (flags->precision - len) : len;
	if (flags->zero)
	{
		ch = ft_check_sign(flags, nb);
		i = ft_loop(flags->width - (len + tmp), '0') + len;
		ft_putnbr_m(nb);
	}
	else
	{
		if (flags->precision < flags->width)
			i += ft_loop(flags->width - (len + tmp), ' ');
		ch = ft_check_sign(flags, nb);
		i += ft_loop(tmp, '0') + len;
		ft_putnbr_m(nb);
	}
	return (i + ch);
}

intmax_t	helper_did_2(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			tmp;

	i = 0;
	len = ft_len(nb, 10);
	tmp = flags->precision > len ? (flags->precision - len) : len;
	ft_check_sign(flags, nb);
	i = ft_loop(tmp, '0') + len;
	ft_putnbr_m(nb);
	if (flags->precision < flags->width)
		i += ft_loop(flags->width - (len + tmp), ' ');
	return (i);
}

intmax_t	did_3(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			tmp;

	i = 0;
	len = ft_len(nb, 10);
	tmp = flags->precision > len ? (flags->precision - len) : len;
	if (flags->width > (tmp + len) || flags->precision > flags->width)
	{
		if (flags->minus)
			i = helper_did_2(flags, nb);
		else
			i = helper_did(flags, nb);
		return (i);
	}
	ft_putnbr(nb);
	return (len);
}
