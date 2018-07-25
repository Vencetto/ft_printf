/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_execute.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:43:46 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/22 13:43:47 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		p_executor(t_opt *flags, va_list ap)
{
	char		*str;
	int			len;

	len = 0;
	str = ft_uitoa_base((uintptr_t)va_arg(ap, void *), 16);

	// if (check_zero(flags, nb))
	// 	return (ft_crutch(flags));
	// if (if_check_sign(flags,nb) && flags->width > flags->precision)
	// 	flags->width--;
	if (!flags->width && !flags->precision)
		return ((len = x_did_0(flags, str, 1)));
	else if (flags->width && !flags->precision)
		return ((len = x_did_1(flags, str, 1)));
	// else if (!flags->width && flags->precision)
	// 	return ((len = did_2(flags, nb)));
	// else if (flags->width && flags->precision)
	// 	return ((len = did_3(flags, nb)));
	ft_putstr("0x");
	ft_putstr(str);
	len = ft_strlen(str);
	return (len);
}