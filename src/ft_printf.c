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

// void	some_funk(char c, va_list ap)
// {
// 	if (c == 'c')
// 		ft_putchar(va_arg(ap, int));
// 	else if (c == 's')
// 		ft_putstr(va_arg(ap, char*));
// 	else if (c == 'd')
// 		ft_putnbr(va_arg(ap, int));
// }

int		searcher(char **str, int i, va_list ap)
{
	char	*buff = NULL;
	int		k;
	char	*point;

	k = 0;
	point = *str;
	while (str)
	{
		if (*str == 's' || *str == 'S' || *str == 'p' || *str == 'd' ||
			*str == 'D' || *str == 'i' || *str == 'o' || *str == 'O' ||
			*str == 'u' || *str == 'U' || *str == 'x' || *str == 'X' ||
			*str == 'c' || *str == 'C')
		{
			// some_funk(str[i], ap);
			return (i);
		}
		else
			//buff[k++] = str[i];
		str++;
	}
	return (i);
}

int		parser(va_list ap, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i = searcher(&str, i + 1, ap);
		else
			// write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		res;

	if (format)
	{
		va_start(ap, format);
		res = parser(ap, (char *)format);
		va_end(ap);
	}
	return (res);
}
