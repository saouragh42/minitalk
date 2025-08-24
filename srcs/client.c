/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:30:49 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 16:58:10 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
/*
* Sends each bit of the character 'c' to the process (server) with the given
* 'pid' using UNIX signals. 
* For each bit, if the bit is 1, sends SIGUSR1;
* if 0, sends SIGUSR2. 
* The line 'if (c & (1 << bit_index))' checks if the bit
* at position 'bit_index' is set (using a bitwise AND). A short delay is added
* after each signal to allow the server to process it.
*/
void	send_signal(int pid, char c)
{
	int	bit_index;

	bit_index = 0;
	while (bit_index < 8)
	{
		if (c & (1 << bit_index))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_index++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Error\nUse: ./client <server_pid> <message>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error\nInvalid PID\n");
		return (1);
	}
	i = 0;
	message = argv[2];
	while (message[i])
	{
		send_signal(pid, message[i]);
		i++;
	}
	send_signal(pid, '\0');
	ft_printf("Message sent to server with PID %d: %s\n", pid, message);
	return (0);
}
