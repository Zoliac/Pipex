/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:09:34 by lpatin            #+#    #+#             */
/*   Updated: 2024/10/17 14:26:27 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	b;
	size_t	i;

	a = 0;
	b = 0;
	i = 0;
	while (dst[a] && a < size)
		a++;
	while (src[b])
		b++;
	if (a >= size)
		return (size + b);
	i = 0;
	while (src[i] && (a + i) < (size - 1))
	{
		dst[a + i] = src[i];
		i++;
	}
	dst[a + i] = '\0';
	return (a + b);
}

/*#include <stdio.h>
int main()
{
    char dest[] = "Hello ";
    char src[] = "World";
    unsigned int size = 5;

    printf("%zu\n", ft_strlcat(dest, src, size));
    return 0;
}*/