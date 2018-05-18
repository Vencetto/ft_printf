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

void	executor(t_opt *flags, va_list ap)
{
	if (flags->sp_type == 'd' || flags->sp_type =='i' || flags->sp_type =='D')
		Did_executor(flags, ap);
}

void	Did_executor(t_opt *flags, va_list ap)
{
	int nb;
									(void)flags;
	nb = va_arg(ap, int);
	ft_putnbr(nb);
	// if (# && !0)
	// 	//
	// if (0)
	// 	//

}