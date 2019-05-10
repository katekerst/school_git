/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:34:04 by siolive           #+#    #+#             */
/*   Updated: 2019/05/09 13:34:04 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "fillit.h"

int main(int argc, char **argv)
{
    t_list      *tetraminos;
    t_square    *square; 
    int          fd;
    t_tetras    *done;
    t_list      *current;

    if (argc != 2)
    {
        ft_putstr("error first\n");
        return (1);
    }
    if ((fd = open(argv[1], O_RDONLY)) <= 0)
    {
        ft_putstr("error second\n");
        return (1);
    }
    tetraminos = ft_read_tetraminos(fd);
    if (tetraminos == NULL)
    {
        ft_putstr("error third\n");
        return (1);
    }
    current = tetraminos;
    while (current)
    {
        done = current->content;
        printf("tetraminos x is %d\n", done->x[0]);
        printf("tetraminos x1 is %d\n", done->x[1]);
        printf("tetraminos x2 is %d\n", done->x[2]);
        printf("tetraminos letter is %c\n", done->letter);
         printf("tetraminos y is %d\n", done->y[0]);
        printf("tetraminos y1 is %d\n", done->y[1]);
        printf("tetraminos y2 is %d\n", done->y[2]);
        current = current->next;
    }
    // square = ft_solution(tetraminos);
    // ft_print_solution(square);
    // free_square(square);
    ft_free_tetraminos(tetraminos);
    return (0);
}