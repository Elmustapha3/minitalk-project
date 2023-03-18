/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 02:16:16 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/11 23:59:41 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*to_binary(int c)
{
	char	d;
	char	*str;
	int		i;

	str = malloc(9);
	str[8] = '\0';
	i = 0;
	while (c != 0)
	{
		d = c % 2 + 48;
		str[i] = d;
		c = c / 2;
		i++;
	}
	while (i < 8)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

void	communication_fun(int c, int pid)
{
	int		j;
	char	*str;
	int		r;

	str = to_binary(c);
	j = 0;
	while (str[j])
	{
		if (str[j] == '1')
			r = kill(pid, SIGUSR1);
		else
			r = kill(pid, SIGUSR2);
		if (r == -1)
		{
			ft_printf("error sending signal");
			free(str);
			exit(0);
		}
		usleep(200);
		j++;
	}
	free(str);
}

int	main(int argc, char const *argv[])
{
	int	id;
	int	i;

	if (argc == 3)
	{
		id = ft_atoi(argv[1]);
		if (id <= 0)
		{
			ft_printf("process code wrong\n");
			exit(0);
		}
		i = 0;
		while (argv[2][i])
		{
			communication_fun(argv[2][i], id);
			i++;
		}
		communication_fun(10, id);
	}
	else
		ft_printf("Arguments not equal two\n");
	return (0);
}
