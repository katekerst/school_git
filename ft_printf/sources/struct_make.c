/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:35:52 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/24 11:39:44 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"

t_option		*clear_option(t_option *opt)
{
	t_option	*fresh_opt;

	fresh_opt = opt;
	fresh_opt->f_plus = FALSE;
	fresh_opt->f_minus = FALSE;
	fresh_opt->f_hash = FALSE;
	fresh_opt->f_space = FALSE;
	fresh_opt->w_dec = FALSE;
	fresh_opt->w_star = FALSE;
	fresh_opt->w_zero_dec = FALSE;
	fresh_opt->a_have_dot = FALSE;
	fresh_opt->a_dec = FALSE;
	fresh_opt->a_star = FALSE;
	fresh_opt->m_h = FALSE;
	fresh_opt->m_hh = FALSE;
	fresh_opt->m_l = FALSE;
	fresh_opt->m_ll = FALSE;
	fresh_opt->m_big_l = FALSE;
	fresh_opt->is_positive = TRUE;
	ft_bzero((fresh_opt->out), 1001);
	return (fresh_opt);
}

t_option		*make_opt(void)
{
	t_option	*new;

	if ((new = (t_option *)ft_memalloc(sizeof(t_option))))
	{
		new = clear_option(new);
	}
	return (new);
}
