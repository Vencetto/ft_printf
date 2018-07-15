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

char		*ft_strinst(char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strnew(1);
	str[0] = '%';
	free(tmp);
	return (str);
}

void		minus_prec(char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	if (ft_strchr(str, '-'))
	{
		while (str[i] != '-')
			i++;
		str[i] = '0';
		str[0] = '-';
	}
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
	printf("modif:     %c\n", flags->modif);
	printf("sp_type:   %c\n", flags->sp_type);
	printf("------------\n\n");
}
