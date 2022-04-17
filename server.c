/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:26:03 by aball             #+#    #+#             */
/*   Updated: 2022/04/18 00:32:32 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int x, int y)
{
	int	pow;

	pow = x;
	if (y == 0)
		return (1);
	y--;
	while (y)
	{
		pow *= x;
		y--;
	}
	return (pow);
}

void	sighandler_1(int signum, siginfo_t *info, void *context)
{
	static int	c;
	static int	i;

	(void)context;
	if (signum == SIGUSR1)
		i++;
	if (signum == SIGUSR2)
	{
		c += power(2, i);
		i++;
	}
	if (i > 6)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	usleep(SLEEP);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	s1;

	s1.sa_flags = SA_SIGINFO;
	sigemptyset(&s1.sa_mask);
	s1.sa_sigaction = &sighandler_1;
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &s1, NULL);
	sigaction(SIGUSR2, &s1, NULL);
	while (1)
		pause();
}
