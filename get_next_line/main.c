/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:39:01 by siolive           #+#    #+#             */
/*   Updated: 2019/04/24 12:41:34 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
    int     i;
    int     fd;
    char    *line;

    if (argc == 2)
    {
        i = 0;
        fd = open(argv[1], O_RDONLY);
        while (get_next_line(fd, &line) == 1)
        {
            ft_putstr(line);
            ft_putchar('\n');
        }
        close(fd);
    }
    return (0);
}