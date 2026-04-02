/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/19 15:38:16 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/02 15:51:36 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	print(const char *format, va_list args)
{
	int	len;

	len = 0;
	if (*format == '%')
		len += write(1, "%", 1);
	if (*format == 'u')
		len += call_putnbru(va_arg(args, unsigned int), "0123456789");
	if (*format == 'd' || *format == 'i')
		len += call_putnbr(va_arg(args, int), "0123456789", 0);
	if (*format == 's')
		len += ft_putstr(va_arg(args, char *));
	if (*format == 'c')
		len += ft_putchar(va_arg(args, int));
	if (*format == 'p')
	{
		len += call_putpointer(va_arg(args, unsigned long), "0123456789abcdef");
	}
	if (*format == 'x')
		len += call_putnbru(va_arg(args, unsigned long), "0123456789abcdef");
	if (*format == 'X')
		len += call_putnbru(va_arg(args, unsigned long), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			len += print(++format, args);
			format++;
		}
		else
			len += write(1, format++, 1);
	}
	return (len);
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

//int	print(const char *format, va_list args)
//{
//	switch (*format)
//	{
//	case 'u':
//		ft_putnbr_base(va_arg(args, int), "0123456789", 1, 0);
//		break;
//	case 'd':
//	case 'i':
//		ft_putnbr_base(va_arg(args, int), "0123456789", 0, 0);
//		break;
//	case 's':
//		ft_putstr(va_arg(args, char *));
//		break;
//	case 'c':
//		ft_putchar(va_arg(args, int));
//		break;
//	case 'p':
//		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 0, 1);
//		break;
//	case 'x':
//	case 'X':
//		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 0, 0);
//		break;
//	default:
//		return (0);
//	}
//	return (1);
//}