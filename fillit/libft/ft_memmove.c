/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:55:49 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/27 15:40:50 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *source, size_t nb)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)source;
	if (d < s)
		while (nb--)
			*d++ = *s++;
	else
	{
		d = d + nb;
		s = s + nb;
		while (nb--)
			*--d = *--s;
	}
	return (dest);
}
