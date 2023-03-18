/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 02:00:38 by eej-jama          #+#    #+#             */
/*   Updated: 2023/02/12 00:04:18 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putcharr(char c)
{
	write(1, &c, 1);
}

void	signal_handling(int sig)
{
	static int	i;
	static int	j;

	i++;
	if (sig == SIGUSR1)
		j = (j | 1);
	if (i == 8)
	{
		ft_putcharr(j);
		i = 0;
		j = 0;
	}
	else
		j = j << 1;
}

int	main(void)
{
	pid_t	id;

	id = getpid();
	ft_printf("use this PID to connect to this process : %d \n", id);
	while (1)
	{
		signal(SIGUSR1, signal_handling);
		signal(SIGUSR2, signal_handling);
		pause();
	}
}
