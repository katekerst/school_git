/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:25:08 by siolive           #+#    #+#             */
/*   Updated: 2019/07/09 16:45:01 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

char	*str_char_in(const int i, const char c)
{
	char		*str;
	int 		j;

 	j = 0;
	str = ft_strnew(i);
  	while (j < i)
	  {
			str[j] = c;
			j++;
	  }
	return (str);
}

void	play_with_conversation(va_list args, char *pointer, t_option *options)
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
		ft_putstr(play_with_hex(args, options));
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
    {
        ft_putendl("Voshla");
		trans_float(play_with_floats(args, options), options);
        ft_putendl("Vishla");
    }
}

int     string_have_conversation(char *str)
{
    while(*str != '\0')
    {
        if(have_conversion(str) == 1)
            return (1);
        str++;
    }
    return (0);
}

int		have_conversion(char *pointer)
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
	int			i;
	char		*buff;

	i = 0;
	buff = (char *)ft_memalloc(BUFF_SIZE * sizeof(char));
	options = clear_option(options);
	while (!have_conversion(pointer))
	{
		buff[i] = *pointer;
		i++;
		pointer++;
	}
	options = change_options(options, buff, args);
	ft_strdel(&buff);
    // print_options(options);
	if (have_conversion(pointer))
		{
			play_with_conversation(args, pointer, options);
			pointer++;
		}
	return (pointer);
}

int		ft_printf(char *string, ...)
{
	char    	*pointer;
	char		*work_string;
	va_list		args;
	t_option	*options = NULL;

	options = make_options(0);
	work_string = ft_strdup(string);
	va_start(args, string);
	pointer = work_string;
	while(*pointer != '\0')
	{
		if(*pointer == '%')
			{
                // if(string_have_conversation(pointer))
				// {
                    pointer++;
				    pointer = lets_play(args, pointer, options);
                // }
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
