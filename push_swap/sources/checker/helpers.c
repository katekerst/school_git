/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:40:10 by siolive           #+#    #+#             */
/*   Updated: 2019/10/09 19:46:39 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_error(void)
{
    ft_putstr("Error\n");
    exit(1);
}

void    ft_ok(void)
{
   ft_putstr("OK\n");
}

void    ft_notok(void)
{
    ft_putstr("KO\n");
    exit(1);
}

void    ft_dellst(t_stack *n)
{
   t_node *temp;
   
   temp = n->head;
   while (n->head)
    {
        temp = n->head;
        n->head = n->head->next;
        free(temp);
    } 
}

int     ft_check_sort(t_stack *a)
{
    t_node *temp;

    temp = a->head;
    while(temp->next)
    {
        if (temp->n > temp->next->n)
            return (1);
        temp = temp->next;
    }
    return (0);
}

void    ft_finish(t_stack *a, t_stack *b)
{
    ft_dellst(a);
    ft_dellst(b);
}