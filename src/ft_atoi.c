/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:15:33 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/09 02:59:37 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_skiping(const char *str, int *i)
{
	int	cm;

	cm = 0;
	while (str[*i] && (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
	while (str[*i] && (str[*i] == '+' || str[*i] == '-'))
	{
		if (str[*i + 1] == '+' || str[*i + 1] == '-')
		{
			write(1, "error\n", 6);
			exit(0);
		}
		if (str[*i] == '-')
			cm++;
		(*i)++;
	}
	return (cm);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		cm;
	long	r;

	i = 0;
	r = 0;
	cm = ft_skiping(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r * 10 + (str[i] - 48) < r)
		{
			if (cm == 1)
				return (0);
			else
				return (-1);
		}
		r = r * 10 + (str[i] - 48);
		i++;
	}
	if (cm == 1)
		r = -r;
	return (r);
}
