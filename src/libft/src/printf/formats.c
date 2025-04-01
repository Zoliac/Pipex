/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:53:51 by lpatin            #+#    #+#             */
/*   Updated: 2024/12/02 16:56:03 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "others.h"

int	formatting(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_puthexa(va_arg(args, unsigned int), count);
	else if (*format == 'X')
		count += ft_puthexa_upp(va_arg(args, unsigned int), count);
	else if (*format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (*format == '%')
		count = ft_putchar('%');
	return (count);
}
