/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:50:10 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/02 14:44:28 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"
#include <stdio.h>


char	*str_char_in(const int i, const char c)
{
	char	*str;
	int j;

 	j = 0;
	str = ft_strnew(i);
  	while (j < i)
	  {
			str[j] = c;
			j++;
	  }
	return (str);
}

void	play_with_conversation(va_list args, char *pointer, t_option *options)	// must to expand
{
	if (*pointer == 'd')
		play_with_decemal(args, options);
	else if (*pointer == 'i')
		play_with_decemal(args, options);
	else if (*pointer == 'o')
		play_with_oct(args, options);
	else if (*pointer == 'u')
		play_with_unsigned_int(args, options);
	else if (*pointer == 'x')
		play_with_hex(args, options);
	else if (*pointer == 'X')
		play_with_hex_big(args, options);
	else if (*pointer == 's')
		play_with_string(args, options);
	else if (*pointer == 'c')
		play_with_char(args, options);
	else if (*pointer == '%')
		play_with_promile(options);
	else if (*pointer == 'p')
		play_with_pointer(args, options);
	else if (*pointer == 'f')
		trans_float(play_with_floats(args, options), options);
}

int		have_conversion(char *pointer) // must to expand
{
	if (*pointer == 'd' || *pointer == 'i' || *pointer == 'o'
            || *pointer == 'u' || *pointer == 'x' || *pointer =='X'
            || *pointer == 's' || *pointer == 'c' || *pointer == '%'
            || *pointer == 'p' || *pointer == 'f')
		return (1);
	else
		return (0);
}


char	*lets_play(va_list args, char *pointer, t_option *options)
{
	int		i;
	char	*buff;

	i = 0;
	buff = (char *)ft_memalloc(BUFF_SIZE * sizeof(char));
	options = clear_option(options); //сделано чтоб компилятор не жаловался на некоторое время
	while (!have_conversion(pointer))
	{
		buff[i] = *pointer;
		i++;
		pointer++;
	}
	options = change_options(options, buff, args);
	ft_strdel(&buff);
	// print_options(options); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (have_conversion(pointer))
		{
			play_with_conversation(args, pointer, options); // options!
			pointer++;
		}
	return (pointer);
}

int		ft_printf(char *string, ...)
{
	char    *pointer;
	char	*work_string;
	va_list	args;
	t_option	*options = NULL;

	options = make_options(0);
	work_string = ft_strdup(string);
	va_start(args, string);
	pointer = work_string;

	while(*pointer != '\0')
	{
		if(*pointer == '%')
			{
				pointer++;
				pointer = lets_play(args, pointer, options);///////////
			}
		else
		{
			ft_putchar(*pointer);
			pointer++;
			options->count++;
		}
	}
	va_end(args);
	return (options->count);
}
