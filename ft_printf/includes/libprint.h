/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprint.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:37:34 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/10 11:32:28 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_LIBPRINT_H_
# define _LIBPRINT_H_

#include "libft.h"
#include <stdarg.h>
# define BUFF_SIZE 32

typedef struct s_option
{
	int		f_plus;
	int		f_minus;
	int		f_hash;
	int		f_space;
	int		w_dec;
	int		w_star;
	int		w_zero_dec;
	int		a_have_dot;
	int		a_dec;
	int		a_star;
	int		m_h;
    int		m_hh;
	int		m_l;
    int		m_ll;
	int		m_L;
	int		count;

	struct s_option *next;
}               t_option;

char			*str_char_in(const int i, const char c);
void			play_with_decemal(va_list args, t_option *options);
void			play_with_int(va_list args);
void			play_with_conversation(va_list args, char *pointer, t_option *options);
void			play_with_oct(va_list args, t_option *options);
void			play_with_unsigned_int(va_list args, t_option *options);
void			play_with_hex(va_list args, t_option *options);
void			play_with_hex_big(va_list args, t_option *options);
void			play_with_string(va_list args, t_option *options);
void			play_with_promile(t_option *options);
void			play_with_char(va_list args, t_option *options);
void			play_with_pointer(va_list args, t_option *options);
char			*play_with_d_flags(va_list args, t_option *options, char **out);
char			*play_with_h_flags(va_list args, t_option *options, char **out);
char			*play_with_o_flags(va_list args, t_option *options, char **out);
int				have_flag(char *pointer);
int				w_dec_clac(char *buff, int i);
char			*lets_play(va_list args, char *pointer, t_option *options);

int				ft_check_double(long double n);
void			ft_round(char **string, long double n, int *i);
long double		check_options(va_list args, t_option *options);
void			ft_round(char **string, long double n, int *i);
void			ft_right_part(char **string, long double n, int *i, int precision);
void			ft_left_part(char **string, long double *n, int *i, long double decs);
long double		dec_count(long double n, int *i);
char			*play_with_floats(va_list args, t_option *options);
void			trans_float(char const *out, t_option *options);

void			finish(void);
void			flag_error(void);
void			flag_ne_tot(void);
void			ft_print_nan(void);
void			ft_print_inf(void);

char			*ft_string(int sign, unsigned int i);
unsigned int	ft_count(int value, int base);
unsigned int	ft_count_long(long long value, int base);
char			*itoa_base(int value, int base);
char			*itoa_base_long(long long value, int base);
char			*itoa_unsigned(unsigned long long value);
char			*itoa_short(short value);

t_option		*clear_option(t_option *options);
t_option		*change_options(t_option *options, char *buff, va_list args);
void			print_options(t_option *options);
t_option		*make_options();
int				ft_printf(char *string, ...);


# endif
