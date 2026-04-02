/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 17:15:58 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/02 15:45:56 by swetting      ########   odam.nl         */
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
	//char	*str = "test";
	//ft_printf(" %c ", '0');
	//printf("%p\n", str);
	//ft_printf(" %d\n", ft_printf("test\n"));
	//ft_printf("\n%s\n", str);
	//ft_printf("%d >", ft_printf("%d\n", -12355));
	//ft_printf(">%u\n", -1);
	//ft_printf("%d\n", 12355);
	//ft_printf("%x\n", 12355);
	//ft_printf("%c\n", 'b');
	//ft_printf("%s\n", "test");
	//ft_printf("%c\n", 'b');
	//ft_printf("pointer>%p\npointer>%p\n", 12355, 12345);
	
	//ft_putnbr_base(-12355, "0123456789", 0);
	//ft_putnbr_base(12355, "0123456789", 0);
	//printf("%d", ft_strlen("0123456789ABCDEF"));
	//ft_printf(" > %d", ft_printf(" %c ", '0'));
	//long	test = UINT_MAX - 1;
	//test++;
	//test++;
	//printf("%p", test);
	//printf("\n[%ld]", test);
	//ft_printf("%p", test);
	//printf("%p\n", (void *)(-1));
	//ft_printf("%p", (void *)(-1));


	//ft_printf("<%d>", ft_printf("[%d]", 0));
	//ft_putstr("\n");
	//ft_printf("<%d>", ft_printf("%d", 0));
	//ft_putstr("\n");
	//ft_printf("<%d>", ft_printf("%d", 1));
	//ft_putstr("\n");
	//ft_printf("<%d>", ft_printf("%d", 10));
	//ft_putstr("\n");
	//ft_printf("<%d>", ft_printf("[%d]", -1));
	//ft_putstr("\n");
	//ft_printf("<%d>", ft_printf("[%d]", -9));
	//ft_putstr("\n");
	//ft_printf("<%d>", ft_printf("[%d]", -10));
	//ft_putstr("\n");
	//ft_printf("<%d>", ft_printf("[%p]", ULONG_MAX));
	//ft_putstr("\n");
	//ft_printf("<%d>", ft_printf(" %p %p ", 0, 0));
	//ft_putstr("\n");
	////ft_printf("<%d>", ft_printf(" %x ", 9223372036854775807LL));
	//ft_putstr("\n");
	//ft_printf("  <%d>", ft_printf(" NULL %s NULL ", (char *)NULL));
	//ft_putstr("\n");
	//printf(" NULL %s NULL ", (char *)NULL);
	//printf("[%s]", (char *)NULL);
	//ft_printf("  <%d>", ft_printf(" %x ", -10));
	//ft_putstr("\n");
	//printf("  <%d>", printf(" %x ", -10));

	ft_printf("  <%d>", ft_printf(" %p %p ", 0, 0));
	ft_putstr("\n");
	printf("  <%d>", printf(" %p %p ", (void *)0, (void *)0));
	
	//ft_putstr("\n\n");
	//ft_printf("  <%d>", ft_printf(" %x ", -1));
	//ft_putstr("\n");
	//printf("  <%d>", printf(" %x ", -1));
	//printf("-ULONG_MAX>%lu\n", -ULONG_MAX);

	//ft_printf("[%d]\n", 0);
	//ft_printf("[%d]\n", -1);
}


//TEST(2, print(" %c ", '0'));
//27: 	TEST(3, print(" %c", '0' - 256));
//29: 	TEST(5, print(" %c %c %c ", '0', 0, '1'));
//30: 	TEST(6, print(" %c %c %c ", ' ', ' ', ' '));
//31: 	TEST(7, print(" %c %c %c ", '1', '2', '3'));
//32: 	TEST(8, print(" %c %c %c ", '2', '1', 0));
//33: 	TEST(9, print(" %c %c %c ", 0, '1', '2'));