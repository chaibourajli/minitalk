/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:20:12 by cbourajl          #+#    #+#             */
/*   Updated: 2022/04/28 01:40:30 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bits(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(500);
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("signal has been sent successfully\n");
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = -1;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid > 0)
		{
			signal(SIGUSR1, handler);
			while (argv[2][++i])
				send_bits(pid, argv[2][i]);
			send_bits(pid, 0);
		}
		else
			ft_putstr("The server pid is Invalid.\n");
	}
	else
		ft_putstr("Invalid number of arguments. Please try again.\n");
	return (0);
}
