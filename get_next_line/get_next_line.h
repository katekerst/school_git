/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 10:59:18 by siolive           #+#    #+#             */
/*   Updated: 2019/04/23 14:42:44 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"

int get_next_line(const int fd, char **line);

#endif
