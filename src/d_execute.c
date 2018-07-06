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

	len = 0;
	if (flags->sp_type == 'd' || flags->sp_type == 'i' || flags->sp_type == 'D' || flags->sp_type == '%')
	{
		str = did_executor(flags, ap);
		len = ft_strlen(str);
		ft_putstr(str);
		free(str);
	}
	return (len);
}

void	d_width(char *str, t_opt *flags)
{
	int		len;
	char	*tmp;
	int		i;
	int		j;
	int		width;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	if (flags->width <= len)
		return ;
	else
	{
		tmp = ft_strdup(str);
		width = flags->width - len;
		while (width--)
			str[i++] = ' ';
		while (len--)
		{
			str[i] = tmp[j];
			i++;
			j++;
		}
		str[i] = '\0';
		free(tmp);
	}
}

void	d_precision(char *str, t_opt *flags)
{
	int		len;
	char	*tmp;
	int		i;
	int		j;
	int		prec;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	if (flags->precision <= len)
		return ;
	else
	{
		tmp = ft_strdup(str);
		prec = flags->precision - len;
		while (prec--)
			str[i++] = '0';
		while (len--)
		{
			str[i] = tmp[j];
			i++;
			j++;
		}
		str[i] = '\0';
		ft_strdel(&tmp);
	}
}

void	d_plus(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (str[i] == ' ')
	{
		while (str[i + 1] == ' ')
			i++;
		str[i] = '+';
		return ;
	}
	else
	{
		tmp = ft_strdup(str);
		str[i] = '+';
		i++;
		while (*tmp)
		{
			str[i] = *tmp;
			i++;
			tmp++;
		}
		ft_strdel(&tmp);
		// printf("str: bef %s %p\n", str, str);
	}
}

char	*did_executor(t_opt *flags, va_list ap)
{
	intmax_t	nb;
	char		*str;

	nb = take_arg_d(flags, ap);
	str = ft_itoa_base(nb, 10);
	if (flags->sp_type == '%')
		str = ft_strinst(str);
	if (flags->precision)
		d_precision(str, flags);
	if (flags->width)
		d_width(str, flags);
	// printf("str1: %s %p\n", str, str);
	if (flags->plus && nb > 0)
		d_plus(str);
	// printf("str2: %s %p\n", str, str);
	return (str);
}