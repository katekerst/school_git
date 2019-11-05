int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    t_list *instruct;

    a = create_stack(&a, argc, argv);
    b = create_stack(&b, argc, argv);
//??????????????????????????????????????
//в структуре стэка есть + t_node **p, int top и ac
    if (!(a.p = malloc(sizeof(t_node*) * ac)) ||
	!(b.p = malloc(sizeof(t_node*) * ac)))
		exit(1);
//??????????????????????????????????????
    a.ac = argc;
    b.ac = argc;
    a.top = 0;
    b.top = 0;
    a.p[a.top] = NULL;
    b.p[a.top] = NULL;
    instruct = ft_solve_it(&a, &b);
    while (instruct)
    {
        ft_putstr((char *instruct->content))
        instruct = instruct->next;
    }
    free(b.p);
    ft_dellst(a);
    ft_delinstr(instruct);
}

void    ft_delinstr(t_list *instruct)
{
    t_list  *temp;
    while (instruct)
    {
        temp = instruct;
        free(instruct->content);
        instruct = instruct->next;
        free(temp);
    }
}

t_list  *ft_solve_it(t_stack *a, t_stack *b)
{
    t_list *instruct;
    int     sorted;

    instruct = ft_lstnew("\0", 1);
    while((sorted = ft_is_sorted(a)) == 0 || b->head)
    {
        if (sorted == 0)
        {
            ret = med_a(a, b, &instruct)
            if (ret == -1)
                exit(1);
        }
        else
            a->p[++(a->top)] = a->head;
        ft_b_to_a(a, b, &instruct);
    }
    return (instruct);
}

int ft_is_sorted(t_stack *a)
{
    t_node  *temp;

    temp = a->head;
    while(temp)
    {
        if(temp->next && temp->n > temp->next->n)
            return(0);
        temp = temp->next;
        if (temp == a->p[a->top])
            break ;
    }
    return (1);
}

int med_a(t_stack *a, t_stack *b, t_list *instruct)
{
    int     count;
    int     median;
    char    temp[a->ac * 4];

    temp[0] = '\0'.
    count = ft_count(a);
    median = 2147483648;
    median = ft_get_median(a);
    if (median != 2147483648 && count > 3)
        ft_split_stack_a(a, b, median, temp);
    else
        ft_sort_a(a, count, temp);
    if (temp[0] != '\0')
        ft_lstaddend(instruct, ft_lststr(temp));
    if (median == 2147483648)
    {    
        a->p[++(a->top)] = a->head;
        return (1);
    }
    else
        return (0);
}

int ft_count(t_stack *n) //differ...
{
    t_stack *temp;
    int     i;

    temp = n;
    i = 0;
    while (temp)
    {
       count++;
       temp = temp->next; 
    }
    return (count);
}

int ft_get_median(t_stack *a)
{
    t_node  *temp;
    int     array[a->ac + 1];
    int     i;
    int     j;
    int     k;

    i = 0;
    temp = a->head;
    while (temp != a->p[a->top])
    {
        array[i++] = temp->n;
        temp = temp->next;
    }
    j = 0; // или -1
    while (++j < i)
    {
        k = j;
        while (++k < i)
        {
            if (attay[j] < array[k])
            {
                array[a->ac] = array[k];
                array[k] = attay[j];
                array[j] = array[a->ac];
            }
        }
    }
    i = i / 2;
    return (array[i]);
}

void    ft_split_stack_a(t_stack *a, t_stack *b, int median, char *instr)
{
    int     rew;

    rew = 0;
    if (b->head != NULL)
        b->p[++(b->top)] = b->head;
    while (a->head != a->p[a->top])
    {
        if (a->head->n <= median)
        {
            ft_push (&a->head, %b->head, &b->end);
            ft_strcat(instr, "pb\n");
        }
        else if (!(ft_choose_high(a, instr, median, &rew)))
            break ;
    }
    while (a->p[a->top] && --rew >= 0)
    {
        ft_revrotate(&a->head, &a->end);
        ft_strcat(instr, "rra\n");
    }
}

int     ft_sort_a(t_stack *a, int count, char *temp)
{
    if (count == 1)
        return ;
    else if (count == 2)
    {
        if (a->head->n > a->head->next->n)
        {
            ft_swap(&a->head)
            ft_strcat(temp, "sa\n");
        }
        return ;
    }
    else 
        ft_sort_three_a(a, temp);
}

