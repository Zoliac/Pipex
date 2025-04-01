/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:06:19 by lpatin            #+#    #+#             */
/*   Updated: 2024/10/18 18:15:54 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	other_c;

	str = (unsigned char *)s;
	other_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (other_c == str[i])
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int main(void)
{
    char texte[] = "Hello, World!";
    char *resultat = ft_memchr(texte, ',', 14);
	printf("%s", resultat);
	return (0);
}*/
