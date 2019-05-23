/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:38:29 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/23 15:27:36 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			new_str[i] = f(i, s[i]);
		new_str[i] = '\0';
	}
	return (new_str);
}
