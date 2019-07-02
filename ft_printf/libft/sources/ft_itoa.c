/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:21:33 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/26 12:39:12 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				rang_bang(int n)
{
	int					i;
	unsigned int		nb;

	nb = 0;
	i = 1;
	if (n < 0)
	{
		i++;
		nb = -1 * n;
	}
	else
		nb = n;
	while (nb / 10 > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static char				*while_plus(char *str, int sgn, int i, unsigned int nb)
{
	int q;

	q = i + sgn;
	while (q-- > 0)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	return (str);
}

static char				*while_minus(char *str, int sgn, int i, unsigned int nb)
{
	int q;

	q = i + sgn;
	while (--q > 0)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	return (str);
}

char					*ft_itoa(int n)
{
	char				*str;
	int					i;
	unsigned int		nb;

	i = rang_bang(n);
	nb = n;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = n * -1;
		while_minus(str, 1, (i - 1), nb);
	}
	else
		while_plus(str, 1, (i - 1), nb);
	return (str);
}
