/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:47:58 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/09 21:55:18 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minitalk.h"

int	ft_putnbr(int n)
{
	long	a;
	int		len;

	len = 0;
	a = (long)n;
	if (a < 0)
	{
		len++;
		ft_putchar('-');
		a = -a;
	}
	if (a > 9)
	{
		len += ft_putnbr(a / 10);
		a %= 10;
	}
	if (a < 10)
	{
		ft_putchar(a + 48);
		len++;
	}
	return (len);
}
