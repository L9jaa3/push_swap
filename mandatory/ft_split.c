/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ielouarr <ielouarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:36:02 by ielouarr          #+#    #+#             */
/*   Updated: 2025/02/06 15:47:54 by ielouarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	count_words(const char *str, char delimiter)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != delimiter && (i == 0 || str[i - 1] == delimiter))
			count++;
		i++;
	}
	return (count);
}

static char	*allocate_word(const char *str, char delimiter, size_t *i)
{
	size_t	start;
	size_t	len;
	char	*word;

	start = *i;
	len = 0;
	while (str[*i] && str[*i] != delimiter)
	{
		(*i)++;
		len++;
	}
	word = (char *)(malloc((len + 1) * sizeof(char)));
	if (!word)
		return (NULL);
	len = 0;
	while (start < *i)
	{
		word[len] = str[start];
		len++;
		start++;
	}
	word[len] = '\0';
	return (word);
}

static char	**free_split_result(char **result, size_t j)
{
	while (j > 0)
		free(result[--j]);
	free(result);
	return (NULL);
}

char	**ft_split(const char *str, char delimiter)
{
	char	**result;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	result = (malloc((count_words(str, delimiter) + 1) * sizeof(char *)));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != delimiter && (i == 0 || str[i - 1] == delimiter))
		{
			result[j] = allocate_word(str, delimiter, &i);
			if (!result[j])
				return (free_split_result(result, j));
			j++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}
