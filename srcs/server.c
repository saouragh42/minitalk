/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:30:57 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 21:14:52 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/**
 * Signal handler that reconstructs a character from bits sent via SIGUSR1 and
 * SIGUSR2. Each time a signal is received, if it is SIGUSR1, the corresponding
 * bit in the character 'c' is set using bitwise OR.
 * The line 'c |= (1 << bit_index);' sets the bit at position 'bit_index' in 'c'
 * to 1, allowing the character to be built one bit at a time.
 * The bit_index is incremented after each signal. 
 * When 8 bits have been received, the completed character is printed, and both
 * 'c' and bit_index are reset to receive the next character.
 * After each received bit, sends an acknowledgment signal back to the client
 * using the PID obtained from siginfo_t to ensure reliable transmission.
 */
static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int				bit_index;
	static unsigned char	c;

	(void)context;
	if (bit_index == 0)
		c = 0;
	if (sig == SIGUSR1)
		c |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		bit_index = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
	{
		ft_printf("Error\nUse ./server\n");
		return (1);
	}
	(void)argv;
	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Waiting for messages...\n");
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, 0) == -1 || sigaction(SIGUSR2, &sa, 0) == -1)
		return (ft_printf("Error sigaction\n"), 1);
	while (1)
	{
		pause();
	}
	return (0);
}
