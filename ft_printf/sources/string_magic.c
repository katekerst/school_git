/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_magic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:02:01 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/24 12:01:40 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void		tsr(char *our_str, char *source)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (source)
	{
		while (our_str[i] != '\0')
			i++;
		while (source[j] != '\0')
		{
			our_str[i] = source[j];
			i++;
			j++;
		}
		our_str[i] = '\0';
	}
}

void		tsraf(char *our_str, char *source)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (source)
	{
		while (our_str[i] != '\0')
			i++;
		while (source[j] != '\0')
		{
			our_str[i] = source[j];
			i++;
			j++;
		}
		our_str[i] = '\0';
		ft_strdel(&source);
	}
}

void		tsl(char *out_str, char *source)
{
	int		i;
	int		j;
	char	*start;

	if (source)
	{
		i = ft_strlen(out_str);
		j = ft_strlen(source);
		while (i >= 0)
		{
			out_str[i + j] = out_str[i];
			out_str[i] = '\0';
			i--;
		}
		i = 0;
		while (i < j)
		{
			out_str[i] = source[i];
			i++;
		}
	}
}

void		tslaf(char *out_str, char *source)
{
	int		i;
	int		j;

	if (source)
	{
		i = ft_strlen(out_str);
		j = ft_strlen(source);
		while (i >= 0)
		{
			out_str[i + j] = out_str[i];
			out_str[i] = '\0';
			i--;
		}
		i = 0;
		while (i < j)
		{
			out_str[i] = source[i];
			i++;
		}
	}
	ft_strdel(&source);
}
