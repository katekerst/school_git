/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_%_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:30:40 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/10 11:55:55 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

void	play_with_char(va_list args, t_option *options)
{
	char	res;
	char	*out;

	res = va_arg(args, int);
	if (res == 0)
	{
		if (options->w_dec != 0)
			options->count += options->w_dec;
		else
			options->count += 1;
		while (options->w_dec-- > 1)
			ft_putchar(' ');
		ft_putchar(res);
		return ;
	}
	out = ft_strnew(2);
	*out = res;
	if (options->f_minus)
		out = ft_strjoin(out, str_char_in(options->w_dec
		- ft_strlen(out), ' '));
	else
		out = ft_strjoin(str_char_in((options->w_dec
		- ft_strlen(out)), ' '), out);
	options->count += ft_strlen(out);
	ft_putstr(out);
}

void	play_with_promile(t_option *options)
{
	char	res;
	char	*out;

	res = '%';
	out = ft_strnew(2);
	*out = res;
	if (options->f_minus)
		out = ft_strjoin(out, str_char_in(options->w_dec
		- ft_strlen(out), ' '));
	else if (options->w_zero_dec)
		out = ft_strjoin(str_char_in((options->w_dec
		- ft_strlen(out)), '0'), out);
	else
		out = ft_strjoin(str_char_in((options->w_dec
		- ft_strlen(out)), ' '), out);
	options->count += ft_strlen(out);
	ft_putstr(out);
}
