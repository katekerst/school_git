/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:00:07 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/23 12:22:55 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *source, int litera, size_t nb)
{
	unsigned char	*str;
	unsigned char	sym;

	str = (unsigned char *)source;
	sym = (unsigned char)litera;
	while (nb--)
	{
		if (*str == sym)
			return (str);
		str++;
	}
	return (NULL);
}
