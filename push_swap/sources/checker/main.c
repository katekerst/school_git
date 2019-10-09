/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:06:00 by siolive           #+#    #+#             */
/*   Updated: 2019/10/09 20:02:00 by siolive          ###   ########.fr       */
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

int     ft_check_doubles(t_stack *a, int argc)
{
    t_node *tmp;
	int		i;
	int		j;
	int		k;
	int		arr[argc + 1];

	tmp = a->head;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->n;
		tmp = tmp->next;
	}
	j = -1;
	while (j++ < i)
	{
		k = j;
		while (++k < i)
			if (arr[j] == arr[k])
				return (1);
	}
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
        ft_error();
    a->head->n = ft_atoi(argv[i]);
    a->size++;
    a->head->prev = NULL;
    a->tail = a->head;
    ft_push_back(a, argc, argv, i);
    if (ft_check_doubles(a, argc))
    {
        ft_dellst(a);
        ft_error();
    }
    return (*a);
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    char    *line;

    a = create_stack(&a, argc, argv);
    b.head = NULL;
	b.tail = NULL;
    while (get_next_line(0, &line) > 0)
    {
        if (!ft_strcmp("sa", line) || !ft_strcmp("sb", line) || !ft_strcmp("ss", line))
            ft_swap_el(&a, &b, line);
        else if (!ft_strcmp("pa", line) || !ft_strcmp("pb", line))
            ft_push_el(&a, &b, line);
        else if (!ft_strcmp("ra", line) || !ft_strcmp("rb", line) || !ft_strcmp("rr", line))
            ft_rotate_el(&a, &b, line);
        else if (!ft_strcmp("rra", line) || !ft_strcmp("rrb", line) || !ft_strcmp("rrr", line))
            ft_revrotate_el(&a, &b, line);
        else
        {
            ft_finish(&a, &b);
            ft_notok();
        }
        ft_strdel(&line);
    }
    if (b.head != NULL || ft_check_sort(&a))
    {
        ft_finish(&a, &b);
        ft_notok();
    }
    else
    {
        ft_finish(&a, &b);
        ft_ok();
    }
    return (0);
}