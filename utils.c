/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 17:26:40 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/02 15:48:53 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return(write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int		len;
	
	if (!s)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	write(1, s++, len);
	return (len);
}

int	ft_strlen(const char *s)
{
	int		length;

	length = 0;
	while (*(s+length))
		length++;
	return length;
}

int	call_putnbr(long nbr, char *base, int unsigned_true)
{
	int			len;
	int			base_len;
	long long	number;
	
	//printf("\n[%ld]", nbr);
	len = 0;
	number = nbr;
	base_len = ft_strlen(base);
	if (number < 0)
	{
		number *= -1;
		len++;
	}
	while (number > 0)
	{
		number /= base_len;
		len++;
	}
	if (len == 0)
		len++;
	ft_putnbr_base(nbr, base, unsigned_true);
	return (len);
}

int	call_putnbru(unsigned int nbr, char *base)
{
	int				len;
	int				base_len;
	unsigned int	number;

	len = 0;
	number = nbr;
	base_len = ft_strlen(base);
	while (number > 0)
	{
		number /= base_len;
		len++;
	}
	ft_putnbr_baseu(nbr, base);
	if (len == 0)
		len++;
	return (len);
}

int	call_putpointer(unsigned long nbr, char *base)
{
	int			len;
	int			base_len;
	unsigned long	number;
	
	//printf("\n[%ld]", nbr);
	len = 0;
	number = nbr;
	base_len = ft_strlen(base);
	while (number > 0)
	{
		number /= base_len;
		len++;
	}
	if (len == 0)
		len++;
	if (nbr)
	{
		len += write(1, "0x", 2);
		ft_putpointer(nbr, base);
	}
	else
		return (write(1, "(nil)", 5));
	return (len);
}

void	ft_putnbr_baseu(unsigned int number, char *base)
{
	unsigned int	base_length;
	
	base_length = ft_strlen(base);
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
	}
	if (number > base_length - 1)
		ft_putnbr_baseu(number / base_length, base);
	ft_putchar(base[number % base_length]);
}

void	ft_putnbr_base(long	number, char *base, int unsigned_true)
{
	int			base_length;
	
	base_length = ft_strlen(base);
	if (unsigned_true && number < 0)
			number = UINT_MAX + number;
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
	}
	if (number > base_length - 1)
		ft_putnbr_base(number / base_length, base, unsigned_true);
	ft_putchar(base[number % base_length]);
}
void	ft_putpointer(unsigned long nbr, char *base)
{
	unsigned long		number;
	unsigned int	base_length;
	
	number = nbr;
	base_length = ft_strlen(base);
	//printf("[%lu] \n", number);
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
	}
	if (number > base_length - 1)
		ft_putpointer(number / base_length, base);
	ft_putchar(base[number % base_length]);
}