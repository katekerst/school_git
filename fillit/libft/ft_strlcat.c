/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:25:54 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/18 11:17:13 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t nb)
{
	size_t	l_dest;
	size_t	l_source;

	l_dest = ft_strlen(dest);
	l_source = ft_strlen(source);
	if (nb < (l_dest + 1) || nb == 0)
	{
		if (nb)
			ft_strncat(dest, source, 0);
		return (l_source + nb);
	}
	else
		ft_strncat(dest, source, nb - l_dest - 1);
	return (l_dest + l_source);
}
