/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:33:21 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/10 17:56:10 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		set(int nbr)
{
	if (nbr >= 10)
		return ('a' - 10 + nbr);
	else if (nbr < 0)
		return (-nbr + '0');
	else
		return (nbr + '0');
}

static int		numlen(long long nbr, int base)
{
	int			len;

	len = 0;
	if (!nbr)
		return (2);
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char			*ft_itoa_base(long long nbr, int base)
{
	char		*str;
	long long	stand;
	int			x;

	x = numlen(nbr, base) - 1;
	str = ft_memalloc(x + 2);
	if (!nbr)
		str[0] = '0';
	stand = nbr;
	if (nbr < 0)
		stand = nbr * -1;
	while (stand)
	{
		str[x] = set(stand % base);
		stand /= base;
		x--;
	}
	return (str);
}
