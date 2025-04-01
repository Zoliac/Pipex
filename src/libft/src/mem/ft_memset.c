/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:02:40 by lpatin            #+#    #+#             */
/*   Updated: 2025/03/25 23:27:00 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*i;
	size_t			coucou;

	coucou = 0;
	i = (unsigned char *)s;
	while (coucou < n)
	{
		i[coucou] = (unsigned char)c;
		coucou++;
	}
	return (s);
}
