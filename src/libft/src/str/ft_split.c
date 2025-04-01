/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpatin <lpatin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:28:00 by lpatin            #+#    #+#             */
/*   Updated: 2024/12/06 18:42:59 by lpatin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	countwords(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	*needfree(char **result, int i)
{
	while (i-- > 0)
		free(result[i]);
	free(result);
	return (NULL);
}

static char	*next_word(const char *s, char c, int *start)
{
	int		end;
	char	*word;

	end = *start;
	while (s[end] && s[end] != c)
		end++;
	word = ft_substr(s, *start, end - *start);
	*start = end;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		count;
	char	**result;

	if (!s)
		return (NULL);
	count = countwords(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < count)
	{
		while (s[start] && s[start] == c)
			start++;
		result[i] = next_word(s, c, &start);
		if (!result[i++])
			return (needfree(result, i - 1));
	}
	result[i] = 0;
	return (result);
}
