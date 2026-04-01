/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/19 15:38:16 by anonymous     #+#    #+#                 */
/*   Updated: 2026/04/01 17:54:48 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(const char *format, va_list args)
{
	if (*format == 'u')
		ft_putnbr_base(va_arg(args, int), "0123456789", 1, 0);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_base(va_arg(args, int), "0123456789", 0, 0);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *));
	else if (*format == 'c')
		ft_putchar(va_arg(args, int));
	else if (*format == 'p')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 0, 1);
	else if (*format == 'x' || *format == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 0, 0);
	else
		return (0);
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