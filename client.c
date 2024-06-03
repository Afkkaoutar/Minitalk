/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:59:59 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/02 21:52:24 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

static	void	envoie_bits(int pid, char c)
{
	static int	count_bit;

	while (count_bit < 8)
	{
		if ((c & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		count_bit++;
		c = c >> 1;
	}
	if (count_bit == 8)
		count_bit = 0;
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	c;

	i = 0;
	if (ac != 3)
	{
		write (1, "error : bad arg", 16);
		exit (1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 0)
	{
		write (1, "error : bad pid", 16);
		exit (1);
	}
	while (av[2][i])
	{
		envoie_bits(pid, av[2][i]);
		i++;
	}
}
