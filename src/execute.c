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

	if (flags->sp_type == 'd' || flags->sp_type == 'i' || flags->sp_type == 'D' || flags->sp_type == '%')
		str = did_executor(flags, ap);
	len = ft_strlen(str);
	ft_putstr(str);
	return (len);
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
			str[i++] = tmp[j++];
		free(tmp);
	}
}

void	d_plus(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = ft_strdup(str);
	str[0] = '+';
	i = 1;
	j = 0;
	while (tmp[j])
		str[i++] = tmp[j++];
	free(tmp);
}

char	*did_executor(t_opt *flags, va_list ap)
{
	intmax_t	nb;
	char		*str;

	nb = take_arg_d(flags, ap);
	str = ft_itoa_base(nb, 10);
	if (flags->sp_type == '%')
		str = "%\0";
	if (flags->precision)
		d_precision(str, flags);
	if (flags->plus)
		d_plus(str);
	return (str);
}