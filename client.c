/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:07:43 by cbourajl          #+#    #+#             */
/*   Updated: 2022/04/23 02:07:48 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

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
		usleep(800);
	}
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
