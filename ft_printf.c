/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/19 15:38:16 by anonymous     #+#    #+#                 */
/*   Updated: 2026/03/19 15:38:16 by anonymous     ########   odam.nl         */
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

void	print_zeros(int n)
{
	long	nbr;
	int		length;

	nbr = n;
	length = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		length++;
		nbr /= 10;
	}
	write(1, "0000000000000000", 16 - length);
}

void	ft_putnbr_base(int	nbr, char *base, int unsigned_true, int is_pointer)
{
	long long			number;
	int				base_length;
	
	if (is_pointer)
		print_zeros(nbr);
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

int	print(const char *format, va_list args, int unsigned_true)
{
	switch (*format)
	{
	case 'd':
	case 'i':
		ft_putnbr_base(va_arg(args, int), "0123456789", unsigned_true, 0);
		break;
	case 's':
		ft_putstr(va_arg(args, char *));
		break;
	case 'c':
		ft_putchar(va_arg(args, int));
		break;
	case 'p':
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", unsigned_true, 1);
		break;
	case 'x':
	case 'X':
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", unsigned_true, 0);
		break;
	default:
		return (0);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int		unsigned_true;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			unsigned_true = 0;
			if (*format == 'u')
			{
				unsigned_true = 1;
				format++;
			}
			if (print(format++, args, unsigned_true) == 0)
				return (0);
		}
		else
			write(1, format++, 1);
	}
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
	ft_printf("%d\n", -12355);
	ft_printf(">%ud\n", -1);
	ft_printf("%d\n", 12355);
	ft_printf("%x\n", 12355);
	ft_printf("%c\n\n", 'b');
	ft_printf("\n%s\n", "test");
	ft_printf("%c\n\n", 'b');
	ft_printf("pointer>%p\npointer>%p\n", 12355, 12345);
	// ft_putnbr_base(-12355, "0123456789", 0, 1);
	// ft_putnbr_base(12355, "0123456789", 0, 1);
	// printf("%d", ft_strlen("0123456789ABCDEF"));
}