/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 01:06:46 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/09 21:55:10 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minitalk.h"

static int	fromat(va_list p, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(p, int));
	else if (c == 's')
		len += ft_putstr(va_arg(p, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(p, int));
	else if (c == 'p')
	{
		len += ft_putstr("0x");
		len += hex_pointer(va_arg(p, size_t));
	}
	else if (c == 'u')
		len += ft_putnbr_u(va_arg(p, unsigned int));
	else if (c == 'x')
		len += dec_to_hex(va_arg(p, unsigned int), 'x');
	else if (c == 'X')
		len += dec_to_hex(va_arg(p, unsigned int), 'X');
	else if (c == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	p;

	va_start(p, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			len += fromat(p, str[i]);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(p);
	return (len);
}
