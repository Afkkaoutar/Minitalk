/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:02:13 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/02 21:56:34 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	handel_signal(int signum, siginfo_t *info, void *extra)
{
	char		stock;
	static int	pid;
	static int	count;
	static int	oper;

	(void)extra;
	if (pid != info->si_pid)
	{
		stock = '\0';
		count = 0;
		pid = info->si_pid;
	}
	if (signum == SIGUSR1)
	{
		oper = 1 << count;
		stock = stock | oper;
	}
	count++;
	if (count == 8)
	{
		ft_putchar(stock);
		count = 0;
		stock = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	action.sa_sigaction = &handel_signal;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
