/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:06:00 by siolive           #+#    #+#             */
/*   Updated: 2019/07/28 15:29:01 by siolive          ###   ########.fr       */
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

int     ft_check_doubles(t_stack *a)
{
    t_node *temp;
    int     i;
    int     *t;
    int     j;

    temp = a->head;
    i = 0;
    t = ft_memalloc(sizeof(int) * (a->size + 1));
    while (temp)
    {
        t[i++] = temp->n;
        temp = temp->next;
    }
    i = 0;
    while (i < (int)a->size)
    {
        j = i;
        while (j++ < (int)a->size)
        {
            if (t[i] == t[j])
                return (1);
        }
        i++;
    }
    ft_memdel((void**)&t);
    return (0);
}

void        ft_push_back(t_stack *a, int argc, char **argv, int i)
{
    t_node      *new;
    int     number;

    while (++i < argc)
    {
        number = ft_atoi(argv[i]);
        new = ft_memalloc(sizeof(t_node));
        new->n = number;
        new->next = NULL;
        new->prev = a->tail;
        a->tail->next = new;
        a->tail = new;
        a->size++;
    }
}

t_stack    create_stack(t_stack *a, int argc, char **argv)
{
    int     i;

    i = 1;
    if (check_input(argc, argv) || !(a->head = ft_memalloc(sizeof(t_node))))
        error();
    a->head->n = ft_atoi(argv[i]);
    a->size++;
    a->head->prev = NULL;
    a->tail = a->head;
    ft_push_back(a, argc, argv, i);
    if (ft_check_doubles(a))
    {
        ft_dellst(a);
        error();
    }
    return (*a);
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    char    *line;
    t_node *temp_a;
    t_node *temp_b;

    a = create_stack(&a, argc, argv);
    b.head = NULL;
    b.tail = NULL;
    temp_a = a.head;
    line = NULL;
    while (temp_a != NULL)
    {
        printf("int here is %d\n", temp_a->n);
        temp_a = temp_a->next;
    }
    printf("\n\n");
    ft_push_el(&a, &b, line);
    // while (get_next_line(0, &line) > 0)
    // {
    //     if (!ft_strcmp("sa", line) || !ft_strcmp("sb", line) || !ft_strcmp("ss", line))
    //         ft_swap_el(&a, &b, line);
    //     else if (!ft_strcmp("pa", line) || !ft_strcmp("pb", line))
    //         ft_push_el(&a, &b, line);
    //     else if (!ft_strcmp("ra", line) || !ft_strcmp("rb", line) || !ft_strcmp("rr", line))
    //         ft_rotate_el(&a, &b, line);
    //     else if (!ft_strcmp("rra", line) || !ft_strcmp("rrb", line) || !ft_strcmp("rrr", line))
    //         ft_rev_rotate_el(&a, &b, line);
    //     else
    //         // ft_finish();
    //     //     error();
    //     ft_strdel(&line);
    // }
    // ft_ok();
    temp_a = a.head;
    temp_b = b.head;
    while (temp_a != NULL)
    {
        printf("int here is %d\n", temp_a->n);
        temp_a = temp_a->next;
    }
    printf("\n\n");
    while (temp_b != NULL)
    {
        printf("int here is %d\n", temp_b->n);
        temp_b = temp_b->next;
    }
    ft_dellst(&a);
    return (0);
}