/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:48:20 by siolive           #+#    #+#             */
/*   Updated: 2019/04/02 17:50:51 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char *))
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (tab[i] != '\0')
	{
		if (f(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}
