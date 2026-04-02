/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swetting <swetting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/01 17:21:18 by swetting      #+#    #+#                 */
/*   Updated: 2026/04/02 14:38:16 by swetting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

int		ft_printf(const char *format, ...);

int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_strlen(const char *s);
void	ft_putnbr_base(long	nbr, char *base, int unsigned_true);
void	ft_putpointer(unsigned long nbr, char *base);
int		call_putnbr(long nbr, char *base, int unsigned_true);
int		call_putpointer(unsigned long nbr, char *base);
int		numb_len(long long number, int base);

int		call_putnbru(unsigned int nbr, char *base);
void	ft_putnbr_baseu(unsigned int number, char *base);

#endif