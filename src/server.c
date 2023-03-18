/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 02:00:38 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/12 00:02:04 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putcharr(char c)
{
	write(1, &c, 1);
}

void	signal_handling(int sig)
{
	static int		i;
	unsigned char	c;
	int				tmp;
	static int		nbr;

	c = '0';
	if (sig == SIGUSR1)
		c = '1';
	else if (sig == SIGUSR2)
		c = '0';
	tmp = ft_atoi_bin(c);
	tmp = tmp << i;
	nbr = nbr | tmp;
	if (i == 7)
	{
		ft_putcharr(nbr);
		i = 0;
		nbr = 0;
	}
	else
		i++;
}

int	main(void)
{
	pid_t	id;

	id = getpid();
	ft_printf("use this PID to connect to this process : %d\n", id);
	while (1)
	{
		signal(SIGUSR1, &signal_handling);
		signal(SIGUSR2, &signal_handling);
		pause();
	}
}
