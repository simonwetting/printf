/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 17:26:40 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/01 17:54:39 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_putnbr_base(int	nbr, char *base, int unsigned_true, int is_pointer)
{
	long long			number;
	int				base_length;
	
	if (is_pointer)
		write(1, "0x", 2);
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