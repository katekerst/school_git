/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats_bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <siolive@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 11:31:54 by siolive           #+#    #+#             */
/*   Updated: 2019/06/27 13:54:18 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	double n = 2346.3456365;
	double result;

	int sign = *(uint64_t *)&n >> 63;
	int exponent = (*(uint64_t *)&n << 1 >> 53) - 1023;
	long mantissa = *(uint64_t *)&n << 12 >> 12;
	result = pow(-1, sign) * (1 + mantissa/pow(2, 52)) * pow(2, exponent);
	printf ("exponent int is %d\n", exponent);
	printf ("sign int is %d\n", sign);
	printf ("matissa int is %ld\n", mantissa);
	printf ("double is %.20f\n", n);
	printf ("result is %.20f\n", result);
	return (0);
}