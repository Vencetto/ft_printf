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
		nb = (long)va_arg(ap, long);
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

int		bd_executor(t_opt *flags, va_list ap)
{
	intmax_t	nb;
	int			len;

	len = 0;
	nb = va_arg(ap, long);
	if (check_zero(flags, nb))
		return (ft_crutch(flags));
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

int		if_check_sign(t_opt *flags, intmax_t nb)
{
	if (flags->sp_type != 'u')
	{
		if (flags->plus)
			return (1);
		else if (flags->space)
			return (1);
		else if (nb < 0)
			return (1);
	}
	return (0);
}

int		ft_check_sign(t_opt *flags, intmax_t nb)
{
	if (flags->sp_type != 'u' && flags->sp_type != 'U')
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
	}
	return (0);
}

intmax_t	did_0(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			ox;

	if (flags->sp_type == 'u' || flags->sp_type == 'U')
		len = ft_ulen(nb, 10);
	else
		len = ft_len(nb, 10);
	len += ft_check_sign(flags, nb);
	ox = ox_did(flags, nb, NULL);
	if (flags->sp_type == 'u' || flags->sp_type == 'U')
		ft_uputnbr_m(nb);
	else
		ft_putnbr_m(nb);
	return (len + ox);
}

int			ox_did(t_opt *flags, intmax_t nb, char *str)
{
	if ((flags->sp_type == 'o' || flags->sp_type == 'O') && flags->sharp && nb != 0)
	{
		ft_putchar('0');
		flags->width--;
		return (1);
	}
	if (flags->sp_type == 'x' && flags->sharp && ft_strcmp(str, "0"))
	{
		ft_putstr("0x");
		flags->width -= 2;
		return (2);
	}
	if (flags->sp_type == 'X' && flags->sharp && ft_strcmp(str, "0"))
	{
		ft_putstr("0X");
		flags->width -= 2;
		return (2);
	}
	if (flags->sp_type == 'p')
	{
		ft_putstr("0x");
		flags->width -= 2;
		return (2);
	}
	return (0);
}

intmax_t	did_2_help(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			tmp;
	int			i;
	int			ox;

	ox = 0;
	len = ft_len(nb, 10);
	if (flags->zero)
	{
		tmp = ft_check_sign(flags, nb);
		ox = ox_did(flags, nb, NULL);
		i = ft_loop(flags->width - len, '0');
		ft_putnbr_m(nb);
	}
	else
	{
		if (flags->sp_type == 'o' && flags->sharp)
			flags->width--;
		i = ft_loop(flags->width - len, ' ');
		ox = ox_did(flags, nb, NULL);
		tmp = ft_check_sign(flags, nb);
		ft_putnbr_m(nb);
	}
	return (i + len + tmp + ox);
}

intmax_t	did_1_help(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			tmp;
	int			i;
	int			ox;

	ox = 0;
	len = ft_len(nb, 10);
	tmp = ft_check_sign(flags, nb);
	if (flags->sp_type == 'o' && flags->sharp && nb != 0)
	{
		ft_putchar('0');
		ox++;
		flags->width--;
	}
	ft_putnbr_m(nb);
	i = ft_loop(flags->width - len, ' ');
	return (i + len + tmp + ox);
}

intmax_t	did_1(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;

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
	return (len);
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
	tmp = flags->precision > len ? (flags->precision - len) : 0;
	if (flags->zero)
	{
		if (flags->precision < flags->width)
			i += ft_loop(flags->width - (len + tmp), ' ');
		ch = ft_check_sign(flags, nb);
		i += ft_loop(tmp, '0') + len;
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
	int			ch;

	i = 0;
	len = ft_len(nb, 10);
	tmp = flags->precision > len ? (flags->precision - len) : 0;
	ch = ft_check_sign(flags, nb);
	i = ft_loop(tmp, '0') + len;
	ft_putnbr_m(nb);
	if (flags->precision < flags->width)
		i += ft_loop(flags->width - (len + tmp), ' ');
	return (i + ch);
}

intmax_t	did_3(t_opt *flags, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			tmp;

	i = 0;
	len = ft_len(nb, 10);
	tmp = flags->precision > len ? (flags->precision - len) : 0;
	if (flags->width >= (tmp + len) || flags->precision > flags->width)
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
