/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:07:24 by gbellege          #+#    #+#             */
/*   Updated: 2019/05/16 13:19:23 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	t_tetra		*tetramino;
	t_map		*map_option;
	int			fd;

	if (argc == 2)
	{
		tetramino = NULL;
		if ((fd = open(argv[1], O_RDONLY)) <= 0)
			check_open(fd);
		tetramino = ft_read_tetraminos(fd, tetramino);
		check_close(fd);
		map_option = ft_create_map_option(&tetramino);
		get_solution(tetramino, map_option);
	}
	else
		ft_putstr_fd("usage: fillit file\n", 2);
	return (0);
}
