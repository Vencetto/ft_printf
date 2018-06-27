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
