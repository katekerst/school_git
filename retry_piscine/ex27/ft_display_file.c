/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:57:26 by siolive           #+#    #+#             */
/*   Updated: 2019/04/02 18:14:07 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	int		count;
	char	buffer[4097];

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		count = read(fd, buffer, 4096);
		buffer[count] = '\0';
		ft_putstr(buffer);
		close(fd);
	}
	else if (argc == 1)
		ft_putstr("File name missing.\n");
	else
		ft_putstr("Too many arguments.\n");
	return (0);
}
