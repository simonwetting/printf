/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/19 15:38:16 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/01 17:03:45 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	ft_strlen(const char *s)
{
	int		length;

	length = 0;
	while (*(s+length))
		length++;
	return length;
}

//void	print_zeros(int n)
//{
//	long	nbr;
//	int		length;

//	nbr = n;
//	length = 0;
//	if (nbr < 0)
//		nbr *= -1;
//	while (nbr > 0)
//	{
//		length++;
//		nbr /= 10;
//	}
//	write(1, "0000000000000000", 16 - length);
//}

void	print_pointer()
{
	write(1, "0x", 2);
}

void	ft_putnbr_base(int	nbr, char *base, int unsigned_true, int is_pointer)
{
	long long			number;
	int				base_length;
	
	if (is_pointer)
		print_pointer();
	number = nbr;
	base_length = ft_strlen(base);
	if (unsigned_true && number < 0)
			number = UINT_MAX + number;
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
	}
	if (number > base_length - 1)
		ft_putnbr_base(number / base_length, base, unsigned_true, 0);
	ft_putchar(base[number % base_length]);
}

int	print(const char *format, va_list args)
{
	switch (*format)
	{
	case 'u':
		ft_putnbr_base(va_arg(args, int), "0123456789", 1, 0);
		break;
	case 'd':
	case 'i':
		ft_putnbr_base(va_arg(args, int), "0123456789", 0, 0);
		break;
	case 's':
		ft_putstr(va_arg(args, char *));
		break;
	case 'c':
		ft_putchar(va_arg(args, int));
		break;
	case 'p':
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 0, 1);
		break;
	case 'x':
	case 'X':
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 0, 0);
		break;
	default:
		return (0);
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			if (print(++format, args) == 0)
				return (0);
			format++;
		}
		else
			write(1, format++, 1);
	}
	return (1);
}

#include <stdio.h>
int		main(void)
{
	// printf("%p\n", 123456789);
	// char	*test = "hello";
	// printf("%p\n%d", test, test);
	// unsigned int	unsign = -1;
	// int				sign = unsign;
	// printf("%d", sign);
	char	*str = "test";
	//printf("%p\n", str);
	ft_printf("\n%s\n", str);
	ft_printf("%d\n", -12355);
	ft_printf(">%u\n", -1);
	ft_printf("%d\n", 12355);
	ft_printf("%x\n", 12355);
	ft_printf("%c\n", 'b');
	ft_printf("%s\n", "test");
	ft_printf("%c\n", 'b');
	ft_printf("pointer>%p\npointer>%p\n", 12355, 12345);
	//ft_putnbr_base(-12355, "0123456789", 0, 1);
	//ft_putnbr_base(12355, "0123456789", 0, 1);
	//printf("%d", ft_strlen("0123456789ABCDEF"));
}