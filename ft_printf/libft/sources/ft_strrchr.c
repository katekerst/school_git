/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:38:31 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/18 11:47:04 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *source, int litera)
{
	unsigned int	i;
	unsigned int	lit_pos;
	unsigned int	qt;

	i = 0;
	qt = 0;
	while (source[i] != '\0')
	{
		if (source[i] == litera)
		{
			lit_pos = i;
			qt++;
		}
		i++;
	}
	if (source[i] == litera)
	{
		qt++;
		lit_pos = i;
	}
	if (qt == 0)
		return (NULL);
	else
		source += lit_pos;
	return ((char *)(source));
}
