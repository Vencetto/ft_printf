/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:23:17 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/15 17:23:19 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_all_zero(t_opt *flags)
{
	// flags = (t_opt *)malloc(sizeof(t_opt));
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->sharp = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->modif = '0';
	flags->sp_type = '0';
}

intmax_t	take_arg_d(t_opt *flags, va_list ap)
{
	intmax_t	nb;

	nb = 0;
	if (flags->modif == 'h')
		nb = (short)va_arg(ap, int);
	else
		nb = va_arg(ap, int);
	// else if (flags->modif == 'hh')
	// 	s = ft_itoabase(va_arg(ap, int), 10);
	// else if (flags->modif == 'l')
	// 	s = ft_itoabase(va_arg(ap, long), 10);
	// else if (flags->modif == 'll')
	// 	s = ft_itoabase(va_arg(ap, int), 10);
	// else if (flags->modif == 'j')
	// 	s = ft_itoabase(va_arg(ap, int), 10);
	// else if (flags->modif == 'z')
	// 	s = ft_itoabase(va_arg(ap, int), 10);
	return (nb);
}

int		checking(char *str)
{
	if (ft_strchr((const char *)str, '%'))
		return (0);
	else
		write(1, str, ft_strlen(str));
	return (1);
}

void	show_structure(t_opt *flags)
{
	printf("\nStructure---\n");
	printf("minus:     %d\n", flags->minus);
	printf("plus:      %d\n", flags->plus);
	printf("space:     %d\n", flags->space);
	printf("sharp:     %d\n", flags->sharp);
	printf("zero:      %d\n", flags->zero);
	printf("precision: %d\n", flags->precision);
	printf("width:     %d\n", flags->width);
	printf("modif:     %c\n", flags->modif);
	printf("sp_type:   %c\n", flags->sp_type);
	printf("------------\n\n");
}
