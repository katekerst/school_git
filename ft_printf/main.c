/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:39:49 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/24 11:26:29 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprint.h"
#include <stdio.h>
#include <limits.h>
#include <math.h>
int main(void)
{
int i = 9, j = 9;
void *a;
char *s = "hello World";
char *s1 = NULL;
char *s2 = "what the fuck?";
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

ft_printf("\n\nmy - %s\n", s);
   printf("re - %s\n", s);
ft_printf("my - %s\n", s1);
   printf("re - %s\n", s1);
ft_printf("my - %s\n", s2);
   printf("re - %s\n", s2);
ft_printf("my - %c\n", c);
   printf("re - %c\n", c);
ft_printf("my - %p\n", a);
   printf("re - %p\n", a);

// ft_printf("%-#23.hhX|%-023.hhX|%#023.hhX|%-#023.hhX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
//    printf("%-#23.hhX|%-023.hhX|%#023.hhX|%-#023.hhX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
// ft_printf("%5hX ----- %hX", 123, 123);
//    printf("hX|hX|hX|%hX\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
// ft_printf("%.5o|%-.5o|%#.5o|%0.5o\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
//    printf("%.5o|%-.5o|%#.5o|%0.5o\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
// ft_printf("|%c|%-c|%12c|%-12c|\n", 0, 0, 0, 0);
//    printf("|%c|%-c|%12c|%-12c|\n", 0, 0, 0, 0);
int result1;
int result2;
result1 = ft_printf("%2.f|%2.1f|%2.2f|%2.5f|%2.12f\n", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999);
result2 = printf("%2.f|%2.1f|%2.2f|%2.5f|%2.12f\n", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999);
printf("my is %d, real is %d\n", result1, result2);
// result1 = ft_printf("%.f|%.f|%.f|%.f|%.f\n", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52);
// result2 = printf("%.f|%.f|%.f|%.f|%.f\n", 45.5, 45.4, 45.6, 45.50001, 45.5 + 1e-52);
// printf("my is %d, real is %d\n", result1, result2);
// result1 = ft_printf("%.f|%.1f|%.2f|%.5f|%.12f\n", 989.9999999, 989.9999999, 989.9999999, 989.9999999, 989.9999999);
// result2 = printf("%.f|%.1f|%.2f|%.5f|%.12f\n", 989.9999999, 989.9999999, 989.9999999, 989.9999999, 989.9999999);
// printf("my is %d, real is %d\n", result1, result2);
return 0;
}