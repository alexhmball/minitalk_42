/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:26:05 by aball             #+#    #+#             */
/*   Updated: 2022/04/24 03:08:26 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_binary[7];

void	send_signal(int pid, int signum)
{
	static int	i;

	usleep(SLEEP);
	if (signum == SIGUSR2)
		exit (0);
	if (g_binary[i] == 0)
	{
		i++;
		if (kill(pid, SIGUSR1) == -1)
			exit (1);
	}
	else if (g_binary[i] == 1)
	{
		i++;
		if (kill(pid, SIGUSR2) == -1)
			exit (1);
	}
	if (i > 6)
	{
		i = 0;
		ft_memset(g_binary, 0, 7 * 4);
	}
}

void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	send_signal(info->si_pid, signum);
}

void	convert_to_binary(int c)
{
	int	i;

	i = 0;
	while (c)
	{
		if (c % 2 == 0)
			g_binary[i] = 0;
		else
			g_binary[i] = 1;
		c /= 2;
		i++;
	}
}

void	waiting(char **av, int c, int i)
{
	while (av[2][i])
	{
		c++;
		if (c > 6)
		{
			i++;
			c = 0;
		}
		convert_to_binary(av[2][i]);
		pause();
	}
	while (1)
		pause();
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					i;
	int					c;

	i = 0;
	c = 0;
	if (ac != 3)
		return (0);
	if (!ft_isdigit(av[1][0]))
	{
		ft_printf("wrong pid");
		exit (1);
	}
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &sighandler;
	convert_to_binary(av[2][i]);
	send_signal(ft_atoi(av[1]), 0);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	waiting(av, c, i);
	return (0);
}
