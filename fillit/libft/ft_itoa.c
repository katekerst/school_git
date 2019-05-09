/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:17:37 by siolive           #+#    #+#             */
/*   Updated: 2019/04/15 14:43:50 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countsigns(int n)
{
	int		count;

	count = 0;
	if (n <= 0)
	{
		if (n == -2147483648)
			return (11);
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		t;

	length = ft_countsigns(n);
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	str[length] = '\0';
	length--;
	t = n;
	while (length >= 0)
	{
		str[length] = ABS(t % 10) + '0';
		t /= 10;
		length--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
