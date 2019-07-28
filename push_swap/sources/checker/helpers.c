/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:40:10 by siolive           #+#    #+#             */
/*   Updated: 2019/07/28 14:40:33 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error(void)
{
    ft_putstr("Error\n");
    exit(1);
}

void    ft_dellst(t_stack *a)
{
    t_node *temp;

    while (a->head)
    {
        temp = a->head;
        a->head = a->head->next;
        free(temp);
    }
}