/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:09:00 by siolive           #+#    #+#             */
/*   Updated: 2019/08/05 16:12:02 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "get_next_line.h"

typedef struct  s_node
{
    int n;
    struct s_node *next;
    struct s_node *prev;
}               t_node;

typedef struct  s_stack
{
    size_t size;
    t_node *head;
    t_node *tail;
}               t_stack;

int         check_input(int argc, char **argv);
int         ft_check_doubles(t_stack *a, int argc);
void        ft_push_back(t_stack *a, int argc, char **argv, int i);
t_stack     create_stack(t_stack *a, int argc, char **argv);
void        ft_error(void);
void        ft_ok(void);
void        ft_notok(void);
void        ft_dellst(t_stack *n);
int         ft_check_sort(t_stack *a);
void        ft_finish(t_stack *a, t_stack *b);
void        ft_dellst(t_stack *a);
void        ft_swap_el(t_stack *a, t_stack *b, char *line);
void        ft_push_el(t_stack *a, t_stack *b, char *line);
void        ft_rotate_el(t_stack *a, t_stack *b, char *line);
void        ft_revrotate_el(t_stack *a, t_stack *b, char *line);
void        ft_swap(t_stack *n);
void        ft_push(t_stack *a, t_stack *b, t_node *tail);
void        ft_rotate(t_stack *n);

#endif