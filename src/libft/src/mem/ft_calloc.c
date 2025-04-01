/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:42:44 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/26 18:41:16 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
int main(void)
{
	size_t idk = 5;
	size_t taille = sizeof(int);
	int *tab;

	tab = (int *)ft_calloc(idk, taille);
	if (!tab)
	{
		printf("Calloc echoue\n");
		return (1);
	}
	printf("%p",tab);
	free(tab);
	return (0);
}
*/