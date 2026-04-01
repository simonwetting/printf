/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 17:21:18 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/01 17:28:29 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

void	ft_putchar(int c);
void	ft_putstr(char *s);
int		ft_strlen(const char *s);
void	ft_putnbr_base(int	nbr, char *base, int unsigned_true, int is_pointer);
int		ft_printf(const char *format, ...);

#endif