/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:05:24 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/23 14:32:22 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new_str;

	new_str = NULL;
	if (s && f)
		new_str = ft_strnew(ft_strlen(s));
	if (new_str)
	{
		i = -1;
		while (s[++i])
			new_str[i] = f(s[i]);
		new_str[i] = '\0';
	}
	return (new_str);
}
