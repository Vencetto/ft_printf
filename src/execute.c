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

int		executor(t_opt *flags, va_list ap)
{
	char	*str;
	int		len;

	if (flags->sp_type == 'd' || flags->sp_type == 'i' || flags->sp_type == 'D')
		str = did_executor(flags, ap);
	len = ft_strlen(str);
	ft_putstr(str);
	return (len);
}

// int		modif(int nb, t_opt *flags)
// {
	
// }

char	*did_executor(t_opt *flags, va_list ap)
{
	intmax_t	nb;
	char		*str;

	nb = take_arg_d(flags, ap);
	str = ft_itoa_base(nb, 10);
	return (str);
}