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

int			checking(char *str)
{
	if (ft_strchr((const char *)str, '%'))
		return (0);
	else
		write(1, str, ft_strlen(str));
	return (1);
}

void		show_structure(t_opt *flags)
{
	printf("\nStructure---\n");
	printf("minus:     %d\n", flags->minus);
	printf("plus:      %d\n", flags->plus);
	printf("space:     %d\n", flags->space);
	printf("sharp:     %d\n", flags->sharp);
	printf("zero:      %d\n", flags->zero);
	printf("precision: %d\n", flags->precision);
	printf("width:     %d\n", flags->width);
	printf("modif:     %s\n", flags->modif);
	printf("sp_type:   %c\n", flags->sp_type);
	printf("------------\n\n");
}
