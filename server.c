/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:07:54 by cbourajl          #+#    #+#             */
/*   Updated: 2022/04/28 01:38:48 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	ascii;
	static int	i;

	(void) context;
	signum -= SIGUSR1;
	if (g_pid != info->si_pid)
	{
		ascii = 0;
		i = 0;
		g_pid = info->si_pid;
	}
	if (signum)
		ascii = ascii << 1 | 1;
	if (!signum)
		ascii = ascii << 1 | 0;
	i++;
	if (i == 8)
	{
		ft_putchar(ascii);
		i = 0;
		ascii = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = &handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_putstr("The server pid is = ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1337)
		pause();
}
