/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 10:59:18 by siolive           #+#    #+#             */
/*   Updated: 2019/07/25 15:21:23 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft.h"

int get_next_line(const int fd, char **line);

#endif
