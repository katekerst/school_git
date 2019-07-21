/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:19:14 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/13 14:48:20 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

static t_option	*change_opt_first(t_option *opt, char *buff, int *i, int *qt)
{
	if (buff[*i] == '+')
	{
		opt->f_plus = TRUE;
		(*qt)++;
	}
	else if (buff[*i] == '-')
	{
		opt->f_minus = TRUE;
		(*qt)++;
	}
	else if (buff[*i] == '#')
	{
		opt->f_hash = TRUE;
		(*qt)++;
	}
	else if (buff[*i] == ' ')
	{
		opt->f_space = TRUE;
		(*qt)++;
	}
	return (opt);
}

static t_option	*change_opt_third(t_option *opt, char *buff, int *i, int *qt)
{
	if (buff[*i] == 'l')
	{
		if (buff[*i + 1] == 'l')
		{
			opt->m_ll = TRUE;
			(*i) += 2;
			(*qt)++;
		}
		else
		{
			opt->m_l = TRUE;
			(*i)++;
			(*qt)++;
		}
	}
	return (opt);
}

static t_option	*change_opt_sec(t_option *opt, char *buff, int *i, int *qt)
{
	if (buff[*i] == 'h')
	{
		if (buff[*i + 1] == 'h')
		{
			opt->m_hh = TRUE;
			(*i) += 2;
			(*qt)++;
		}
		else
		{
			opt->m_h = TRUE;
			(*i)++;
			(*qt)++;
		}
	}
	else if (buff[*i] == 'L')
	{
		opt->m_big_l = TRUE;
		(*qt)++;
	}
	else if ((opt = change_opt_third(opt, buff, i, qt)) && (*qt) != 0)
		qt = 0;
	return (opt);
}

static t_option	*change_opt_fourth(t_option *opt, char *buff, int *i, int *qt)
{
	if (buff[(*i)] == '0')
		opt->w_zero_dec = TRUE;
	else if (buff[(*i)] == '.' && !ft_isdigit(buff[(*i) + 1]))
	{
		opt->a_have_dot = TRUE;
		opt->a_dec = 0;
		(*qt)++;
	}
	else if (buff[(*i)] == '.')
	{
		(*i)++;
		opt->a_have_dot = TRUE;
		while (buff[(*i)] >= '0' && buff[(*i)] <= '9')
		{
			opt->a_dec = opt->a_dec * 10 + buff[(*i)] - 48;
			(*i)++;
			(*qt)++;
		}
	}
	return (opt);
}

t_option		*change_opt(t_option *opt, char *buff, int i, int qt)
{
	while (buff[i])
	{
		if ((opt = change_opt_first(opt, buff, &i, &qt)) && qt != 0)
			qt = 0;
		else if (buff[i] >= '1' && buff[i] <= '9' && !opt->w_star)
		{
			while ((buff[i] >= '0' && buff[i] <= '9'))
			{
				opt->w_dec = opt->w_dec * 10 + buff[i] - 48;
				i++;
			}
			if (buff[i] == '.')
				continue;
		}
		else if ((opt = change_opt_fourth(opt, buff, &i, &qt)) && qt != 0)
			qt = 0;
		else if ((opt = change_opt_sec(opt, buff, &i, &qt)) && qt != 0)
			qt = 0;
		i++;
	}
	if (opt->f_plus == TRUE && opt->f_space == TRUE)
		opt->f_space = FALSE;
	if (opt->f_minus == TRUE && opt->w_zero_dec == TRUE)
		opt->w_zero_dec = FALSE;
	return (opt);
}
