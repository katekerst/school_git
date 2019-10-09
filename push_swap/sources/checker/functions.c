/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:45:10 by siolive           #+#    #+#             */
/*   Updated: 2019/08/05 16:06:46 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    ft_revrotate(t_stack *n)
{
    if (!n->head || !n->tail)
        return ;
    n->head->prev = n->tail;
    n->tail->next = n->head;
    n->head = n->tail;
    n->tail = n->tail->prev;
    n->head->prev = NULL;
    n->tail->next = NULL;
}

void    ft_rotate(t_stack *n)
{
    if (!n->head || !n->tail)
        return ;
    n->tail->next = n->head;
    n->head->prev = n->tail;
    n->head = n->head->next;
    n->head->prev = NULL;
    n->tail = n->tail->next;
    n->tail->next = NULL;
}

void    ft_push(t_stack *source, t_stack *dest, t_node *tail)
{
    t_node *temp;

    if (!source->head)
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

    if (n->head == NULL || n->head->next == NULL)
		return ;
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
    {    
        ft_swap(a);
        return ;
    }
    if (!ft_strcmp("sb", line))
    {
        ft_swap(b);
        return ;
    }
    ft_swap(a);
    ft_swap(b);
}

void    ft_push_el(t_stack *a, t_stack *b, char *line)
{
    if (!ft_strcmp("pa", line))
    {
        ft_push(b, a, a->tail);
        return ;
    }
    if (!ft_strcmp("pb", line))
    {
        ft_push(a, b, b->tail);
        return ;
    }
}

void    ft_rotate_el(t_stack *a, t_stack *b, char *line)
{
    if (!ft_strcmp("ra", line))
    { 
        ft_rotate(a);
        return ;
    }
    if (!ft_strcmp("rb", line))
    {
        ft_rotate(b);
        return ;
    }
    ft_rotate(a);
    ft_rotate(b);
}

void    ft_revrotate_el(t_stack *a, t_stack *b, char *line)
{
    if (!ft_strcmp("rra", line))
        ft_revrotate(a);
    else if (!ft_strcmp("rrb", line))
        ft_revrotate(b);
    else
    {
        ft_revrotate(a);
        ft_revrotate(b);
    }
}