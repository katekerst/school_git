/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:06:00 by siolive           #+#    #+#             */
/*   Updated: 2019/07/25 15:05:41 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int     check_input(int argc, char **argv)
{
    int     i;
    int     j;
    int     num;

    i = 1;
    while (i < argc)
    {
        j = 0;
        if (argv[i][j] == '-')
            j++;
        while ((num = (ft_isdigit(argv[i][j])) == 1))
            j++;
        if (argv[i][j])
            return (1);
        i++;
    }
    return (0);
}

void    error(void)
{
    ft_putstr("Error\n");
    exit(1);
}

t_stack    *create_stack(t_stack **a, int argc, char **argv)
{
    int     i;
    t_stack     *temp;

    i = 1;
    if (check_input(argc, argv))
        error();
    if(!(*a = ft_memalloc(sizeof(t_stack))))
            error();
    temp = *a;
    while (i < argc)
    {
        temp->n = ft_atoi(argv[i]);
        if(i != argc - 1)
            temp->next = ft_memalloc(sizeof(t_stack));
        temp = temp->next;
        i++;
    }
    temp = NULL;
    return (*a);
}

int main(int argc, char **argv)
{
    t_stack *a;

    a = NULL;
    a = create_stack(&a, argc, argv);
    while (a)
    {
        printf("int here is %d\n", a->n);
        a = a->next;
    }
    return (0);
}