/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:06:52 by lpatin            #+#    #+#             */
/*   Updated: 2024/11/05 23:08:14 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "others.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putstr("-2147483648");
		return (i);
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putunsigned(unsigned int n)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = (unsigned)n;
	if (nbr > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}
