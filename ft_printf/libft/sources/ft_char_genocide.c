/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_genocide.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 18:35:42 by gbellege          #+#    #+#             */
/*   Updated: 2019/06/21 13:14:22 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_char_genocide(char *string, char to_genocide)
{
	char	*string_after_genocide;
	int		i;
	int		j;

	i = 0;
	j = 0;
	string_after_genocide = ft_strnew(ft_strlen(string));
	while (string[i] != '\0')
	{
		if (string[i] != to_genocide)
		{
			string_after_genocide[j] = string[i];
			j++;
			i++;
		}
		else
			i++;
	}
	free(string);
	return (string_after_genocide);
}