void    ft_sort_three_a(t_stack *a, char *temp)
{
    t_stack *p;
    
    p = a->head;
    while (!(p->n < p->next->next->n 
    && p->next->n < p->next->next->n))
    {
        if (p->next->n > p->next->next->n
        && p->next->n > p->n)
        {
            ft_revrotate(&a->head, &a->end);
            ft_strcat(temp, "rra\n");
        }
        else
        {
            ft_rotate(&a->head, &a->end);
            ft_strcat(tmp, "ra\n");
        }
    }
    if (p->next->n < p->n)
        return ;
    ft_swap(&a->head);
    ft_strcat(temp, "sa\n");
}

void    ft_lstaddend(t_list **old, t_list *new)
{
    t_list *temp;

    temp = *old;
    if (temp == NULL)
    {
        *old = new;
        new->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
        new->next = NULL;
    }
}

t_list    *ft_lststr(char *str)
{
    t_list *temp;
    int     i;
    char    *array;

    if (!(temp = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    if (str == NULL)
    {
        temp->content = NULL;
        temp->content_size = 0;
        temp->next = NULL;
        return (temp);
    }
    array = malloc(sizeof(char) * ft_strlen(str) + 1);
    i = 0;
    while(str[i++] != '\0')
        array[i] = str[i];
    array[i] = '\0';
    temp->content = (void *)array;
    temp->next = NULL;
    return (temp);
}

void    ft_b_to_a(t_stack *a, t_stack *b, t_list **instruct)
{
    int count;
    int median;
    char temp[a->ac * 4];

   `temp[0] = '\0'.
    count = ft_count(a);
    median = 2147483648;
    median = ft_get_median(b);
    if (median != 2147483648 && count > 3)
        ft_split_stack_b(a, b, median, temp);
    else
        ft_sort_b(a, count, temp);
    if (median == 2147483648)
        ft_push_b(b, count, temp);
    if (temp[0] != '\0')
        ft_lstaddend(instruct, ft_lststr(temp));
}

void    ft_split_stack_b(t_stack *a, t_stack *b, int median, char *instr)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (b->head != b->p[b->top])
    {
        if (b->head->n <= median)
        {
            ft_push(&b->head, %a->head, &a->end);
            ft_strcat(instr, "pa\n");
        }
        else if (!(ft_choose_low(b, instr, median, i)))
            break ;
    }
    while (b->p[b->top] && --i >= 0)
    {
        ft_revrotate(&b->head, &b->end);
        ft_strcat(instr, "rrb\n");
    }
}

int     ft_choose_low(t_stack *b, char *instr, int median, int i)
{
    int     skipped;
    t_node  *temp;

    skipped = 0;
    temp = b->head;
    while (temp != b->p[b->top] && temp->n <= median)
    {
        skipped++;
        temp = temp->next;
    }
    if (temp == b->p[b->top])
        return (0);
    i += skipped;
    while (skipped--)
    {
        ft_rotate(&b->head, &b->end);
        ft_strcat(instr, "rb\n");
    }
    return (1);
}

void       ft_sort_b(t_stack *b, int count, char *temp)
{
    if (b->top != NULL)
        b->top--;
    if (count == 1 || count == 0)
        return ;
    else if (count == 2)
    {
        if (b->head->next && b->head->next->n > b->head->n)
        {
            ft_swap(&b->head);
            ft_strcat(temp, "sb\n");
        }
        return ;
    }
    else 
        ft_sort_three_b(b, temp);
}

void    ft_sort_three_b(t_stack *a, char *temp)
{
    t_stack *p;
    
    p = a->head;
    while (!(p->n < p->next->next->n 
    && p->next->n < p->next->next->n))
    {
        if (p->next->n > p->next->next->n
        && p->next->n > p->n)
        {
            ft_revrotate(&a->head, &a->end);
            ft_strcat(temp, "rrb\n");
        }
        else
        {
            ft_rotate(&a->head, &a->end);
            ft_strcat(tmp, "rb\n");
        }
    }
    if (p->next->n > p->n)
        return ;
    ft_swap(&a->head);
    ft_strcat(temp, "sb\n");
}

void        ft_push_b(t_stack *b, t_stack *a, int count, char *temp)
{
    int i;

    i = 0;
    if (count == -1)
        count = 3;
    while (i++ < count)
    {
        ft_push (&b->head, &a->head, &a->end);
        ft_strcat(temp, "pa\n");
    }
}