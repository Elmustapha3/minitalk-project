/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 02:16:16 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/12 00:04:00 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	communication_fun(int c, int pid)
{
	int	bit;
	int	a;
	int	r;

	bit = 7;
	while (bit >= 0)
	{
		a = 1 << bit;
		if ((c & a) == 0)
			r = kill(pid, SIGUSR2);
		else
			r = kill(pid, SIGUSR1);
		if (r == -1)
		{
			ft_printf("error sending signal");
			exit(0);
		}
		usleep(200);
		bit--;
	}
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
		ft_printf("Arguments not eqaul two\n");
	return (0);
}
