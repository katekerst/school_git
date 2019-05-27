/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:07:14 by gbellege          #+#    #+#             */
/*   Updated: 2019/04/27 15:10:59 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_destroy_arr(void **ap)
{
	while (ap)
	{
		free(*ap);
		*ap = NULL;
		ap++;
	}
	free(ap);
}