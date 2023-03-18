/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:20:42 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/09 21:55:07 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minitalk.h"

int	dec_to_hex(unsigned int a, char x)
{
	int	len;
	int	t;

	len = 0;
	if (x == 'x')
		t = 87;
	if (x == 'X')
		t = 55;
	if (a > 15)
	{
		len += dec_to_hex(a / 16, x);
		a %= 16;
	}
	if (a < 16)
	{
		if (a >= 10)
			ft_putchar(a + t);
		else
			ft_putchar(a + 48);
		len++;
	}
	return (len);
}
