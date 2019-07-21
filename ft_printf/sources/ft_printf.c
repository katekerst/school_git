/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:06:14 by siolive           #+#    #+#             */
/*   Updated: 2019/07/21 13:09:27 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	play_with_conversation(va_list args, char *pointer, t_option *opt)
{
	if (*pointer == 'd')
		play_with_decemal(args, opt);
	else if (*pointer == 'i')
		play_with_decemal(args, opt);
	else if (*pointer == 'o')
		play_with_oct(args, opt);
	else if (*pointer == 'u')
		play_with_unsigned_int(args, opt);
	else if (*pointer == 'x')
		play_with_hex(args, opt);
	else if (*pointer == 'X')
		play_with_hex_big(args, opt);
	else if (*pointer == 's')
		play_with_string(args, opt);
	else if (*pointer == 'c')
		play_with_char(args, opt);
	else if (*pointer == '%')
		play_with_promile(opt);
	else if (*pointer == 'p')
		play_with_pointer(args, opt);
	else if (*pointer == 'f')
		play_with_floats(args, opt);
	else if (*pointer == '\0')
		ft_putchar('\n');
}

char	*lets_play(va_list args, char *pointer, t_option *opt)
{
	int			i;
	char		*buff;

	i = 0;
	buff = ft_strnew(BUFF_SIZE);
	opt = clear_option(opt);
	while (!have_conversion(pointer))
	{
		buff[i] = *pointer;
		i++;
		pointer++;
	}
	opt = change_opt(opt, buff, 0, 0);
	ft_strdel(&buff);
	if (have_conversion(pointer))
	{
		play_with_conversation(args, pointer, opt);
		pointer++;
	}
	return (pointer);
}

void	ft_move_point(char *pointer, va_list args, t_option *opt)
{
	while (*pointer != '\0')
	{
		if (*pointer == '%')
		{
			pointer++;
			if (*pointer == '\0')
			{
				ft_putchar(*pointer);
				return ;
			}
			pointer = lets_play(args, pointer, opt);
		}
		else
		{
			ft_putchar(*pointer);
			pointer++;
			opt->count++;
		}
	}
}

int		ft_printf(char *string, ...)
{
	char		*pointer;
	char		*work_string;
	va_list		args;
	t_option	*opt;

	opt = NULL;
	opt = make_opt(0);
	work_string = ft_strdup(string);
	va_start(args, string);
	pointer = work_string;
	ft_move_point(pointer, args, opt);
	va_end(args);
	free(work_string);
	free(opt);
	return (opt->count);
}
