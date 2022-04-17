/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:26:05 by aball             #+#    #+#             */
/*   Updated: 2022/04/18 00:35:19 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_client	g_nums;

void	send_signal(int pid)
{
	if (g_nums.num[g_nums.c] == 0 && g_nums.str[g_nums.index])
	{
		g_nums.c++;
		usleep(SLEEP);
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("wrong pid");
			free (g_nums.str);
			exit (1);
		}
	}
	else if (g_nums.num[g_nums.c] == 1 && g_nums.str[g_nums.index])
	{
		g_nums.c++;
		usleep(SLEEP);
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("wrong pid");
			free (g_nums.str);
			exit (1);
		}
	}
	if (g_nums.c > 6)
	{
		g_nums.c = 0;
		ft_memset(g_nums.num, 0, 7 * 4);
		g_nums.index++;
	}
}

void	sighandler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		send_signal(info->si_pid);
}

void	convert_to_binary(int c)
{
	int	i;

	i = 0;
	while (c)
	{
		if (c % 2 == 0)
			g_nums.num[i] = 0;
		else
			g_nums.num[i] = 1;
		c /= 2;
		i++;
	}
}


int	main(int ac, char **av)
{
	struct sigaction	sa;

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
	g_nums.index = 0;
	g_nums.c = 0;
	g_nums.str = ft_strdup(av[2]);
	convert_to_binary(av[2][g_nums.index]);
	send_signal(ft_atoi(av[1]));
	sigaction(SIGUSR1, &sa, NULL);
	while (av[2][g_nums.index])
	{
		convert_to_binary(av[2][g_nums.index]);
		pause();
	}
	free(g_nums.str);
	return (0);
}
