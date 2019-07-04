/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:39:49 by gbellege          #+#    #+#             */
/*   Updated: 2019/07/04 12:49:40 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprint.h"
#include <stdio.h>
#include <limits.h>

char *print_memory(void *addr, size_t size) // Нужно вкурить функцию
{
	size_t			i;
	unsigned char	*pc;
	char			*out;
	int				g;

	i = 0;
	pc = (unsigned char *)addr;
	out = ft_strnew(size);
	while (i++ < size)
	{
		g = (*(pc+i) >> 4) & 0xf;
		g += g >= 10 ? 'a'-10 : '0';
		*out = g;
		out++;

		g = *(pc+i) & 0xf;
		g += g >= 10 ? 'a'-10 : '0';
		*out = g;
		out++;
	}

	// for (i=0; i<(size); ++i)
	// {
	// 	g = (*(pc+i) >> 4) & 0xf;
	// 	g += g >= 10 ? 'a'-10 : '0';
	// 	*out = g;
	// 	out++;

	// 	g = *(pc+i) & 0xf;
	// 	g += g >= 10 ? 'a'-10 : '0';
	// 	*out = g;
	// 	out++;
	// }
	out = out - (size*2);
	// ft_putstr(out);
	return (out);
}

int main(void)
{
// long tab = 2555555555565;
// int d = 123456;
// char *s = "hello World";
// long double n = -12345678901234567901234567890.1;
// int n2 = 1234556;
// long double n3 = 21231235.653454565;
// long double n4 = 212344415.612345565;
// long double n5 = 23745675.6456745675;
// long double n6 = 2745675.634565;
// ft_strchr("Hello World", 'W');
// ft_printf("\n%+-20.f", n2);
int result1 = ft_printf("%hho, %hho\n", 0, 297);
int result2 = printf("%hho, %hho\n", 0, 297);
printf("my is %d, norm is - %d\n", result1, result2);
return 0;
}