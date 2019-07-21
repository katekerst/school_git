/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprint.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbellege <gbellege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:37:34 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/20 18:44:30 by gbellege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINT_H
# define LIBPRINT_H

# include "libft.h"
# include <stdarg.h>
# define BUFF_SIZE 64
# define OUT_SIZE 5000

typedef struct		s_option
{
	char			out[OUT_SIZE];
	int				f_plus;
	int				f_minus;
	int				f_hash;
	int				f_space;
	int				w_dec;
	int				w_star;
	int				w_zero_dec;
	int				a_have_dot;
	int				a_dec;
	int				a_star;
	int				m_h;
	int				m_hh;
	int				m_l;
	int				m_ll;
	int				m_big_l;
	int				count;
	int				is_positive;
	struct s_option *next;
}					t_option;

char				*msos(int len, char sym);
void				ft_del_sim_in_str(char *our_str, int how_many_sym_del);
void				play_with_decemal(va_list args, t_option *opt);
void				play_with_int(va_list args);
void				play_with_conversation(va_list args,
						char *pointer, t_option *opt);
void				play_with_oct(va_list args, t_option *opt);
void				play_with_unsigned_int(va_list args, t_option *opt);
void				play_with_hex(va_list args, t_option *opt);
void				play_with_hex_big(va_list args, t_option *opt);
void				play_with_string(va_list args, t_option *opt);
void				play_with_promile(t_option *opt);
void				play_with_char(va_list args, t_option *opt);
void				play_with_pointer(va_list args, t_option *opt);
char				*play_with_d_flags(va_list args,
						t_option *opt, char *out);
char				*play_with_h_flags(va_list args,
						t_option *opt, char *out);
char				*play_with_o_flags(va_list args,
						t_option *opt, char *out);
char				*play_with_u_flags(va_list args, t_option *opt);
int					have_flag(char *pointer);
int					string_have_conversation(char *str);
int					have_conversion(char *pointer);
int					w_dec_clac(char *buff, int i);
char				*lets_play(va_list args, char *pointer, t_option *opt);
void				ft_move_point(char *pointer, va_list args, t_option *opt);

int					ft_check_double(long double n);
void				ft_round(char **string, long double n, int *i);
long double			check_opt(va_list args, t_option *opt);
void				ft_round(char **string, long double n, int *i);
void				ft_right_part(char **string, long double n,
						int *i, int precision);
void				ft_left_part(char **string, long double *n,
						int *i, long double decs);
long double			dec_count(long double n, int *i);
void				play_with_floats(va_list args, t_option *opt);
void				trans_float(char *out, t_option *opt);

void				finish(void);
void				flag_error(void);
void				flag_ne_tot(void);
void				ft_print_nan(void);
void				ft_print_inf(void);
void				tsr(char *our_str, char *source);
void				tsl(char *out_str, char *source);
void				tsraf(char *our_str, char *source);
void				tslaf(char *out_str, char *source);

char				*ft_string(int sign, unsigned int i);
unsigned int		ft_count(int value, int base);
unsigned int		ft_count_long(long long value, int base);
char				*itoa_base(int value, int basex);
char				*itoa_base_long(long long value, int base);
char				*itoa_unsigned(unsigned long long value);
char				*itoa_short(short value);

t_option			*clear_option(t_option *opt);
t_option			*change_opt(t_option *opt,
						char *buff, int i, int qt);
void				print_opt(t_option *opt);
t_option			*make_opt();
int					ft_printf(char *string, ...);
#endif
