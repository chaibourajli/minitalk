/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:20:19 by cbourajl          #+#    #+#             */
/*   Updated: 2022/04/28 01:39:43 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	ascii;
	static int	i;
	int			pid;

	(void) context;
	signum -= SIGUSR1;
	pid = info->si_pid;
	if (signum)
		ascii = ascii << 1 | 1;
	if (!signum)
		ascii = ascii << 1 | 0;
	i++;
	if (i == 8)
	{
		if (ascii == '\0')
			kill(pid, SIGUSR1);
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
