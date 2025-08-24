/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:30:57 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/24 17:30:31 by saouragh         ###   ########.fr       */
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
 * When 8 bits have been received,
 * the completed character is printed, and both 'c' and bit_index are reset to
 * receive the next character.
 */
void	handle_signal(int sig)
{
	static int	bit_index;
	static char	c;

	if (bit_index == 0)
		c = 0;
	if (sig == SIGUSR1)
		c |= (1 << bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("Received character by server: %c\n", c);
		c = 0;
		bit_index = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 1)
	{
		ft_printf("Error\nUse ./server\n");
		return (1);
	}
	(void)argv;
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Waiting for messages...\n");

	while (1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
	return (0);
}
