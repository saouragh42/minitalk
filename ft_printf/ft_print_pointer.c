/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouragh <saouragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:02:20 by saouragh          #+#    #+#             */
/*   Updated: 2025/08/06 01:41:03 by saouragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_print_ptr(ptr / 16);
		ft_print_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_print_char((ptr + '0'));
		else
			ft_print_char((ptr - 10 + 'a'));
	}
}

size_t	ft_ptrlen(uintptr_t ptr)
{
	size_t	count;

	count = 0;
	if (ptr <= 0)
		count++;
	while (ptr)
	{
		count++;
		ptr /= 16;
	}
	return (count);
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	count;
	int	r;

	if (ptr == 0)
	{
		r = write(1, "(nil)", 5);
		if (r == -1)
			return (-1);
		return (5);
	}
	r = write(1, "0x", 2);
	if (r == -1)
		return (-1);
	count = r;
	ft_print_ptr(ptr);
	count += ft_ptrlen(ptr);
	return (count);
}
