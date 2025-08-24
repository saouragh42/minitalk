/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:01:09 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/08 13:58:56 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	int	r;

	r = write(1, &c, 1);
	if (r == -1)
		return (-1);
	return (1);
}

size_t	ft_strlen_printf(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_string(char *str)
{
	int	r;

	if (!str)
		str = "(null)";
	r = write(1, str, ft_strlen_printf(str));
	if (r == -1)
		return (-1);
	return (ft_strlen_printf(str));
}
