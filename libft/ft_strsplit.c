/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:21:50 by siolive           #+#    #+#             */
/*   Updated: 2019/04/16 13:31:43 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int		result;

	result = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != c && *s)
		{
			result++;
			while (*s && *s != c)
				s++;
		}
	}
	return (result);
}

static int	ft_lettercount(const char *s, char c)
{
	int count;

	count = 0;
	while (*s != c && *s)
	{
		s++;
		count++;
	}
	return (count);
}

static void	ft_freearray(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

static char	**ft_array_copy(char **array, const char *s, char c, int words)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	while (*s != '\0' && words > 0)
	{
		i = 0;
		k = 0;
		while (*s && *s == c)
			s++;
		i = ft_lettercount(s, c);
		if (!(array[j] = (char *)malloc(sizeof(char) * (i + 1))))
		{
			ft_freearray(array);
			return (array);
		}
		while (k < i)
			array[j][k++] = *(s++);
		array[j][k] = '\0';
		j++;
		words--;
	}
	array[j] = 0;
	return (array);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		words;

	if (!s || !c)
		return (NULL);
	words = ft_wordcount(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
		return (NULL);
	array = ft_array_copy(array, s, c, words);
	return (array);
}
