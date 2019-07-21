/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:18:21 by siolive           #+#    #+#             */
/*   Updated: 2019/07/20 19:03:30 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

int			string_have_conversation(char *str)
{
	while (*str != '\0')
	{
		if (have_conversion(str))
			return (1);
		str++;
	}
	return (0);
}

int			have_conversion(char *pointer)
{
	if (*pointer == 'd' || *pointer == 'i' || *pointer == 'o'
	|| *pointer == 'u' || *pointer == 'x' || *pointer == 'X'
	|| *pointer == 's' || *pointer == 'c' || *pointer == '%'
	|| *pointer == 'p' || *pointer == 'f')
		return (1);
	else
		return (0);
}

void		ft_del_sim_in_str(char *our_str, int how_many_sym_del)
{
	int		i;
	int		j;
	int		k;

	i = how_many_sym_del;
	j = ft_strlen(our_str);
	k = 0;
	while ((j - how_many_sym_del) > 0)
	{
		our_str[k] = our_str[k + how_many_sym_del];
		our_str[k + how_many_sym_del] = 0;
		k++;
		j--;
	}
}
