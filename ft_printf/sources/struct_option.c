/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:19:14 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/02 14:44:30 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"







t_option		*clear_option(t_option *options)
{
	t_option	*fresh_options;

	fresh_options = options;
	fresh_options->f_plus = FALSE;
	fresh_options->f_minus = FALSE;
	fresh_options->f_hash = FALSE;
	fresh_options->f_space = FALSE;
	fresh_options->w_dec = FALSE;
	fresh_options->w_star = FALSE;
	fresh_options->w_zero_dec = FALSE;
	fresh_options->a_have_dot = FALSE;
	fresh_options->a_dec = FALSE;
	fresh_options->a_star = FALSE;
	fresh_options->m_h = FALSE;
    fresh_options->m_hh = FALSE;
	fresh_options->m_l = FALSE;
    fresh_options->m_ll = FALSE;
	fresh_options->m_L = FALSE;
	return (fresh_options);
}

t_option	*make_options()
{
	t_option	*new;

	if((new = (t_option *)ft_memalloc(sizeof(t_option))))
		new = clear_option(new);
	return (new);
}

void		print_options(t_option *options)
{

	ft_putstr("options->f_plus      ");
	ft_putendl(ft_itoa(options->f_plus)); // обработал считывание одного минуса
	ft_putstr("options->f_minus     ");
	ft_putendl(ft_itoa(options->f_minus)); // есть считывание
	ft_putstr("options->f_hash      ");
	ft_putendl(ft_itoa(options->f_hash)); // read done
	ft_putstr("options->f_space     ");
	ft_putendl(ft_itoa(options->f_space)); //read done
	ft_putstr("options->w_dec       ");
	ft_putendl(ft_itoa(options->w_dec)); //read done
	ft_putstr("options->w_star      ");
	ft_putendl(ft_itoa(options->w_star));  //read done
	ft_putstr("options->w_zero_dec  ");
	ft_putendl(ft_itoa(options->w_zero_dec)); //read done
 	ft_putstr("options->a_have_dot  ");
	ft_putendl(ft_itoa(options->a_have_dot));
	ft_putstr("options->a_dec       ");
	ft_putendl(ft_itoa(options->a_dec));
	ft_putstr("options->a_star      ");
	ft_putendl(ft_itoa(options->a_star));
	ft_putstr("options->m_hh        ");
	ft_putendl(ft_itoa(options->m_hh));
	ft_putstr("options->m_ll        ");
	ft_putendl(ft_itoa(options->m_ll));
	ft_putstr("options->m_h         ");
	ft_putendl(ft_itoa(options->m_h));
	ft_putstr("options->m_l         ");
	ft_putendl(ft_itoa(options->m_l));
	ft_putstr("options->m_L         ");
	ft_putendl(ft_itoa(options->m_L));

}

t_option	*change_options(t_option *options, char *buff, va_list args)
{
	int		i;

	i = 0;
	while(buff[i])
	{
		if(buff[i] == '+')
			options->f_plus = TRUE;
		else if(buff[i] == '-')
			options->f_minus = TRUE;
		else if(buff[i] == '#')
			options->f_hash = TRUE;
		else if(buff[i] == ' ')
			options->f_space = TRUE;
		else if (buff[i] >= '1' && buff[i] <= '9')
		{
			while((buff[i] >= '0' && buff[i] <= '9'))
			{

				options->w_dec = options->w_dec * 10 + buff[i] - 48;
				i++;
			}
			if (buff[i] == '.')
					continue;
		}
		else if (buff[i] == '0')
			options->w_zero_dec = TRUE;


		else if (buff[i] == '.' && buff[i + 1] == '*')
		{
			i++;
			options->a_dec = va_arg(args, int);
			options->a_star = TRUE;
		}
		else if(buff[i] == '*')
		{

			options->w_dec = va_arg(args, int);
			options->w_star = TRUE;
		}
		else if (buff[i] == '.' && !ft_isdigit(buff[i + 1]))
		{
			options->a_have_dot = TRUE;
            options->a_dec = 0;
		}


		else if (buff[i] == '.')
		{
			i++;
			options->a_have_dot = TRUE;
			while(buff[i] >= '0' && buff[i] <= '9')
				{
					options->a_dec = options->a_dec * 10 + buff[i] - 48;
					i++;
				}
		}


        else if (buff[i] == 'h')
            {
                if (buff[i+1] == 'h')
                {
                    options->m_hh = TRUE;
                    i += 2;
                }
                else
                {
                    options->m_h = TRUE;
                    i++;
                }
            }
        else if (buff[i] == 'l')
            {
                if (buff[i+1] == 'l')
                {
                    options->m_ll = TRUE;
                    i += 2;
                }
                else
                {
                    options->m_l = TRUE;
                    i++;
                }
            }
        else if (buff[i] == 'L')
            options->m_L = TRUE;



		// if(options->f_plus == TRUE && options->f_space == TRUE)
		// 	flag_error();
		// if(options->f_minus == TRUE && options->w_zero_dec == TRUE)
		// 	flag_error();
		i++;
	}
	return (options);
}



void	finish(void)
{
	ft_putstr("EOF");
	exit(0);
}

// void	flag_error(void)
// {
// 	ft_putstr("Flag conflict!");
// 	exit(0);
// }

// void	flag_ne_tot(void)
// {
// 	ft_putstr("Alyo, debila, sledi sho pishesh!");
// 	exit(0);
// }