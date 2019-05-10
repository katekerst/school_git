/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:53:56 by siolive           #+#    #+#             */
/*   Updated: 2019/05/10 12:04:12 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void    ft_free_tetraminos(t_list   *tetraminos)
{
    t_tetras    *figure;
    t_list      *current;

    while (tetraminos)
    {
        figure = tetraminos->content;
        current = tetraminos->next;
        ft_memdel((void **)&figure);
        ft_memdel((void **)&tetraminos);
        tetraminos = current;
    }
}