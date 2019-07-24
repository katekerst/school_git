/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:05:02 by siolive           #+#    #+#             */
/*   Updated: 2019/07/24 12:16:22 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"
#include <stdio.h>

static void		ft_round3(char **string, int *i, int j)
{
	int			k;
	int			tmp;
	char		*copy;

	copy = *string;
	k = *i;
	while (copy[*i] != '.' && copy[*i])
		(*i)++;
	tmp = copy[*i];
	copy[*i] = copy[*i + 1];
	copy[*i + 1] = tmp;
	*i = k;
	while (j-- > 0)
	{
		if (copy[*i] == '.')
		{
			(*i)++;
			continue ;
		}
		copy[(*i)++] = '0';
	}
}

static void		ft_round2(char **string, int *i, int j)
{
	char		*copy;

	copy = *string;
	while ((copy[*i] == '9' || copy[*i] == '.') && *i >= 0)
	{
		(*i)--;
		j++;
	}
	if (*i == -1)
	{
		*i = 0;
		copy[*i] = '1';
	}
	else
		copy[*i] += 1;
	(*i)++;
	ft_round3(&copy, i, j);
}

void			ft_round(char **string, long double n, int *i)
{
	char		*copy;
	int			j;

	j = 0;
	copy = *string;
	if ((int)n >= 5)
	{
		if (copy[*i - 1] == '9')
		{
			(*i)--;
			ft_round2(&copy, i, j);
		}
		else
			copy[*i - 1]++;
	}
}

void			ft_right_part(char **string, long double n,
	int *i, int precision)
{
	int			j;
	int			temp;
	char		*copy;

	j = 0;
	n *= 10;
	copy = *string;
	if (precision >= 1)
		copy[(*i)++] = '.';
	while (j++ < precision)
	{
		temp = (int)n;
		copy[*i] = temp + 48;
		n = (n - temp) * 10;
		(*i)++;
	}
	ft_round(&copy, n, i);
	copy[*i] = '\0';
}

void			ft_left_part(char **str, long double *n,
	int *i, long double decs)
{
	char		*copy;
	long double temp;

	copy = *str;
	while ((long long)decs != 0)
	{
		copy[(*i)++] = (char)((*n) / decs) + 48;
		temp = ((copy[*i - 1] - 48) * decs);
		*n -= temp;
		decs /= 10;
	}
}
