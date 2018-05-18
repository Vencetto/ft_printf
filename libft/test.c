char		*ft_itoa_2(int nb)
{
	int		len;
	char	*str;

	len = ft_len(nb);
	if (nb < 0)
	{
		len++;
		if (!(str = ft_strnew(len)))
			return (NULL);
		str[0] = -;
	}
	else
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
	}
	str[len] = 0;
	str[--len] = ft_abs(nb % 10) + 0;
	while (ft_abs(nb /= 10))
		str[--len] = ft_abs(nb % 10) + 0;
	return (str);
}
