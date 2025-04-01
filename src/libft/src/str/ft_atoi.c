/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:45:20 by lpatin            #+#    #+#             */
/*   Updated: 2024/10/29 14:01:29 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	temp;

	i = 0;
	sign = 1;
	temp = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign -= (nptr[i] == '-') * 2;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		temp = temp * 10 + (nptr[i++] - '0');
	return (temp * sign);
}

/*#include <stdio.h>
int main(void)
{
	char jesaispas[] = "-124812";
	printf("%d", ft_atoi(jesaispas));
	return(0);
}*/