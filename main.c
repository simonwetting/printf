/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 17:15:58 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/01 17:54:53 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

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