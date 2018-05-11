/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:46:26 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/03 13:46:28 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_flags(char **s, t_opt *flags)
{
	if (*s == ' ')
		flags->space = 1;
	else if (*s == '-')
		flags->minus = 1;
	else if (*s == '+')
		flags->plus = 1;
	else if (*s == '#')
		flags->sharp = 1;
	else if (*s == '0')
		flags->zero = 1;
}