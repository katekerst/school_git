/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:34:48 by siolive           #+#    #+#             */
/*   Updated: 2019/05/09 14:44:40 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct  s_tetras
{
    int     num;
    int     *x;
    int     *y;
    char    letter;
}               t_tetras;

typedef struct s_square
{
    /*data*/
}               t_square;

t_list  *ft_read_tetraminos(int fd);
int     ft_check_block(char *buffer, int ret);
int     ft_check_figure(char *buffer);
t_tetras    *ft_newtetra(char *buffer, char let);
t_list      *ft_newfigure(t_list *figure, t_tetras *tetramino);