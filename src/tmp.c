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

void	put_flags(char c, t_opt *flags)
{
	if (c == ' ')
		flags->space = 1;
	else if (c == '-')
		flags->defis = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == '#')
		flags->sharp = 1;
	else if (c == '0')
		flags->zero = 1;
}

void	put_precision(int c, t_opt *flags)
{
	if (c >= '0' && c <= '9')
		flags->precision = c - '0';
}

void	show_structure(t_opt *flags)
{
	printf("\nStructure-------\n");
	printf("flags->defis: %d\n", flags->defis);
	printf("flags->plus:  %d\n", flags->plus);
	printf("flags->space: %d\n", flags->space);
	printf("flags->sharp: %d\n", flags->sharp);
	printf("flags->zero:  %d\n", flags->zero);
	printf("precision:    %d\n", flags->precision);
	printf("----------------\n\n");
}