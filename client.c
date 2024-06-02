/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaafkhar <kaafkhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:59:59 by kaafkhar          #+#    #+#             */
/*   Updated: 2024/06/02 11:39:08 by kaafkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"


static void envoie_bits(int PID, char c)
{
    static int bit;

    while (bit < 8)
    {
        if ((c & 1) == 1)
            kill(PID, SIGUSR1);
        else 
            kill(PID, SIGUSR2);
        usleep(700);
        bit++;
        c = c >> 1;
    }
    if (bit == 8)
        bit = 0;
}

int main (int ac, char **av)
{
    int PID;
    int i;
    char c;

    i = 0;
    if (ac != 3)
    {
        write (1, "erreur", 6);
        exit (1);
    }
    PID = ft_atoi(av[1]);
    if (PID < 0)
    {
        write (1, "impossible", 11);
        exit (1);
    }
    while (av[2][i])
    {
        envoie_bits(PID, av[2][i]);
        i++;
    }
}