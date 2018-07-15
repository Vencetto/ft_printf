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
	int		len;

	len = 0;
	if (flags->sp_type == 'd' || flags->sp_type == 'i' ||
		flags->sp_type == 'D' || flags->sp_type == '%')
		len = did_executor(flags, ap);
	else if (flags->sp_type == 's')
		len = s_executor(flags, ap);
	return (len);
}

void	d_width(char *str, t_opt *flags, char ch)
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
			str[i++] = ch;
		while (len--)
		{
			str[i++] = tmp[j];
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
			str[i++] = tmp[j];
			j++;
		}
		str[i] = '\0';
		ft_strdel(&tmp);
	}
}

void	d_plus(char *str, char ch)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[i] == ' ')
	{
		while (str[i + 1] == ' ')
			i++;
		str[i] = ch;
		return ;
	}
	else
	{
		tmp = ft_strdup(str);
		str[i++] = ch;
		while (tmp[j])
		{
			str[i++] = tmp[j];
			j++;
		}
		str[i] = '\0';
		ft_strdel(&tmp);
	}
}

int		did_executor(t_opt *flags, va_list ap)
{
	intmax_t	nb;
	int			len;
	char		*str;

	nb = take_arg_d(flags, ap);
	str = ft_itoa_base(nb, 10);

	// printf("gotdamnshit_str: %s\n", str);

	if (flags->sp_type == '%')
		str = ft_strinst(str);
	if (flags->precision)
		d_precision(str, flags);
	if (flags->width && !flags->zero)
		d_width(str, flags, ' ');
	else if (flags->width && flags->zero)
		d_width(str, flags, '0');
	if (flags->space && !flags->plus && flags->sp_type != '%' && nb >= 0)
		d_plus(str, ' ');
	if (flags->plus && nb >= 0)
		d_plus(str, '+');
	if (nb < 0 && (flags->precision || flags->zero))
		minus_prec(str);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}