/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:45:10 by siolive           #+#    #+#             */
/*   Updated: 2019/07/28 15:31:46 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    ft_push(t_stack *source, t_stack *dest, t_node *tail)
{
    t_node *temp;

    if (!source)
        return ;
    temp = source->head;
    source->head =  source->head->next;
    if (source->head != NULL)
        source->head->prev = NULL;
    if (dest->head != NULL)
        dest->head->prev = temp;
    else
        tail = temp;
    temp->next = dest->head;
    dest->head = temp;
    dest->head->prev = NULL;
}

void    ft_swap(t_stack *n)
{
    t_node *temp;

    temp = n->head;
    n->head = n->head->next;
    temp->prev = n->head;
    temp->next = n->head->next;
    n->head->prev = NULL;
    n->head->next = temp;
}

void    ft_swap_el(t_stack *a, t_stack *b, char *line)
{
    if (!ft_strcmp("sa", line))
        ft_swap(a);
    else if (!ft_strcmp("sb", line))
        ft_swap(b);
    else
    {   
        ft_swap(a);
        ft_swap(b);
    }
}

void    ft_push_el(t_stack *a, t_stack *b, char *line)
{
    line = NULL;
    // if (!ft_strcmp("pa", line))
    //     ft_push(b, a, a->tail);
    // else if (!ft_strcmp("pb", line))
    //     ft_push(a, b, b->tail);
    ft_push(a, b, b->tail);
}

// void    ft_rotate_el(t_stack *a, t_stack *b, char *line)
// {

// }

// void    ft_rev_rotate_el(t_stack *a, t_stack *b, char *line)
// {

// }