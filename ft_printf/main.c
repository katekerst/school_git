/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:39:49 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/10 12:18:50 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libprint.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
// long tab = 2555555555565;
// int d = 123456;
// char *s = "hello World";
long double n = 1223434.2334234242341;
// int n2 = 1234556;
long double n3 = 21231235.653454565;
double n4 = 212344415.612345565;
double n5 = 23745675.6456745675;
// long double n6 = 2745675.634565;
// ft_strchr("Hello World", 'W');
// ft_printf("\n%+-20.f", n2);
int result1 = ft_printf("my - %.27Lf\n", n);
int result2 = printf("re - %.27Lf\n", n);
printf("my is %d, norm is - %d\n", result1, result2);
result1 = ft_printf("my - %Lf\n", n3);
result2 = printf("re - %Lf\n", n3);
printf("my is %d, norm is - %d\n", result1, result2);
result1 = ft_printf("my - %f\n", n4);
result2 = printf("re - %f\n", n4);
printf("my is %d, norm is - %d\n", result1, result2);
result1 = ft_printf("my - %.8f\n", n5);
result2 = printf("re - %.8f\n", n5);
printf("my is %d, norm is - %d\n", result1, result2);
return 0;
}