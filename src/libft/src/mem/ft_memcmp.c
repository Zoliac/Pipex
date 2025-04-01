/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:45:33 by lpatin            #+#    #+#             */
/*   Updated: 2024/10/21 13:45:47 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_bis;
	unsigned char	*s2_bis;
	size_t			i;

	s1_bis = (unsigned char *)s1;
	s2_bis = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_bis[i] < s2_bis[i])
			return (s1_bis[i] - s2_bis[i]);
		else if (s1_bis[i] > s2_bis[i])
			return (s1_bis[i] - s2_bis[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int main(void)
{
    char str1[] = "Hello";
    char str2[] = "He'\'lLo";
	printf("%d", ft_memcmp(str1, str2, 6));
	return (0);
}*/