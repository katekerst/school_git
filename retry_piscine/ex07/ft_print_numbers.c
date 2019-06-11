/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siolive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:53:16 by siolive           #+#    #+#             */
/*   Updated: 2019/04/02 13:59:31 by siolive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char zero;

	zero = '0';
	while (zero != '9')
	{
		ft_putchar(zero);
		zero++;
	}
	ft_putchar(zero);
}
