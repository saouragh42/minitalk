/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:30:49 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 21:05:00 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/* Global variable for signal acknowledgment */
int	g_received = 0;

/**
 * Signal handler for client acknowledgment.
 * SIGUSR1: Normal acknowledgment (bit received)
 */
static void	handle_acknowledgment(int sig)
{
	if (sig == SIGUSR1)
		g_received = 1;
}

/*
** Sends each bit of the character 'c' to the process with the given 'pid'
** using UNIX signals. For each bit, if the bit is 1, sends SIGUSR1; if 0,
** sends SIGUSR2. The line 'if (c & (1 << bit_index))' checks if the bit at
** position 'bit_index' is set (using a bitwise AND). 
** Now waits for acknowledgment from server before sending next bit.
** Returns 1 on success, 0 on failure.
*/
static int	send_signal(int pid, unsigned char c)
{
	int	bit_index;
	int	sig;
	int	timeout;

	bit_index = 0;
	while (bit_index < 8)
	{
		if (c & (1 << bit_index))
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		if (kill(pid, sig) == -1)
			return (0);
		timeout = 0;
		while (g_received == 0 && timeout < 1000)
		{
			usleep(1000);
			timeout++;
		}
		if (g_received == 0)
			return (0);
		g_received = 0;
		bit_index++;
	}
	return (1);
}

static int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*message;

	if (argc != 3)
		return (ft_printf("Error\nUse: ./client <server_pid> <message>\n"), 1);
	if (!ft_strisdigit(argv[1]))
		return (ft_printf("Error\nInvalid PID: %s\n", argv[1]), 1);
	pid = ft_atoi(argv[1]);
	if (pid <= 1)
		return (ft_printf("Error\nInvalid PID: %d\n", pid), 1);
	if (kill(pid, 0) == -1)
		return (ft_printf("Error\nNo process with PID: %d\n", pid), 1);
	signal(SIGUSR1, handle_acknowledgment);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		if (!send_signal(pid, (unsigned char)message[i++]))
			return (ft_printf("Error\nFailed to send signal or timeout\n"), 1);
	}
	if (!send_signal(pid, '\0'))
		return (ft_printf("Error\nFailed to send null terminator\n"), 1);
	ft_printf("Message sent successfully to server with PID %d\n", pid);
	return (0);
}
