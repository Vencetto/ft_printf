/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 20:45:42 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/24 20:45:47 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			x_check_zero(t_opt *flags, char *str)
{
	if (!ft_strcmp(str, "0"))
	{
		if (flags->point && !flags->precision)
			return (1);
	}
	return (0);
}

intmax_t	x_did_0(t_opt *flags, char *str, intmax_t nb)
{
	intmax_t	len;
	int			ox;

	len = ft_strlen(str);
	ox = ox_did(flags, nb, str);
	ft_putstr(str);
	return (len + ox);
}

int			if_ox_did(t_opt *flags, intmax_t nb, char *str)
{
	if (flags->sp_type == 'o' && flags->sharp && nb != 0)
		return (1);
	if (flags->sp_type == 'x' && flags->sharp && ft_strcmp(str, "0"))
		return (2);	if (flags->sp_type == 'X' && flags->sharp && ft_strcmp(str, "0"))
	{
		return (2);
	}
	if (flags->sp_type == 'p')
		return (2);
	return (0);
}

intmax_t	x_did_2_help(t_opt *flags, char *str, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			ox;

	ox = 0;
	len = ft_strlen(str);
	if (flags->zero)
	{
		ox = ox_did(flags, nb, str);
		i = ft_loop(flags->width - len, '0');
		ft_putstr(str);
	}
	else
	{
		// printf("width: %d\n", flags->width);
		if (if_ox_did(flags, nb, str))
			flags->width -= if_ox_did(flags, nb, str);
		// printf("width: %d\n", flags->width);
		i = ft_loop(flags->width - len, ' ');
		ox = ox_did(flags, nb, str);
		ft_putstr(str);
	}
	return (i + len + ox);
}

intmax_t	x_did_1_help(t_opt *flags, char *str)
{
	intmax_t	len;
	int			i;
	int			ox;

	ox = 0;
	len = ft_strlen(str);
	if ((flags->sharp && ft_strcmp(str, "0")) || flags->sp_type == 'p') 
	{
		// printf("width: %d\n", flags->width);
		ox = ox_did(flags, ft_atoi(str), str);
		// if (flags->sp_type == 'p')
			// flags->width -= 2;
		// printf("width: %d\n", flags->width);
	}
	ft_putstr(str);
	i = ft_loop(flags->width - len, ' ');
	return (i + len + ox);
}

intmax_t	x_did_1(t_opt *flags, char *str, intmax_t nb)
{
	intmax_t	len;
	int			i;
	int			ox;

	len = ft_strlen(str);
	if (flags->width > len)
	{
		if (flags->minus)
			i = x_did_1_help(flags, str);
		else
			i = x_did_2_help(flags, str, nb);
		return (i);
	}
	ox = ox_did(flags, nb, str);
	ft_putstr(str);
	return (len + ox);
}

intmax_t	x_did_2(t_opt *flags, char *str)
{
	intmax_t	len;
	int			i;

	i = 0;
	len = ft_strlen(str);
	if (flags->precision > len)
	{
		i = ft_loop(flags->precision - len, '0') + len;
		ft_putstr(str);
		return (i);
	}
	ft_putstr(str);
	return (len);
}

intmax_t	x_helper_did(t_opt *flags, char *str)
{
	intmax_t	len;
	int			i;
	int			tmp;

	i = 0;
	len = ft_strlen(str);
	tmp = flags->precision > len ? (flags->precision - len) : 0;
	if (flags->zero)
	{
		if (flags->precision < flags->width)
			i += ft_loop(flags->width - (tmp + len), ' ');
		i += ft_loop(tmp, '0') + len;
		ft_putstr(str);
	}
	else
	{
		// printf("str: %s, len: %jd, tmp: %d, prec: %d, width: %d, loop: %ld\n", str, len, tmp, flags->precision, flags->width, flags->width - (tmp + len));
		if (flags->precision < flags->width)
			i += ft_loop(flags->width - (len + tmp), ' ');
		i += ft_loop(tmp, '0') + len;
		ft_putstr(str);
	}
	return (i);
}

intmax_t	x_helper_did_2(t_opt *flags, char *str)
{
	intmax_t	len;
	int			i;
	int			tmp;

	i = 0;
	len = ft_strlen(str);
	tmp = flags->precision > len ? (flags->precision - len) : 0;
	i = ft_loop(tmp, '0') + len;
	ft_putstr(str);
	if (flags->precision < flags->width)
		i += ft_loop(flags->width - (len + tmp), ' ');
	return (i);
}

intmax_t	x_did_3(t_opt *flags, char *str)
{
	intmax_t	len;
	int			i;
	int			tmp;

	i = 0;
	len = ft_strlen(str);
	tmp = flags->precision > len ? flags->precision  : 0;
	// printf("str: %s, len: %jd, tmp: %d, prec: %d, width: %d\n", str, len, tmp, flags->precision, flags->width);
	if (flags->width >= tmp || flags->precision > flags->width)
	{
		if (flags->minus)
			i = x_helper_did_2(flags, str);
		else
			i = x_helper_did(flags, str);
		return (i);
	}
	ft_putstr(str);
	return (len);
}
