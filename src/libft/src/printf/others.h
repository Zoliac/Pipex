/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:57:59 by lpatin            #+#    #+#             */
/*   Updated: 2024/11/07 16:20:07 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHERS_H
# define OTHERS_H
# include <stdarg.h>
# include <unistd.h>
# include "ft_printf.h"

int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putptr(void *ptr);
int	ft_puthexa(unsigned long n, int nb);
int	ft_putunsigned(unsigned int n);
int	formatting(const char *format, va_list args);
int	ft_putchar(char c);
int	ft_toupper(int c);
int	ft_puthexa_upp(unsigned long nb, int n);

#endif