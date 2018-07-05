#include "./includes/ft_printf.h"

int	main(void)
{
	// char a = 'H';
	// char *str = "ABBA";
	// ft_printf("12 %c	%s %d", a, str, 35);
	// ft_printf("%s", str);
	// ft_printf("1%  s2%c3%d", "lalala\n", 97, 97);//4%p5%D6%i7%o8%O9%u10%U11%x12%X13%S14%C15");
	// ft_printf("% -#2.8ls", "lalala\n");
	 // ft_printf("ft -: %-d\n", 35);
		// printf("og -  : %-d\n", 35);
		// printf("og +  : %+d\n", 35);
		// printf("og ' ': % d\n", 35);
	// printf("%s\n", ft_itoa_base(244, 8));
																	// ft_printf("%  656.10024d"); //-- width and precision здається працюють, залишу це для перевірки
	// system("leaks a.out");
	// printf("%6d\n", 123);
	// printf("%hd\n", 2147483648);
	// char c = 255;
	// ft_printf("%5%")
	// ft_printf("%d\n", 1212);
	// ft_printf("dadasdada   asd%+- 05.10d helol", 1);

	   printf("%.1d\n", 123);
	ft_printf("%.1d\n", 123);
	   printf("%.2d\n", 123);
	ft_printf("%.2d\n", 123);
	   printf("%.3d\n", 123);
	ft_printf("%.3d\n", 123);
	   printf("%+.4d\n", 123);
	ft_printf("%+.4d\n", 123);
	   printf("%+.5d\n", 123);
	ft_printf("%+.5d\n", 123);
	   printf("%+.6d\n", 123);
	ft_printf("%+.6d\n", 123);
	   printf("%+.7d\n", 123);
	ft_printf("%+.7d\n", 123);
	   printf("%+.8d\n", 123);
	ft_printf("%+.8d\n", 123);
	   printf("%+.9d\n", 123);
	ft_printf("%+.9d\n", 123);
	return (0);
}