/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:08:36 by lpatin            #+#    #+#             */
/*   Updated: 2024/11/07 16:43:43 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "others.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

int	ft_putptr(void *ptr)
{
	unsigned long	nb;
	int				i;

	nb = (unsigned long)ptr;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = ft_putstr("0x");
	return (ft_puthexa(nb, i));
}

int	ft_puthexa(unsigned long n, int nb)
{
	char	*basehex;

	basehex = "0123456789abcdef";
	if (n >= 16)
		nb = ft_puthexa(n / 16, nb);
	nb += ft_putchar(basehex[n % 16]);
	return (nb);
}

int	ft_puthexa_upp(unsigned long nb, int n)
{
	char	*basehex;

	basehex = "0123456789abcdef";
	if (nb > 15)
		n += ft_puthexa_upp(nb / 16, n);
	n += ft_putchar(ft_toupper(basehex[nb % 16]));
	return (n);
}
