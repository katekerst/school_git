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

    if (argc != 2)
    {
        ft_error();
        return (1);
    }
    if ((fd = open(argv[1], O_RDONLY)) <= 0)
    {
        ft_putstr("error\n");
        return (1);
    }
    tetraminos = ft_read_tetraminos(fd);
    if (tetraminos == NULL)
    {
        ft_putstr("error\n");
        return (1);
    }
    square = ft_solution(tetraminos);
    ft_print_solution(square);
    free_square(square);
    free_tetraminos(tetraminos);
    return (0);
}