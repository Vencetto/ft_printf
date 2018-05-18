/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:42:01 by vzomber           #+#    #+#             */
/*   Updated: 2018/05/17 18:42:03 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int nb, int base)
{
	int		len;
	char	*str;

	len = ft_len(nb, base);
	if (value == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (nb < 0 && base == 10)
	{
		len++;
		if (!(str = ft_strnew(len)))
			return (NULL);
		str[0] = '-';
	}
	else
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
	}
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % base) + (nb % base > 9 ? 'a' - 10 : '0');
		nb /= base;
	}
	return (str);
}
