/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:10:24 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/30 11:09:43 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *source, int litera)
{
	unsigned int	i;

	i = 0;
	if (!(source))
		return (NULL);
	while (source[i])
	{
		if (source[i] == litera)
		{
			source += i;
			return ((char *)source);
		}
		i++;
	}
	if (source[i] == litera)
	{
		source += i;
		return ((char *)(source));
	}
	return (NULL);
}
