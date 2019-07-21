/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:39:49 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/21 13:36:09 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprint.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
// long tab = 2555555555565;
// int d = 123456;
void *a;
char *s = "hello World";
// long double n = 1223434.2334234242341;
// int n2 = 1234556;
char c = 'b';
int n3 = 21231235;
unsigned int n5 = 23432;
unsigned long n7 = 23433453452;
long n9 = 34524345234;
unsigned long long n8 = 23432342343453452;
double n4 = 212344415.612345565;
long long n10 = 3456357464353653;
// double n5 = 23745675.6456745675;
long double n6 = 2745675.634565;
ft_printf("my - %d\n", n3);
printf("re - %d\n", n3);
ft_printf("my - %f\n", n4);
printf("re - %f\n", n4);
ft_printf("my - %u\n", n5);
printf("re - %u\n", n5);
ft_printf("my - %x\n", n3);
printf("re - %x\n", n3);
ft_printf("my - %X\n", n3);
printf("re - %X\n", n3);
ft_printf("my - %o\n", n3);
printf("re - %o\n", n3);

ft_printf("my - %Lf\n", n6);
printf("re - %Lf\n", n6);
ft_printf("my - %lu\n", n9);
printf("re - %lu\n", n9);
ft_printf("my - %lx\n", n9);
printf("re - %lx\n", n9);
ft_printf("my - %lX\n", n9);
printf("re - %lX\n", n9);
ft_printf("my - %lo\n", n9);
printf("re - %lo\n", n9);
ft_printf("my - %lu\n", n7);
printf("re - %lu\n", n7);
ft_printf("my - %lx\n", n9);
printf("re - %lx\n", n9);

ft_printf("my - %llX\n", n10);
printf("re - %llX\n", n10);
ft_printf("my - %llo\n", n10);
printf("re - %llo\n", n10);
ft_printf("my - %llu\n", n8);
printf("re - %llu\n", n8);
ft_printf("my - %llx\n", n10);
printf("re - %llx\n", n10);

ft_printf("my - %s\n", s);
printf("re - %s\n", s);
ft_printf("my - %c\n", c);
printf("re - %c\n", c);
ft_printf("my - %p\n", a);
printf("re - %p\n", a);
return 0;
}