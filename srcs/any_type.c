/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:40:13 by vzomber           #+#    #+#             */
/*   Updated: 2018/07/25 15:40:14 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	a_did_2_help(t_opt *flags)
{
	int			i;

	if (flags->zero)
		i = ft_loop(flags->width, '0');
	else
		i = ft_loop(flags->width, ' ');
	// write(1, flags->str, ft_strlen(flags->str));
	return (i);
}

int		any_type(t_opt *flags)
{
	int len;

	len = 0;
	if (flags->width)
		return ((len = a_did_2_help(flags)));
	return (len);
}