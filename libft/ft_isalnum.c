/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:25:11 by siolive           #+#    #+#             */
/*   Updated: 2019/04/09 12:37:35 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	int	result;

	result = ft_isdigit(c) + ft_isalpha(c);
	if (result == 1)
		return (1);
	else
		return (0);
}
